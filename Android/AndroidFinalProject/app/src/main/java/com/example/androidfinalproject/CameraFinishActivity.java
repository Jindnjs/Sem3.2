package com.example.androidfinalproject;

import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.content.Context;  // Context 사용을 위한 임포트

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.viewpager.widget.ViewPager;

import com.github.mikephil.charting.animation.Easing;
import com.github.mikephil.charting.charts.PieChart;
import com.github.mikephil.charting.data.PieData;
import com.github.mikephil.charting.data.PieDataSet;
import com.github.mikephil.charting.data.PieEntry;
import com.github.mikephil.charting.utils.ColorTemplate;

import java.util.ArrayList;

public class CameraFinishActivity extends AppCompatActivity {
    Button btn;
    PieChart pieChart;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_camera_finish);

        pieChart = findViewById(R.id.pie_chart);
        pieChart.setUsePercentValues(true);


//        DBHelper dbHelper = new DBHelper(context);
//        String exampleData = "Hello, Database!";
//        dbHelper.insertData("exampleKey", exampleData.getBytes());
//        Log.d("DB", "Data saved successfully!");
        //목표불러오기

        DBHelper dbHelper = new DBHelper(this);
        byte[] data = dbHelper.getData("1");
        String retrievedData = new String(data);
        String news = "01:00:00";

        String[] timeParts = news.split(":");

        if (timeParts.length != 3) {
            Log.e("CameraFinishActivity", "Invalid time format: " + retrievedData);
            // 기본값으로 설정하거나 예외 처리
            timeParts = new String[]{"0", "0", "0"};
        }
        int hours = Integer.parseInt(timeParts[0]);
        int minutes = Integer.parseInt(timeParts[1]);
        int seconds = Integer.parseInt(timeParts[2]);
        int total_sec = hours * 3600 + minutes * 60 + seconds;

        //학습시간 불러오기
        //목표 나누기 학습시간

        Intent intent = getIntent();
        TextView text = (TextView) findViewById(R.id.timerTextView);
        text.setText(intent.getStringExtra("time"));

        String studyTime = intent.getStringExtra("time");
        String[] timeParts2 = studyTime.split(":");

        minutes = Integer.parseInt(timeParts2[0]);
        seconds = Integer.parseInt(timeParts2[1]);
        int total_sec2 = minutes * 60 + seconds;

        ArrayList<PieEntry> entries = new ArrayList<>();
        entries.add(new PieEntry(total_sec));
        entries.add(new PieEntry(total_sec2));

        // 다양한 색상 추가
        ArrayList<Integer> colorsItems = new ArrayList<>();
        for (int c : ColorTemplate.VORDIPLOM_COLORS) colorsItems.add(c);
        for (int c : ColorTemplate.JOYFUL_COLORS) colorsItems.add(c);
        for (int c : ColorTemplate.COLORFUL_COLORS) colorsItems.add(c);
        for (int c : ColorTemplate.LIBERTY_COLORS) colorsItems.add(c);
        for (int c : ColorTemplate.PASTEL_COLORS) colorsItems.add(c);
        colorsItems.add(ColorTemplate.getHoloBlue());

        PieDataSet pieDataSet = new PieDataSet(entries, "");
        pieDataSet.setColors(colorsItems);
        pieDataSet.setValueTextColor(Color.BLACK);
        pieDataSet.setValueTextSize(0f);

        PieData pieData = new PieData(pieDataSet);
        pieChart.setData(pieData);
        pieChart.getDescription().setEnabled(false);
        pieChart.setRotationEnabled(false);
        float percentage = (float) total_sec2 / total_sec * 100;
        pieChart.setCenterText(String.format("%.2f", percentage) + "%");
        pieChart.setEntryLabelColor(Color.BLACK);
        pieChart.setCenterTextSize(20f);
        pieChart.animateY(1400, Easing.EaseInOutQuad);

        Log.d("CameraFinishActivity", "Total time: " + total_sec + ", Study time: " + total_sec2);
        btn = (Button) findViewById(R.id.btnFinishS);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();

            }
        });
    }
}