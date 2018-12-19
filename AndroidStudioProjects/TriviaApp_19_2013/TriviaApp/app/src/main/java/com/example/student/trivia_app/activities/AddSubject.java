package com.example.student.trivia_app.activities;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.example.student.trivia_app.R;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class AddSubject extends AppCompatActivity {
    EditText editText;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_subject);
        editText = findViewById(R.id.editText_subject_name);
    }

    public void add_subject(View view){
        String str = editText.getText().toString();
        FirebaseDatabase mDatabase =FirebaseDatabase.getInstance();
        DatabaseReference dbRootRef =mDatabase.getReference("/subjects");
        dbRootRef.child(str).setValue(str);
        Toast.makeText(getApplicationContext(),"added subject: "+ str,Toast.LENGTH_SHORT).show();
    }
}
