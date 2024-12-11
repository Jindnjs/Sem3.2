package com.example.androidfinalproject;

public class StudyData {

    private String date;
    private int totalStudyTime; // 학습 시간(분)
    private String startTime;
    private String endTime;
    private int[] subjectTimes = new int[4]; // 과목별 학습시간 (과목1, 과목2, 과목3, 과목4)
    private int[] hourlyStudyTimes = new int[24]; // 시간대별 공부시간 (0~23시)

    // 기본 생성자
    public StudyData() {
    }

    // 파라미터를 받는 생성자
    public StudyData(String date, int totalStudyTime, String startTime, String endTime, int[] subjectTimes, int[] hourlyStudyTimes) {
        this.date = date;
        this.totalStudyTime = totalStudyTime;
        this.startTime = startTime;
        this.endTime = endTime;
        this.subjectTimes = subjectTimes;
        this.hourlyStudyTimes = hourlyStudyTimes;
    }

    // Getter 및 Setter

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public int getTotalStudyTime() {
        return totalStudyTime;
    }

    public void setTotalStudyTime(int totalStudyTime) {
        this.totalStudyTime = totalStudyTime;
    }

    public String getStartTime() {
        return startTime;
    }

    public void setStartTime(String startTime) {
        this.startTime = startTime;
    }

    public String getEndTime() {
        return endTime;
    }

    public void setEndTime(String endTime) {
        this.endTime = endTime;
    }

    public int[] getSubjectTimes() {
        return subjectTimes;
    }

    public void setSubjectTimes(int[] subjectTimes) {
        this.subjectTimes = subjectTimes;
    }

    public int[] getHourlyStudyTimes() {
        return hourlyStudyTimes;
    }

    public void setHourlyStudyTimes(int[] hourlyStudyTimes) {
        this.hourlyStudyTimes = hourlyStudyTimes;
    }
}