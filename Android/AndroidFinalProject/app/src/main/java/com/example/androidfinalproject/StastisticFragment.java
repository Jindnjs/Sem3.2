package com.example.androidfinalproject;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.DatePicker;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.TextView;
import java.util.Calendar;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.github.mikephil.charting.charts.BarChart;
import com.github.mikephil.charting.charts.PieChart;
import com.github.mikephil.charting.data.BarData;
import com.github.mikephil.charting.data.BarDataSet;
import com.github.mikephil.charting.data.BarEntry;
import com.github.mikephil.charting.data.PieData;
import com.github.mikephil.charting.data.PieDataSet;
import com.github.mikephil.charting.data.PieEntry;
import com.github.mikephil.charting.formatter.IndexAxisValueFormatter;
import com.github.mikephil.charting.utils.ColorTemplate;

import java.util.ArrayList;
import java.util.Random;

public class StastisticFragment extends Fragment {

    private DatePicker datePicker;
    private TextView studyTimeText, startEndText;
    private PieChart pieChart;
    private BarChart barChart;
    private RadioGroup dateRangeRadioGroup;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_stastistic, container, false);

        datePicker = view.findViewById(R.id.datePicker);
        studyTimeText = view.findViewById(R.id.studyTimeText);
        startEndText = view.findViewById(R.id.startEndText);
        pieChart = view.findViewById(R.id.pieChart);
        barChart = view.findViewById(R.id.barChart);
        dateRangeRadioGroup = view.findViewById(R.id.dateRangeRadioGroup);

        dateRangeRadioGroup.setOnCheckedChangeListener((group, checkedId) -> {
            String selectedDate = getSelectedDate();
            StudyData data = null;

            try {
                if (checkedId == R.id.radioDay) {
                    data = generateRandomStudyData(selectedDate);
                } else if (checkedId == R.id.radioWeek) {
                    data = generateRandomStudyDataForWeek(selectedDate);
                } else if (checkedId == R.id.radioMonth) {
                    data = generateRandomStudyDataForMonth(selectedDate);
                } else {
                    data = generateRandomStudyData(selectedDate);
                }
            } catch (Exception e) {
                e.printStackTrace();  // 예외 발생 시 로그를 출력
                // 예외 처리 로직 추가 (예: 기본 데이터로 설정)
                data = generateRandomStudyData(selectedDate);
            }

            // UI 업데이트
            if (data != null) {
                studyTimeText.setText("공부시간: " + data.getTotalStudyTime() + " 분");
                startEndText.setText("시작시간: " + data.getStartTime() + " | 종료시간: " + data.getEndTime());
                setPieChart(data.getSubjectTimes());
                setBarChart(data.getHourlyStudyTimes());
            }
        });

        // Default action for the datePicker when the fragment is loaded
        datePicker.init(datePicker.getYear(), datePicker.getMonth(), datePicker.getDayOfMonth(),
                (view1, year, monthOfYear, dayOfMonth) -> {
                    String selectedDate = year + "-" + (monthOfYear + 1) + "-" + dayOfMonth;
                    StudyData data = generateRandomStudyData(selectedDate);
                    studyTimeText.setText("공부시간: " + data.getTotalStudyTime() + " 분");
                    startEndText.setText("시작시간: " + data.getStartTime() + " | 종료시간: " + data.getEndTime());
                    setPieChart(data.getSubjectTimes());
                    setBarChart(data.getHourlyStudyTimes());
                });

        return view;
    }

    private String getSelectedDate() {
        int year = datePicker.getYear();
        int month = datePicker.getMonth() + 1;
        int day = datePicker.getDayOfMonth();
        return year + "-" + month + "-" + day;
    }

    private StudyData generateRandomStudyData(String date) {
        Random random = new Random();
        StudyData data = new StudyData();
        data.setDate(date);
        data.setTotalStudyTime(random.nextInt(480) + 60);
        data.setStartTime("09:00");
        data.setEndTime("17:00");

        for (int i = 0; i < 4; i++) {
            data.getSubjectTimes()[i] = random.nextInt(120) + 30;
        }

        for (int i = 0; i < 24; i++) {
            data.getHourlyStudyTimes()[i] = random.nextInt(30);
        }

        return data;
    }

    private StudyData generateRandomStudyDataForWeek(String startDate) {
        Random random = new Random();
        StudyData data = new StudyData();
        data.setDate(startDate);
        data.setTotalStudyTime(random.nextInt(2400) + 420);  // Total for a week (7 days)
        data.setStartTime("07:00");
        data.setEndTime("21:00");
        for (int i = 0; i < 4; i++) {
            data.getSubjectTimes()[i] = random.nextInt(600) + 150;  // Weekly subject time
        }

        for (int i = 0; i < 7; i++) {
            data.getHourlyStudyTimes()[i] = random.nextInt(180);  // Weekly study hours per day
        }

        return data;
    }

    private StudyData generateRandomStudyDataForMonth(String startDate) {
        Random random = new Random();
        StudyData data = new StudyData();
        data.setDate(startDate);
        data.setTotalStudyTime(random.nextInt(7200) + 1800);  // Total for a month (30 days)
        data.setStartTime("11:00");
        data.setEndTime("19:00");
        for (int i = 0; i < 4; i++) {
            data.getSubjectTimes()[i] = random.nextInt(1800) + 300;  // Monthly subject time
        }

        for (int i = 0; i < 30; i++) {
            data.getHourlyStudyTimes()[i] = random.nextInt(240);  // Monthly study hours per day
        }

        return data;
    }

    private void setPieChart(int[] subjectTimes) {
        ArrayList<PieEntry> entries = new ArrayList<>();
        for (int i = 0; i < subjectTimes.length; i++) {
            entries.add(new PieEntry(subjectTimes[i], "과목 " + (i + 1)));
        }

        PieDataSet dataSet = new PieDataSet(entries, "~");
        ArrayList<Integer> colorsItems = new ArrayList<>();
        colorsItems.add(Color.parseColor("#FF5733"));
        colorsItems.add(Color.parseColor("#FFC300"));
        colorsItems.add(Color.parseColor("#DAF7A6"));
        colorsItems.add(Color.parseColor("#900C3F"));
        colorsItems.add(Color.parseColor("#581845"));
        colorsItems.add(Color.parseColor("#FF8C00"));
        colorsItems.add(Color.parseColor("#32CD32"));
        colorsItems.add(Color.parseColor("#1E90FF"));
        colorsItems.add(Color.parseColor("#FFD700"));
        colorsItems.add(ColorTemplate.getHoloBlue());

        dataSet.setColors(colorsItems);
        PieData data = new PieData(dataSet);
        pieChart.setData(data);
        pieChart.setBackgroundColor(Color.WHITE);
        pieChart.invalidate();
    }

    private void setBarChart(int[] hourlyStudyTimes) {
        ArrayList<BarEntry> entries = new ArrayList<>();
        for (int i = 0; i < hourlyStudyTimes.length; i++) {
            entries.add(new BarEntry(i, hourlyStudyTimes[i]));
        }

        BarDataSet barDataSet = new BarDataSet(entries, "시간대별 공부시간");
        barDataSet.setColor(Color.BLUE);
        BarData data = new BarData(barDataSet);
        barChart.setData(data);

        barChart.getXAxis().setLabelCount(12);
        barChart.getXAxis().setValueFormatter(new IndexAxisValueFormatter(getHours()));
        barChart.getAxisLeft().setGranularity(1f);
        barChart.invalidate();
    }

    private String[] getHours() {
        String[] hours = new String[24];
        for (int i = 0; i < 24; i++) {
            hours[i] = i + ":00";
        }
        return hours;
    }
}