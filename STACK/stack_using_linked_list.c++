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

class Stack{
    node *top;
    
    public:
       Stack(){
        top=NULL;
       }

       void push(int val){
           node *newnode=new node(val);
           if(top==NULL){
              top=newnode;
              return;
           }
           newnode->next=top;
           top=newnode;
       }

       int pop(){
           if(top==NULL){
            cout<<"stack is empty"<<endl;
            return 0;
           }
           int val=top->data;
           node *temp=top;
           top=top->next;
           temp->next=NULL;
           delete temp;
           return val;
       }

       int stack_top(){
           return top->data;
       }

       void print_stack(){
           node *temp=top;
           while(temp!=NULL){
              cout<<temp->data<<" ";
              temp=temp->next;
           }
           cout<<endl;
       }

       bool isempty(){
          return top==NULL;
       }
       
};

int main(){
    Stack s; 
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    cout<<s.stack_top()<<endl;
    s.print_stack();
    cout<<"deleted value:"<<s.pop()<<endl;
    cout<<s.stack_top()<<endl;
    s.print_stack();
    cout<<"deleted value:"<<s.pop()<<endl;
    s.print_stack();
    cout<<"deleted value:"<<s.pop()<<endl;
    cout<<"deleted value:"<<s.pop()<<endl;
    cout<<"deleted value:"<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isempty();

}
