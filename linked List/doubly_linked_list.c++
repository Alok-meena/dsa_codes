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
    if(pos<1){
        cout<<"invalid position"<<endl;
        return;
    }
    
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

        if(curr==NULL){
            cout<<"invalid position"<<endl;
            return;
        }

        //and check this curr==NULL before that curr->next below o/w it will give unexpected results okkk

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

void deleteAtPos(node* &head,node* &tail,int pos){
    if(pos==1){
        node *temp=head;
        //ye imp hai okk prev bhi to start node ka null hota hai na
        head=head->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else{
        
        node *forward=head->next;
        node *curr=head;
        int count=1;
        while(count<pos-1){
            curr=curr->next;
            forward=forward->next;
            count++;
        }
        if(forward->next==NULL){
            curr->next=forward->next;
            tail=curr;
        }
        else{
            curr->next=forward->next;
            forward->next->prev=curr;
        }
        forward->next=NULL;
        forward->prev=NULL;
        delete forward;
    }
}

this is also correct and easy one alright

void deletepos(node* &head,node* &tail,int pos){
    if(pos==1){
        node *temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    node *p=head;
    node *curr=head->next;

    int count=1;
    while(count<pos-1){
        p=p->next;
        curr=curr->next;
        count++;
    }


    if(curr->next==NULL){
        p->next=NULL;
        curr->prev=NULL;
        tail=p;
        delete curr;
        return;
    }

    p->next=curr->next;
    curr->next->prev=p;
    curr->next=NULL;
    curr->prev=NULL;
    delete curr;
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
