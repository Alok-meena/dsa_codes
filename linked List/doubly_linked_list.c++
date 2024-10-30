#include <bits/stdc++.h>
using namespace std;

class node{
    public:
      int data;
      node *next;
      node *prev;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }

    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data:"<<value<<endl;
    }
    
};

void insertAtHead(node* &head,node* &tail,int data){
    if(head==NULL){
        node *temp=new node(data);
        head=temp;
        tail=temp;
    }
    else{
        node *temp=new node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insertAtTail(node* &tail,node* &head,int data){
    if(tail==NULL){
        node *temp=new node(data);
        tail=temp;
        head=temp;
    }
    else{
        node *temp=new node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insertAtPos(node* &head,node* &tail,int data,int pos){
    if(pos==1){
        insertAtHead(head,tail,data);
        return;
    }
    else{
        node *current=head;
        int count=1;
        while(count<pos-1){
            current=current->next;
            count++;
        }

        //inserting at the end with data d and using pointer tail

        if(current->next==NULL){
            insertAtTail(tail,head,data);
            return;
        }
        
        node *temp=new node(data);
        temp->next=current->next;
        current->next->prev=temp;
        current->next=temp;
        temp->prev=current;
    }
}

int getlength(node* &head){
    int len=0;
    node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

void print(node* &head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main(){
    node *head=NULL;
    node *tail=NULL;
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,10);
    insertAtTail(tail,head,50);
    insertAtPos(head,tail,100,4);
    print(head);
    cout<<endl<<getlength(head);
    cout<<endl<<"head:"<<head->data<<" "<<"tail:"<<tail->data;
}
