#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;

        node(int data){
            this->data=data;
            this->next=NULL;
        }
};

class Queue{    
    int size;
    node *front;
    node *rear;
    
    public:
       Queue(){
        size=0;
        front=NULL;
        rear=NULL;
       }

       void push(int val){
           size++;
           node *newnode=new node(val);
           if(rear==NULL and front==NULL){
              rear=newnode;
              front=newnode;
              return;
           }
        
           rear->next=newnode;
           rear=newnode;
       }

       int pop(){
           if(front==NULL and rear==NULL){
            cout<<"queue is empty"<<endl;
            return -1;
           }

           size--;

           int val=front->data;
           node *temp=front;
           front=front->next;
           temp->next=NULL;
           delete temp;

           if(front==NULL) rear=NULL;
           
           return val;
       }

       int front_val(){
           if(front!=NULL) return front->data;
           cout<<"queue is empty"<<endl;
           return -1;
       }

       int back_val(){
           if(rear!=NULL) return rear->data;
           cout<<"queue is empty"<<endl;
           return -1;
       }

       void print_queue(){
           node *temp=front;
           while(temp!=NULL){
              cout<<temp->data<<" ";
              temp=temp->next;
           }
           cout<<endl;
       }

       bool isempty(){
          return front==NULL and rear==NULL;
       }

       int size_of_queue(){
          return size;
       }
       
};

int main(){
    Queue s; 
    s.push(1);
    s.push(2);
    s.push(3);
    s.print_queue();
    cout<<s.back_val()<<endl;
    cout<<s.size_of_queue()<<endl;
    cout<<"deleted value:"<<s.pop()<<endl;
    cout<<s.back_val()<<endl;
    cout<<s.front_val()<<endl;
    cout<<"deleted value:"<<s.pop()<<endl;
    cout<<s.back_val()<<endl;
    cout<<"delete value:"<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.size_of_queue()<<endl;
    cout<<s.back_val();

}
