package com.example.report2;

import android.app.TabActivity;
import android.os.Bundle;
import android.widget.TabHost;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

@SuppressWarnings("deprecatinon")
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TabHost tabHost = findViewById(android.R.id.tabhost);
        tabHost.setup();

        TabHost.TabSpec tabCat = tabHost.newTabSpec("CAT").setIndicator("고양이");
        tabCat.setContent(R.id.imgCat);
        tabHost.addTab(tabCat);

        TabHost.TabSpec tabDog = tabHost.newTabSpec("DOG").setIndicator("강아지");
        tabDog.setContent(R.id.imgDog);
        tabHost.addTab(tabDog);

        TabHost.TabSpec tabHorse = tabHost.newTabSpec("HORSE").setIndicator("말");
        tabHorse.setContent(R.id.imgHorse);
        tabHost.addTab(tabHorse);

        TabHost.TabSpec tabRabbit = tabHost.newTabSpec("RABBIT").setIndicator("토끼");
        tabRabbit.setContent(R.id.imgRabbit);
        tabHost.addTab(tabRabbit);

        tabHost.setCurrentTab(0);
    }
}