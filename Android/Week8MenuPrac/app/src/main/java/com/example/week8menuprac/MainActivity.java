package com.example.week8menuprac;

import android.graphics.Color;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    LinearLayout baseLayout;
    Button button1, button2, button3;

    int button1rot =0;
    int button3rot=0;
    int button1s =0;
    int button3s=0;
    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);

        MenuInflater min = getMenuInflater();
        if(v == button2){
            menu.setHeaderTitle("배경색 변경");
            min.inflate(R.menu.menu2, menu);
        }
        if(v == button3)
            min.inflate(R.menu.menu3, menu);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
//        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.baseLayout), (v, insets) -> {
//            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
//            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
//            return insets;
//        });
        getSupportActionBar().setDisplayShowHomeEnabled(true);
        setTitle("배경색 바꾸기 + 컨텍스트 메뉴");
        baseLayout = (LinearLayout) findViewById(R.id.baseLayout);
        button1 = (Button) findViewById(R.id.button1);

        button2 = (Button) findViewById(R.id.button2);
        registerForContextMenu(button2);
        button3 = (Button) findViewById(R.id.button3);
        registerForContextMenu(button3);
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        MenuInflater mInflater = getMenuInflater();
        mInflater.inflate(R.menu.menu1, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.itemRed) {
            baseLayout.setBackgroundColor(Color.RED);
            return true;
        } else if (id == R.id.itemGreen) {
            baseLayout.setBackgroundColor(Color.GREEN);
            return true;
        } else if (id == R.id.itemBlue) {
            baseLayout.setBackgroundColor(Color.BLUE);
            return true;
        } else if (id == R.id.subRotate) {
            button1rot += 45;
            button1.setRotation(button1rot);
            return true;
        } else if (id == R.id.subSize) {
            button1s += 2;
            button1.setScaleX(button1s);
            return true;
        }

        return false;
    }

    @Override
    public boolean onContextItemSelected(@NonNull MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.itemRed) {
            baseLayout.setBackgroundColor(Color.RED);
            return true;
        } else if (id == R.id.itemGreen) {
            baseLayout.setBackgroundColor(Color.GREEN);
            return true;
        } else if (id == R.id.itemBlue) {
            baseLayout.setBackgroundColor(Color.BLUE);
            return true;
        } else if (id == R.id.subRotate) {
            button3rot += 45;
            button3.setRotation(button3rot);
            return true;
        } else if (id == R.id.subSize) {
            button3s +=2;
            button3.setScaleX(button3s);
            return true;
        }

        return false;
    }

}