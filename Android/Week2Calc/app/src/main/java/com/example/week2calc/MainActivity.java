package com.example.week2calc;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    EditText text1, text2;
    Button btnAdd, btnSub, btnMul, btnDiv, btnMod;
    TextView textResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        text1 = findViewById(R.id.editText1);
        text2 = findViewById(R.id.editText2);
        textResult = findViewById(R.id.TextResult);

        btnAdd = findViewById(R.id.btnAdd);
        btnSub = findViewById(R.id.btnSub);
        btnMul = findViewById(R.id.btnMul);
        btnDiv = findViewById(R.id.btnDiv);
        btnMod = findViewById(R.id.btnMod);

        btnAdd.setOnClickListener(view -> performOperation(Operation.ADD));
        btnSub.setOnClickListener(view -> performOperation(Operation.SUB));
        btnMul.setOnClickListener(view -> performOperation(Operation.MUL));
        btnDiv.setOnClickListener(view -> performOperation(Operation.DIV));
        btnMod.setOnClickListener(view -> performOperation(Operation.MOD));
    }

    private void performOperation(Operation operation) {
        String input1 = text1.getText().toString();
        String input2 = text2.getText().toString();

        if (!checkValid(input1, input2)) {
            Toast.makeText(getApplicationContext(), "숫자가 입력되지 않았습니다.", Toast.LENGTH_SHORT).show();
            return;
        }

        try {
            Number n1 = parseNumber(input1);
            Number n2 = parseNumber(input2);

            String result = calculate(n1, n2, operation);
            textResult.setText("계산 결과 : " + result);

        } catch (IllegalArgumentException e) {
            Toast.makeText(MainActivity.this, "유효한 숫자가 아닙니다", Toast.LENGTH_SHORT).show();
        }
    }

    public static Number parseNumber(String input) {
        try {
            return Integer.parseInt(input);
        } catch (NumberFormatException e1) {
            try {
                return Double.parseDouble(input);
            } catch (NumberFormatException e2) {
                throw new IllegalArgumentException();
            }
        }
    }

    private String calculate(Number n1, Number n2, Operation operation) {

        //정수
        if (n1 instanceof Integer && n2 instanceof Integer) {
            int int1 = (Integer) n1;
            int int2 = (Integer) n2;

            switch (operation) {
                case ADD:
                    return String.valueOf(int1 + int2);
                case SUB:
                    return String.valueOf(int1 - int2);
                case MUL:
                    return String.valueOf(int1 * int2);
                case DIV:
                    if(int2 == 0){
                        Toast.makeText(MainActivity.this, "0으로 나눌수 없습니다", Toast.LENGTH_SHORT).show();
                        return "";
                    }
                    return String.valueOf((double) int1 / int2); // 정수 나눗셈은 실수로 반환
                case MOD:
                    return String.valueOf(int1 % int2);
            }
        }

        //실수
        double double1 = n1.doubleValue();
        double double2 = n2.doubleValue();

        switch (operation) {
            case ADD:
                return String.valueOf(double1 + double2);
            case SUB:
                return String.valueOf(double1 - double2);
            case MUL:
                return String.valueOf(double1 * double2);
            case DIV:
                if(double2 == 0){
                    Toast.makeText(MainActivity.this, "0으로 나눌수 없습니다", Toast.LENGTH_SHORT).show();
                    return "";
                }
                return String.valueOf(double1 / double2);
            case MOD:
                return String.valueOf(double1 % double2);
        }

        return "오류";
    }

    public static boolean checkValid(String one, String two) {
        return !one.isEmpty() && !two.isEmpty();
    }

    private enum Operation {
        ADD, SUB, MUL, DIV, MOD
    }
}