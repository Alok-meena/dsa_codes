
//encapsulation file
#include <bits/stdc++.h>
using namespace std;

class Game {
public:
   int lives;
   string name;
   int age;

   void print_age(int age);
   void print_name(string name);
   void print_lives(int lives);
};

//hiding this implementation means ABSTRACTION

#include <bits/stdc++.h>
#include <D:\revision\add.h>
using namespace std;

void Game:: print_name(string name){
    this->name=name;
    cout<<this->name<<endl;
}

void Game:: print_age(int age){
    this->age=age;
    cout<<this->age<<endl;
}

void Game:: print_lives(int lives){
    this->lives=lives;
    cout<<this->lives<<endl;
}


//user side view by importing files

#include <iostream>
#include <D:\revision\k.c++>
using namespace std;


int main(){
     Game g1;
    g1.print_name("Player1");
    g1.print_age(25);
    g1.print_lives(3);


    return 0;
}

