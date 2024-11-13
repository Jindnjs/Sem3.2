package com.example.week11prac3;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioGroup;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends Activity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final EditText edtNum1 = (EditText) findViewById(R.id.edtNum1);
        final EditText edtNum2 = (EditText) findViewById(R.id.edtNum2);
        final RadioGroup rdoGroup = (RadioGroup) findViewById(R.id.rdoGroup);

        Button btnNewActivity = (Button) findViewById(R.id.btnNewActivity);
        btnNewActivity.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(),
                        SecondActivity.class);

                int checkedRadioButtonId = rdoGroup.getCheckedRadioButtonId();
                if (checkedRadioButtonId == R.id.rdoAdd) {
                    intent.putExtra("operate", "+");
                }
                else if (checkedRadioButtonId == R.id.rdoSub) {
                    intent.putExtra("operate", "-");
                }
                else if (checkedRadioButtonId == R.id.rdoMul) {
                    intent.putExtra("operate", "*");
                }
                else if (checkedRadioButtonId == R.id.rdoDiv) {
                    intent.putExtra("operate", "/");
                }

                intent.putExtra("Num1",
                        Integer.parseInt(edtNum1.getText().toString()));
                intent.putExtra("Num2",
                        Integer.parseInt(edtNum2.getText().toString()));

                startActivityForResult(intent, 0);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

        if (resultCode == RESULT_OK) {
            int hap = data.getIntExtra("Res", 0);
            Toast.makeText(getApplicationContext(), "결과:" + hap,
                    Toast.LENGTH_SHORT).show();
        }
    }

}
