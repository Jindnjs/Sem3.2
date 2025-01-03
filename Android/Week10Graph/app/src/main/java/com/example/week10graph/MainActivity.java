package com.example.week10graph;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.SubMenu;
import android.view.View;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    final static int LINE = 1, CIRCLE = 2, RECT = 3;
    static int curShape = LINE;
    final static int RED = 1, GREEN = 2, BLUE = 3;
    static int curColor = RED;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new MyGraphicView(this));
        getSupportActionBar().setDisplayShowHomeEnabled(true);
        setTitle("간단 그림판");

    }
    public boolean onCreateOptionsMenu(Menu menu){
        super.onCreateOptionsMenu(menu);
        menu.add(0,1,0,"선 그리기");
        menu.add(0,2,0,"원 그리기");
        menu.add(0,3,0,"사각형 그리기");

        SubMenu sMenu = menu.addSubMenu("색상 변경 >>");
        sMenu.add(0,4,0,"빨강");
        sMenu.add(0,5,0,"초록");
        sMenu.add(0,6,0,"파랑");

        return true;
    }
    public boolean onOptionsItemSelected(MenuItem item){
        switch (item.getItemId()){
            case 1:
                curShape = LINE;
                return true;
            case 2:
                curShape = CIRCLE;
                return true;
            case 3:
                curShape = RECT;
                return true;
            case 4:
                curColor = RED;
                return true;
            case 5:
                curColor = GREEN;
                return true;
            case 6:
                curColor = BLUE;
                return true;
        }
        return super.onOptionsItemSelected(item);
    }
    private static class MyGraphicView extends View {
        int startX = -1, startY = -1, stopX = -1, stopY = -1;
        public MyGraphicView(Context context){
            super(context);
        }

        @Override
        public boolean onTouchEvent(MotionEvent event) {
            switch (event.getAction()){
                case MotionEvent.ACTION_DOWN:
                    startX = (int) event.getX();
                    startY = (int) event.getY();
                    break;
                case MotionEvent.ACTION_MOVE:
                case MotionEvent.ACTION_UP:
                    stopX = (int) event.getX();
                    stopY = (int) event.getY();
                    this.invalidate();
                    break;
            }
            return true;
        }

        @Override
        protected void onDraw(@NonNull Canvas canvas) {
            super.onDraw(canvas);
            Paint paint = new Paint();
            paint.setAntiAlias(true);
            paint.setStrokeWidth(5);
            paint.setStyle(Paint.Style.STROKE);

            switch(curColor){
                case RED:
                    paint.setColor(Color.RED);
                    break;
                case GREEN:
                    paint.setColor(Color.GREEN);
                    break;
                case BLUE:
                    paint.setColor(Color.BLUE);
                    break;
            }
            switch (curShape){
                case LINE:
                    canvas.drawLine(startX, startY, stopX, stopY, paint);
                    break;
                case CIRCLE:
                    int radius = (int) Math.sqrt(Math.pow(stopX-startX,2) + Math.pow(stopY - startY,2));
                    canvas.drawCircle(startX,startY,radius,paint);
                    break;
                case RECT:
                    canvas.drawRect(startX, startY, stopX, stopY, paint);
                    break;
            }
        }
    }
}