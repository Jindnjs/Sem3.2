package com.example.myapplication

import android.app.Application
import androidx.camera.lifecycle.ProcessCameraProvider
import androidx.core.content.ContextCompat
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import java.util.concurrent.ExecutionException

class CameraXViewModel(application: Application) : AndroidViewModel(application){

    private val cameraProviderLiveData: MutableLiveData<ProcessCameraProvider> = MutableLiveData()
    val processCameraProvider: LiveData<ProcessCameraProvider>
        get(){
            val cameraProvderFuture = ProcessCameraProvider.getInstance(getApplication())
            cameraProvderFuture.addListener(
                {
                    try{
                        cameraProviderLiveData.setValue(cameraProvderFuture.get())
                    }catch (e: ExecutionException){
                        e.printStackTrace()
                    }catch (e:InterruptedException){
                        e.printStackTrace()
                    }
                },
                ContextCompat.getMainExecutor(getApplication())
            )
            return cameraProviderLiveData
        }
}