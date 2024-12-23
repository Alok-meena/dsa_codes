#include <bits/stdc++.h>
using namespace std;

class student{
    string name;
    int age;
    vector<int>marks;
    
    public:

    void print_name(){
        cout<<name<<endl;
    }

    void print_age(){ 
        cout<<age<<endl;
    }
    
    void print_marks();
    
    void set_name(string n){
        name=n;
    }

    student(){
        cout<<"constructor called"<<endl;
        name="dj";
        age=0;
    }

    student(string a,int m){
        cout<<"parametrized constructor is called"<<endl;
        name=a;
        marks.push_back(m);
    }
};

void student::print_marks(){
    for(auto i:marks){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    student s1("aman",96);
    s1.print_name();
    s1.print_marks();
    student s2;
    s2.print_name();
    s2.print_age();


    return 0;
}

like this diff objects have their diff memory so if you will try to modify the class members by other 
object then also the other objects values remain unchanged as all objects have their own memory


we can also call multiple parametrized constructor based on the passed parameters

#include <bits/stdc++.h>
using namespace std;

class student{
    string name;
    int age;
    vector<int>marks;
    
    public:

    void print_name(){
        cout<<name<<endl;
    }

    void print_age(){ 
        cout<<age<<endl;
    }
    
    void print_marks();
    
    void set_name(string n){
        name=n;
    }

    student(){
        cout<<"default constructor called"<<endl;
        name="dj";
        age=0;
    }

    student(string a,int m){
        cout<<"parametrized constructor is called"<<endl;
        name=a;
        marks.push_back(m);
    }

    student(string a){
        cout<<"parametrized constructor2 is called"<<endl;
        name=a;
    }

    student(student &obj){
        cout<<"copy constructor called"<<endl;
        name=obj.name;
        age=obj.age;
    }
};

void student::print_marks(){
    for(auto i:marks){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    student s1("aman");
    s1.print_name();
    s1.print_marks();
    student s2;
    s2.print_name();
    s2.print_age();
    student s3;
    s3.print_name();
    s3.print_age();


    return 0;
}


and we should pass the object in copy constructor by reference okkk


Why Is Passing the Copy Constructor by Reference Necessary?
When defining a copy constructor, passing the object by reference (instead of by value) is absolutely necessary. Here's why:

1. Avoid Infinite Recursion
If the copy constructor takes the object by value, a new object would need to be created to pass it to the constructor. This triggers the copy constructor again, leading to infinite recursion.

For example:

cpp
Copy code
student(student obj) { // Passed by value
    name = obj.name;   // Infinite recursion here
    age = obj.age;
}
When student obj is passed by value:

The copy constructor itself is called to copy obj.
This creates another call to the same constructor, and so on.
The program will crash due to a stack overflow. 

for shallow copy we should have to use pointers okk 

#include <bits/stdc++.h>
using namespace std;

class student{
    string *name;
    int age;
    vector<int> marks;

public:
    void print_name(){
        cout << *name << endl;
    }

    void print_age(){
        cout << age << endl;
    }

    void print_marks();

    void set_name(string n){
        *name = n;
    }

    student(){
        cout << "default constructor called" << endl;
        name = new string;  // Dynamically allocate memory for name
    }

    student(student &obj){
        cout << "copy constructor called" << endl;
        name = obj.name;  // Shallow copy the pointer
    }

    ~student(){
        delete name;  // Free dynamically allocated memory
    }
};

void student::print_marks(){
    for (auto i : marks) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    student s1;
    s1.set_name("alok");
    student s2 = s1; // or can do s2(s1);
    s2.set_name("aman");
    s1.print_name();  // Outputs "aman"
    s2.print_name();  // Outputs "aman"

    return 0;
}

so here the name is defined as pointer so for shallow copy do use pointer 

we can access the private part within the class and in other classes and in main function
using getter and setter okk

#include <bits/stdc++.h>
using namespace std;

class animal{
    
    int legs;
    string color;

    public:
    
    void set_legs(int leg){
        legs=leg;
    }

    void set_color(string s){
        color=s;
    }

    void print_legs(){
        cout<<"legs of animal is:"<<legs<<endl;
    }

    void print_color(){
        cout<<"color of animal is:"<<color<<endl;
    }
};

class dog: public animal{
    public:
     void print(){
        cout<<"about the animal dog:"<<endl;
        print_legs();
        print_color();
     }
};

int main(){

    //and here no need to declare animal object as all of the members of animal 
    //are accessible by the dog class okk 
    dog d1;
    d1.set_color("black");
    d1.set_legs(4);
    d1.print();


    return 0;
}
