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
        cout<<"destructor is called..."<<endl;
        cout<<"deleted value is:"<<this->data<<endl;
    }
};


void insertathead(node* &head,int value){
    if(head==NULL){
        node *newnode=new node(value);
        newnode->next=newnode;
        newnode->prev=newnode;
        head=newnode;
    }
    else{
        node *newnode=new node(value);
        newnode->next=head;
        newnode->prev=head->prev;
        head->prev->next=newnode;
        head->prev=newnode;
        head=newnode;
    }
}

void insertafter_ele(node* &head,int value,int element){
    if(head==NULL){
        insertathead(head,value);
    }
    else{
        node *temp=head;
        while(temp->data!=element){
            temp=temp->next;
            if(temp==head){
                cout<<"value does not exist in list"<<endl;
                return;
            }
        }

        node *newnode=new node(value);
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void deletevalue(node* &head,int value){
    if(head==NULL){
        cout<<"list is empty , cant delete";
        return;
    }
    else{
        node *p=head;
        node *curr=head->next;

        while(curr->data!=value){
            if(p==head){
                cout<<"value does not exist"<<endl;
                return;
            }
            p=curr;
            curr=curr->next;
        }

        if(curr==p){
            head=NULL;
        }
        else if(curr==head){
            head=p;
        }

        p->next=curr->next;
        curr->next->prev=p;
        curr->next=NULL;
        curr->prev=NULL;
        delete curr;
    }
}

void print(node* &head){
    if(head==NULL){
        cout<<"list is empty";
        return;
    }
    node *temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
}





int main(){
    node *head=NULL;
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    print(head);
    cout<<endl;
    cout<<head->data<<endl;
    deletevalue(head,10);
    // insertafter_ele(head,4,1);
    cout<<endl;
    print(head);
    cout<<endl;
    cout<<head->data;
}
