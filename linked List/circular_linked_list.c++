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

//we will give the element such that after that element we have to insert the data in the linked list
void insertNode(node* &tail,int element,int data){

    //empty list
    if(tail==NULL){
        node *temp=new node(data);
        tail=temp;
        temp->next=temp;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list
        node *curr=tail;
        while(curr->data!=element){
            curr=curr->next;
            if (curr == tail) {
                cout << "Element " << element << " not found in the list." << endl;
                return;
            }
        }
        
        //noew element is founded  -> curr is representing element wala node
        node *temp=new node(data);
        temp->next=curr->next;
        curr->next=temp;
    }
}



//here we need to pass tail by reference because if we delete the node (in single node case)
//and set tail to null then also in main() tail is pointing to the deleted node only 
//which will cause errors
void deleteNode(node* &tail,int value){
    if(tail==NULL){
        cout<<"linked list is empty plz check again!"<<endl;
        return;
    }
    else{
        node *prev=tail;
        node *curr=tail->next;
        while(curr->data!=value){
            if(curr==tail){
                cout<<"value does not exist in the list";
                return;
            }
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;

        //it is very imp here we firstly have to check condition for single node alright curr==prev this one 
        //if we check curr==tail first then it is true in case of single node also and will not do tail=null which result in error alright
        if(curr==prev){
            tail=NULL;
        }
        else if(tail==curr){
            tail=prev; //does not matter ki kis ele ko point krvaye because circular list hai alright
        }
        curr->next=NULL;
        delete curr;
    }
}

this deletion code is correct but cannot handle if the data is equal to head node and duplicate values are also present alright

like 5->1->2->3->5->5->head  in this case wrong 5 will be deleted alright

Node* deleteNode(Node* head, int key) {
        
        // code here
        Node *prev=head;
        Node *curr=head->next;
        
        if(head->data==key){
            Node *temp=head->next;
            while(temp->next!=head){
                temp=temp->next;
            }
            
            Node *d=head;
            
            temp->next=head->next;
            head=d->next;
            
            d->next=NULL;
            delete d;
            return head;
        }
        while(curr->data!=key){
            if(curr==head) return head;
            prev=curr;
            curr=curr->next;
        }
        
        prev->next=curr->next;
        
        if(curr==prev){
            head=NULL;
        }
        else if(curr==head){
            head=prev;
        }
        
        curr->next=NULL;
        delete curr;
        
        return head;
    }

Node* reverse(Node* head) {
        // code here
        Node *prev=head;
        Node *curr=head->next;
        
        
        while(curr!=head){
            Node *forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        curr->next=prev;
        
        return prev;
    }

void print(node *tail){
    if(tail==NULL){
        cout<<"list is empty";
        return;
    }
    node *temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=tail);
}


int main(){
    node *tail=NULL;
    insertNode(tail,2,1);
    insertNode(tail,1,2);
    insertNode(tail,2,3);
    insertNode(tail,3,4);
    insertNode(tail,4,5);

    print(tail);
    cout<<endl;
    deleteNode(tail,1);
    print(tail);
}
