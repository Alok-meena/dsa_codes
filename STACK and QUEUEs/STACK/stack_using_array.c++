#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;

    //constructor
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int val){
        if(top<size-1){
            top++;
            arr[top]=val;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            cout<<arr[top]<<" value is popped of the stack"<<endl;
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }

    int top_value(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isempty(){
        if(top==-1){
            return true;
        }
        return false;
    }

    ~Stack(){
        delete[] arr;
        cout<<"stack destructor is called"<<endl;
    }
};

int main(){
    
    Stack s(2);
    // s.push(5);
    // s.push(4);
    // s.pop();
    // s.pop();
    // s.pop();
    // s.push(4);
    cout<<s.top_value()<<endl;
    cout<<s.isempty()<<endl;

}
