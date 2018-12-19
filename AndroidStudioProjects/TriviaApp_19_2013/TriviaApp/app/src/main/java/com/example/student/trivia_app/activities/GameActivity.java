package com.example.student.trivia_app.activities;

import com.example.student.trivia_app.model.User;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

import com.example.student.trivia_app.R;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.HashMap;
import java.util.Map;

public class GameActivity extends AppCompatActivity {
    RadioGroup radioGroup;
    RadioButton radioButton;
    final String[] correctAnswer = new String[1];
    final String[] id = new String[1];
    final String[] user_score = new String[1];
    String user_email;
    FirebaseAuth mAuth;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


        Intent intent = getIntent();
        id[0] = intent.getStringExtra("question_id");

        FirebaseAuth mAuth = FirebaseAuth.getInstance();
        user_email = mAuth.getCurrentUser().getEmail().replace(".", "|");
        Toast.makeText(getApplicationContext(),"question "+id[0] , Toast.LENGTH_SHORT).show();
        radioGroup = findViewById(R.id.radioGroup);
        final RadioButton radioButton1 = findViewById(R.id.radioButton1);
        final RadioButton radioButton2 = findViewById(R.id.radioButton2);
        final RadioButton radioButton3 = findViewById(R.id.radioButton3);
        final RadioButton radioButton4 = findViewById(R.id.radioButton4);
        final TextView question_tv = findViewById(R.id.question_tv);
        //Radio Buttons
        FirebaseDatabase mDatabase = FirebaseDatabase.getInstance();
//        DatabaseReference dbRef =mDatabase.getReference("/questions");
        DatabaseReference dbRef =mDatabase.getReference();
//        DatabaseReference dbRef =mDatabase.getReference("/questions" + id);

        //Read from database
        //constantly checks for changes
        dbRef.addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                user_score[0] = dataSnapshot.child("users/"+user_email).child("score").getValue().toString();
                dataSnapshot = dataSnapshot.child("questions").child(id[0].toString());
//                for (DataSnapshot ds : dataSnapshot.getChildren()){
                    correctAnswer[0] = dataSnapshot.child("rightAnswer").getValue().toString();
                    radioButton1.setText(dataSnapshot.child("answer1").getValue().toString());
                    radioButton2.setText(dataSnapshot.child("answer2").getValue().toString());
                    radioButton3.setText(dataSnapshot.child("answer3").getValue().toString());
                    radioButton4.setText(dataSnapshot.child("answer4").getValue().toString());
                    question_tv.setText(dataSnapshot.child("question").getValue().toString());

//                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });

    }



    public void submit_answer(View view){
        int radioId = radioGroup.getCheckedRadioButtonId();
        radioButton = findViewById(radioId);

//        DatabaseReference dbRef_users =mDatabase.getReference("/users");



        if (correctAnswer[0].equals(radioButton.getText())){
//            Toast.makeText(getApplicationContext(),"Correct!",Toast.LENGTH_SHORT).show();
            FirebaseDatabase mDatabase = FirebaseDatabase.getInstance();
            final DatabaseReference dbRef =mDatabase.getReference("/users/"+user_email);

            dbRef.addValueEventListener(new ValueEventListener() {
                @Override
                public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                    User user= dataSnapshot.getValue(User.class);
                    /*user.getQuestions_answered().put("question "+id ,score);*/


                    if(user.getQuestions_answered()==null || !user.getQuestions_answered().containsKey("question "+id[0])) {
                        dbRef.child("questions_answered").child("question " + id[0]).setValue(100);
                        final int score = Integer.parseInt(user_score[0]) + 100;
                        dbRef.child("score").setValue(score);
                        Toast.makeText(getApplicationContext(),"Added================================================ to DB!",Toast.LENGTH_SHORT).show();

                    }else {
                        Toast.makeText(getApplicationContext(), "not Added to DB!", Toast.LENGTH_SHORT).show();
                    }

                }

                @Override
                public void onCancelled(@NonNull DatabaseError databaseError) {

                }
            });



        }
        else
            Toast.makeText(getApplicationContext(),"Loser!",Toast.LENGTH_SHORT).show();

    }

}