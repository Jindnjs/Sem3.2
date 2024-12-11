package com.example.androidfinalproject;

import android.content.Intent;
import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.viewpager.widget.ViewPager;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

public class StudyFragment extends Fragment {

    Button btnStudyStart;


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_study, container, false);

        btnStudyStart = (Button) view.findViewById(R.id.btnStudyStart);
        btnStudyStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ViewPager viewPager = getActivity().findViewById(R.id.viewPager);
                if (viewPager != null) {
                    viewPager.setCurrentItem(1);
                }
                Intent intent = new Intent(getActivity(), CameraActivity.class);
                startActivity(intent);
            }
        });
        return view;
    }
}