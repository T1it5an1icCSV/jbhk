package com.example.android3;

import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

public class MainActivity2 extends AppCompatActivity {
    private boolean isDarkMode = true;
    private static final String PREFS_NAME = "AppPrefs";
    private static final String KEY_DARK_MODE = "dark_mode";
    private int clickCount = 0;
    private TextView clickCountTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);


        SharedPreferences sharedPreferences = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);
        isDarkMode = sharedPreferences.getBoolean(KEY_DARK_MODE, true);

        ConstraintLayout layout = findViewById(R.id.main);
        ImageButton imageButton = findViewById(R.id.imageButtonId);
        ImageButton notCoinButton = findViewById(R.id.imageButtonId2);
        clickCountTextView = findViewById(R.id.clickCountTextView);


        if (isDarkMode) {
            layout.setBackgroundColor(Color.DKGRAY);
        } else {
            layout.setBackgroundColor(Color.WHITE);
        }


        imageButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (isDarkMode) {
                    layout.setBackgroundColor(Color.WHITE);
                } else {
                    layout.setBackgroundColor(Color.GRAY);
                }
                isDarkMode = !isDarkMode;

                SharedPreferences.Editor editor = sharedPreferences.edit();
                editor.putBoolean(KEY_DARK_MODE, isDarkMode);
                editor.apply();
            }
        });


        notCoinButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                clickCount++;
                clickCountTextView.setText("Clicks: " + clickCount);
            }
        });
    }
}
