package com.example.student.trivia_app.activities;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import com.example.student.trivia_app.R;
import com.example.student.trivia_app.model.Question;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;
import java.util.List;

public class QuestionsActivity extends AppCompatActivity {
    String permissions;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Intent intent = getIntent();
        permissions = intent.getStringExtra("permissions");

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_questions);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        //print the catergory id
        String id = intent.getStringExtra("category_item");
//        user_hash = intent.getStringExtra("user_hash");
        Toast.makeText(getApplicationContext(),id , Toast.LENGTH_SHORT).show();

        final LinearLayout question_gallery = findViewById(R.id.gallery_questions);
        final LayoutInflater inflater = LayoutInflater.from(this);

        FirebaseDatabase mDatabase = FirebaseDatabase.getInstance();
        DatabaseReference dbRefQuestions =mDatabase.getReference("/questions");
        DatabaseReference dbRefSubject = mDatabase.getReference("/subjects/" + id + "/questions");


        //TODO Moshe will add this
        dbRefSubject.addValueEventListener(new ValueEventListener() {
                @Override
                public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                    for (DataSnapshot ds : dataSnapshot.getChildren()){
                        int i = 1;
                        View view = inflater.inflate(R.layout.question_item, question_gallery, false);

                        TextView question_details_tv = view.findViewById(R.id.question_details);
                        TextView question_level_tv = view.findViewById(R.id.question_level);

                        if (permissions.equals("true")) {
                            question_details_tv.setText(ds.getValue().toString());
                            question_level_tv.setText("Question: " + i++ );

                        } else {
                            question_details_tv.setText("Question: " + i++ );
                            question_level_tv.setText("");
                        }
                        question_details_tv.setTag(ds.getKey().toString());

                        view.setTag(ds.getKey().toString());
                        question_gallery.addView(view);
                    }

                }

                @Override
                public void onCancelled(@NonNull DatabaseError databaseError) {

                }
            });


//        //Read from database
//        //constantly checks for changes
//
//        final ArrayList<String> idQuestions = new ArrayList<>();
//
//        dbRefSubject.addValueEventListener(new ValueEventListener() {
//            @Override
//            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
//                for (DataSnapshot ds : dataSnapshot.getChildren()) {
//                    idQuestions.add(ds.getKey().toString());
//                }
//            }
//
//            @Override
//            public void onCancelled(@NonNull DatabaseError databaseError) {
//
//            }
//        });
//
//        Toast.makeText(getApplicationContext(),idQuestions.size() + "" , Toast.LENGTH_SHORT).show();

//        dbRefQuestions.addValueEventListener(new ValueEventListener() {
//            @Override
//            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
//                for (DataSnapshot ds : dataSnapshot.getChildren()){
//                    View view = inflater.inflate(R.layout.question_item, question_gallery, false);
//
//                    TextView question_details_tv = view.findViewById(R.id.question_details);
//                    question_details_tv.setText(ds.child("question").getValue().toString());
//                    question_details_tv.setTag(ds.getKey().toString());
//
//                    TextView question_level_tv = view.findViewById(R.id.question_level);
//                    question_level_tv.setText(ds.child("level").getValue().toString());
//
//                    String temp = ds.getKey().toString();
//                    view.setTag(ds.getKey().toString());
//                    question_gallery.addView(view);
//                }
//
//            }
//
//            @Override
//            public void onCancelled(@NonNull DatabaseError databaseError) {
//
//            }
//        });

    }

    public void questionSelect(View view){
//        Toast.makeText(getApplicationContext(),"hello" , Toast.LENGTH_SHORT).show();
        //TODO setTag doesnt work always null
        String question_id = view.getTag().toString();
        Toast.makeText(getApplicationContext(),question_id , Toast.LENGTH_SHORT).show();
//        System.out.println(question_id);
//
        Intent intent = new Intent(QuestionsActivity.this, GameActivity.class);
        //will send the category_item to other activity
        intent.putExtra("question_id", question_id);
//        intent.putExtra("user_hash",user_hash);
//
        startActivity(intent);
    }

}
