package com.example.androidfinalproject;

import android.os.Bundle;
import androidx.fragment.app.Fragment;
import androidx.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class SettingFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // 'fragment_page1.xml' 레이아웃을 사용하여 페이지 1 구성
        return inflater.inflate(R.layout.fragment_setting, container, false);
    }
}