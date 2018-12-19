package com.example.student.trivia_app.activities;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import com.example.student.trivia_app.R;
import com.example.student.trivia_app.model.Category;
import com.example.student.trivia_app.model.User;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.ChildEventListener;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;
import java.util.List;

public class CategoriesActivity extends AppCompatActivity {
    String permissions;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Intent intent = getIntent();
        permissions = intent.getStringExtra("permissions");

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_category);
        final LinearLayout gallery = findViewById(R.id.gallery);

        final LayoutInflater inflater = LayoutInflater.from(this);

        //TODO del

        System.out.println("##########################################");
        System.out.println(FirebaseAuth.getInstance().getCurrentUser().getEmail());
        FirebaseDatabase mDatabase = FirebaseDatabase.getInstance();
        DatabaseReference dbRef =mDatabase.getReference("/subjects");

        //Read from database
        //constantly checks for changes
        dbRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                for (DataSnapshot ds : dataSnapshot.getChildren()){
                    View view = inflater.inflate(R.layout.category_item, gallery, false);

                    TextView textView = view.findViewById(R.id.textView);
                    textView.setText(ds.getKey());

                    ImageView imageView = view.findViewById(R.id.imageView);
                    imageView.setImageResource(R.drawable.python_logo);

                    view.setTag(ds.getKey());
                    gallery.addView(view);
                    view.setBackgroundColor(Color.parseColor("#fffe77"));
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });
    }

    public void categorySelect(View view){
        String string = view.getTag().toString();

//        Toast.makeText(getApplicationContext(),string , Toast.LENGTH_LONG).show();
        System.out.println(string);
        Intent intent = new Intent(CategoriesActivity.this, QuestionsActivity.class);
        //will send the category_item to other activity
        intent.putExtra("category_item", string);
        intent.putExtra("permissions", permissions);

        startActivity(intent);
    }

}
