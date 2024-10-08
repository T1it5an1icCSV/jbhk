package com.example.android3;

import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

public class MainActivity3 extends AppCompatActivity {

    private boolean isDarkMode = true;
    private static final String PREFS_NAME = "AppPrefs";
    private static final String KEY_DARK_MODE = "dark_mode";
    private Button[] buttons = new Button[9];
    private boolean isXTurn = true;
    private int[][] winningCombinations = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);


        SharedPreferences sharedPreferences = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);
        isDarkMode = sharedPreferences.getBoolean(KEY_DARK_MODE, true);
        ConstraintLayout layout = findViewById(R.id.main);


        setLayoutBackgroundColor(layout);

        ImageButton imageButton = findViewById(R.id.imageButtonId);
        imageButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                isDarkMode = !isDarkMode;
                setLayoutBackgroundColor(layout);

                SharedPreferences.Editor editor = sharedPreferences.edit();
                editor.putBoolean(KEY_DARK_MODE, isDarkMode);
                editor.apply();
            }
        });


        for (int i = 0; i < buttons.length; i++) {
            String buttonID = "button_" + i;
            int resID = getResources().getIdentifier(buttonID, "id", getPackageName());
            buttons[i] = findViewById(resID);

            final int index = i;
            buttons[i].setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    handleButtonClick(buttons[index]);
                }
            });
        }
    }

    private void setLayoutBackgroundColor(ConstraintLayout layout) {
        if (isDarkMode) {
            layout.setBackgroundColor(Color.GRAY);
        } else {
            layout.setBackgroundColor(Color.WHITE);
        }
    }

    private void handleButtonClick(Button button) {
        if (button.getText().toString().equals("")) {
            button.setText(isXTurn ? "X" : "O");
            if (checkWinner()) {
                String winner = isXTurn ? "X" : "O";
                Toast.makeText(this, winner + " Победитель", Toast.LENGTH_SHORT).show();
                resetBoard();
            } else if (isBoardFull()) {
                Toast.makeText(this, "Ничья", Toast.LENGTH_SHORT).show();
                resetBoard();
            }
            isXTurn = !isXTurn;
        }
    }

    private boolean checkWinner() {
        for (int[] combination : winningCombinations) {
            String b1 = buttons[combination[0]].getText().toString();
            String b2 = buttons[combination[1]].getText().toString();
            String b3 = buttons[combination[2]].getText().toString();


            if (!b1.equals("") && b1.equals(b2) && b2.equals(b3)) {
                return true;
            }
        }
        return false;
    }

    private boolean isBoardFull() {
        for (Button button : buttons) {
            if (button.getText().toString().equals("")) {
                return false;
            }
        }
        return true;
    }

    private void resetBoard() {
        for (Button button : buttons) {
            button.setText("");
        }
        isXTurn = true;
    }
}
