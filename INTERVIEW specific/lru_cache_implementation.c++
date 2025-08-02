#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int key,value;
    node *prev;
    node *next;

    node(int key,int value){
        this->key=key;
        this->value=value;
        this->prev=NULL;
        this->next=NULL;
    }
};

class LRUcache{
    public:
    int capacity;
    node *head;
    node *tail;
    unordered_map<int,node*>mapp;

    LRUcache(int capacity){
        this->capacity=capacity;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void deletion(node* &temp){
        node *nextnode=temp->next;
        node *prevnode=temp->prev;

        if(nextnode) nextnode->prev=prevnode;
        if(prevnode) prevnode->next=nextnode;
    }

    void insertafterHead(node* &newnode){
        node *nextnode=head->next;

        head->next=newnode;
        newnode->prev=head;

        newnode->next=nextnode;
        nextnode->prev=newnode;
    }

    int get(int key){
        if(mapp.find(key)==mapp.end()) return -1;

        node *temp=mapp[key];
        deletion(temp);
        insertafterHead(temp);
        return temp->value;
    }

    void put(int key,int value){
        //ye to tab hai jab key pahle se present hai then just remove that and put at top and update it's value alright
        if(mapp.find(key)!=mapp.end()){
            node *temp=mapp[key];
            temp->value=value;
            deletion(temp);
            insertafterHead(temp);
        }
        else{
            //if capacity full hai (yani sari frames allocate ho gyi hai)
            if(mapp.size()==capacity){
                node *temp=tail->prev;
                mapp.erase(temp->key);//map me se bhi to delete krna hai
                deletion(temp);
                delete temp;
            }

            node *newnode=new node(key,value);
            mapp[key]=newnode; //map me insert bhi to kroge 
            insertafterHead(newnode);
        }
    }

    void print(){
        node *temp=head->next;
        cout<<"(";
        while(temp!=tail){
            cout<<temp->key<<" "<<temp->value<<"),(";
            temp=temp->next;
        }
    }
};

int main(){
    LRUcache lru(3);
    lru.put(3,4);
    lru.put(10,2);
    lru.put(5,1);
    cout<<endl;
    lru.print();
    cout<<endl;
    lru.put(11,3);
    cout<<endl;
    lru.print();
    return 0;
}
