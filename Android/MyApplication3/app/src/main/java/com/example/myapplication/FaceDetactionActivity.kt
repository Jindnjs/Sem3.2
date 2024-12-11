package com.example.myapplication

import android.annotation.SuppressLint
import android.content.Context
import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.util.Size
import androidx.activity.enableEdgeToEdge
import androidx.activity.viewModels
import androidx.appcompat.app.AppCompatActivity
import androidx.camera.core.CameraSelector
import androidx.camera.core.ImageAnalysis
import androidx.camera.core.ImageProxy
import androidx.camera.core.Preview
import androidx.camera.lifecycle.ProcessCameraProvider
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.example.myapplication.ScannerActivity.Companion
import com.example.myapplication.databinding.ActivityFaceDetactionBinding
import com.google.common.util.concurrent.ListenableFuture
import com.google.mlkit.vision.barcode.BarcodeScanner
import com.google.mlkit.vision.barcode.BarcodeScannerOptions
import com.google.mlkit.vision.barcode.BarcodeScanning
import com.google.mlkit.vision.barcode.common.Barcode
import com.google.mlkit.vision.common.InputImage
import com.google.mlkit.vision.face.FaceDetection
import com.google.mlkit.vision.face.FaceDetector
import com.google.mlkit.vision.face.FaceDetectorOptions
import java.util.concurrent.Executors

class FaceDetactionActivity : AppCompatActivity() {

    private lateinit var binding: ActivityFaceDetactionBinding

    private lateinit var cameraSelector: CameraSelector
    private lateinit var processCameraProvider: ProcessCameraProvider
    private lateinit var cameraPreview: Preview
    private lateinit var imageAnalysis: ImageAnalysis

    private val cameraXViewModel = viewModels<CameraXViewModel>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityFaceDetactionBinding.inflate(layoutInflater)
        setContentView(binding.root)

        cameraSelector = CameraSelector.Builder().requireLensFacing(CameraSelector.LENS_FACING_BACK).build()

        cameraXViewModel.value.processCameraProvider.observe(this){provider ->
            processCameraProvider = provider
            bindCameraPreview()
            bindInputAnalyser()
        }

    }

    private fun bindCameraPreview(){
        cameraPreview = Preview.Builder()
            .setTargetRotation(binding.previewView.display.rotation)
            .build()

        cameraPreview.setSurfaceProvider(binding.previewView.surfaceProvider)
        try{
            processCameraProvider.bindToLifecycle(this,cameraSelector,cameraPreview)
        }catch (illegalStateException: IllegalStateException){
            Log.e(TAG, illegalStateException.message ?: "IllegalStateException")
        }catch (illegalArgumentException : IllegalArgumentException){
            Log.e(TAG, illegalArgumentException.message?:"IllegalArgumentException")
        }

    }

    private fun bindInputAnalyser(){

        val detector = FaceDetection.getClient(
            FaceDetectorOptions.Builder()
                .setContourMode(FaceDetectorOptions.CONTOUR_MODE_ALL)
                .build()
        )

        imageAnalysis = ImageAnalysis.Builder()
            .setTargetResolution(Size(1280, 720))
            .setBackpressureStrategy(ImageAnalysis.STRATEGY_KEEP_ONLY_LATEST) // 최신 이미지만 처리
            .build()

        val cameraExecutor = Executors.newSingleThreadExecutor()

        var lastProcessedTime: Long = 0
        val processingInterval: Long = 500  // 500ms 간격으로 처리

        imageAnalysis.setAnalyzer(cameraExecutor) { imageProxy ->
            val currentTime = System.currentTimeMillis()
            if (currentTime - lastProcessedTime >= processingInterval) {
                processImageProxy(detector, imageProxy)
                lastProcessedTime = currentTime
            } else {
                imageProxy.close() // 처리 간격이 지나지 않으면 처리 건너뜀
            }
        }
        try {
            processCameraProvider.bindToLifecycle(this, cameraSelector, imageAnalysis)
        }catch (illegalStateException: IllegalStateException){
            Log.e(TAG, illegalStateException.message ?: "IlligalStateException")
        }catch(illegalArgumentException : IllegalArgumentException){
            Log.e(TAG, illegalArgumentException.message ?: "IllegalArgumentException")
        }
    }

    @SuppressLint("UnsafeOptInUsageError")
    private fun processImageProxy(detector: FaceDetector, imageProxy: ImageProxy) {
        val mediaImage = imageProxy.image
        if (mediaImage != null) {
            val inputImage = InputImage.fromMediaImage(mediaImage, imageProxy.imageInfo.rotationDegrees)

            detector.process(inputImage)
                .addOnSuccessListener { faces ->
                    binding.faceBoxOverlay.clear()

                    if (faces.isNotEmpty()) {
                        faces.forEach { face ->
                            val box = FaceBox(binding.faceBoxOverlay, face, imageProxy.cropRect, isDetected = true)
                            binding.faceBoxOverlay.add(box)
                        }
                    } else {
                        // 얼굴이 감지되지 않은 경우 기본 박스 추가
                        val box = FaceBox(binding.faceBoxOverlay, null, null, isDetected = false)
                        binding.faceBoxOverlay.add(box)
                    }

                }
                .addOnFailureListener { e ->
                    Log.e(TAG, "Face detection failed: ${e.message}")
                }
                .addOnCompleteListener {
                    imageProxy.close()
                }
        } else {
            Log.e(TAG, "Image is null")
            imageProxy.close()
        }
    }

    companion object{
        private var TAG = FaceDetactionActivity::class.simpleName
        fun start(context: Context){
            Intent(context, FaceDetactionActivity::class.java).also{
                context.startActivity(it)
            }
        }
    }
}