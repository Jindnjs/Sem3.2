package com.example.androidfinalproject;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.activity.EdgeToEdge;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.camera.core.AspectRatio;
import androidx.camera.core.CameraSelector;
import androidx.camera.core.Preview;
import androidx.camera.lifecycle.ProcessCameraProvider;
import androidx.camera.view.PreviewView;
import androidx.core.app.ActivityCompat;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentTransaction;

import java.util.concurrent.ExecutionException;
import android.os.Handler;
import android.widget.TextView;

public class CameraActivity extends AppCompatActivity {

    private TextView timerTextView;
    PreviewView previewView;
    Button startButton;
    Button stopButton;
    Button btnFinishS;
    String TAG = "CameraActivity";
    ProcessCameraProvider processCameraProvider;
    int lensFacing = CameraSelector.LENS_FACING_BACK;

    private Handler handler = new Handler();
    private boolean isRunning = false;

    private boolean isGreenBorder = true; // 초록색 상태 여부
    private long realElapsedTime = 0; // 초록색 상태에서만 증가하는 타이머
    private long realStartTime = 0; // 초록색 상태에서 타이머 시작 시간
    private long lastUpdateTime = 0; // 마지막 업데이트 시간

    private static final int GREEN_DURATION = 10000; // 초록색 지속 시간 (10초)
    private static final int RED_DURATION = 5000;   // 빨간색 지속 시간 (5초)

    private Runnable timerRunnable = new Runnable() {
        @Override
        public void run() {
            if (isRunning) {
                long currentTime = System.currentTimeMillis();
                long cycleTime = (currentTime - lastUpdateTime) % (GREEN_DURATION + RED_DURATION);

                if (cycleTime < GREEN_DURATION) { // 초록색 상태
                    if (!isGreenBorder) {
                        isGreenBorder = true;
                        updateBorderColor(true);
                        realStartTime = currentTime - realElapsedTime; // 타이머 재동기화
                    }
                    realElapsedTime = currentTime - realStartTime; // 초록색 상태에서 타이머 갱신
                } else { // 빨간색 상태
                    if (isGreenBorder) {
                        isGreenBorder = false;
                        updateBorderColor(false);
                    }
                    // 빨간색 상태에서는 realElapsedTime을 유지
                }

                updateTimerUI(); // 타이머 UI 업데이트
                handler.postDelayed(this, 100); // 100ms마다 호출
            }
        }
    };

    private void updateBorderColor(boolean isGreen) {
        int color = isGreen ? getResources().getColor(android.R.color.holo_green_light)
                : getResources().getColor(android.R.color.holo_red_light);
        previewView.setBackgroundColor(color);
    }

    private void updateTimerUI() {
        int seconds = (int) (realElapsedTime / 1000);
        int minutes = seconds / 60;
        seconds %= 60;
        int milliseconds = (int) (realElapsedTime % 1000);

        timerTextView.setText(String.format("%02d:%02d:%03d", minutes, seconds, milliseconds));
    }

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camera);

        previewView = findViewById(R.id.previewView);

        timerTextView = findViewById(R.id.timerTextView);
        btnFinishS = findViewById(R.id.btnFinishS);

        ActivityCompat.requestPermissions(this, new String[]{android.Manifest.permission.CAMERA}, 1);

        try {
            processCameraProvider = ProcessCameraProvider.getInstance(this).get();
        } catch (ExecutionException | InterruptedException e) {
            e.printStackTrace();
        }




        btnFinishS.setOnClickListener(view -> {
            if (!isRunning) {
                if (ActivityCompat.checkSelfPermission(CameraActivity.this, android.Manifest.permission.CAMERA) == PackageManager.PERMISSION_GRANTED) {
                    bindPreview();
                }
                realStartTime = System.currentTimeMillis();
                lastUpdateTime = realStartTime;
                realElapsedTime = 0; // 초기화
                isRunning = true;
                handler.post(timerRunnable);
                updateBorderColor(true);
                this.btnFinishS.setText("학습종료");// 시작 시 초록색
            }else {
                processCameraProvider.unbindAll();
                isRunning = false;
                handler.removeCallbacks(timerRunnable);
                Intent intent = new Intent(CameraActivity.this, CameraFinishActivity.class);
                int seconds = (int) (realElapsedTime / 1000);
                int minutes = seconds / 60;
                seconds %= 60;
                int milliseconds = (int) (realElapsedTime % 1000);

                // 데이터 전달
                intent.putExtra("time", String.format("%02d:%02d:%03d", minutes, seconds, milliseconds));
                intent.putExtra("studyid", 1);
                intent.putExtra("second", seconds);
                startActivity(intent);
                finish();
            }
        });
    }

    void bindPreview() {
        previewView.setScaleType(PreviewView.ScaleType.FIT_CENTER);
        CameraSelector cameraSelector = new CameraSelector.Builder()
                .requireLensFacing(lensFacing)
                .build();
        Preview preview = new Preview.Builder()
                .setTargetAspectRatio(AspectRatio.RATIO_4_3) //디폴트 표준 비율
                .build();
        preview.setSurfaceProvider(previewView.getSurfaceProvider());

        processCameraProvider.bindToLifecycle(this, cameraSelector, preview);
    }


    @Override
    protected void onPause() {
        super.onPause();
        processCameraProvider.unbindAll();
    }
}