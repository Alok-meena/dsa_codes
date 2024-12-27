#include <bits/stdc++.h>
using namespace std;

class Queue{
    public:
        int *arr;
        int size;
        int front;
        int rear;
    
    Queue(int s){
        this->size=s;
        arr=new int[size];
        front=0;
        rear=0;
    }

    void push(int val){
        if(rear<size){
            arr[rear]=val;
            rear++;
        }
        else{
            cout<<"queue is full"<<endl;
        }
    }

    void pop(){
        if(front==rear){
            cout<<"queue is empty"<<endl;
            return;
        }
        front++;
        if(front==rear){
            front=0;
            rear=0;
        }
    }

    int front_val(){
        if(front!=rear) return arr[front];
        cout<<"queue is empty"<<endl;
        return -1;
    }

    int back_val(){
        if(front!=rear) return arr[rear-1];
        cout<<"queue is empty"<<endl;
        return -1;
    }

    bool isempty(){
        if(front==rear) return true;
        return false;
    }

    ~Queue(){
        delete[] arr;
        cout<<"destructor called"<<endl;
    }
};

int main(){
    Queue q(3);
    q.pop();
    // q.pop();
    // q.pop();

    cout<<q.isempty();
}
