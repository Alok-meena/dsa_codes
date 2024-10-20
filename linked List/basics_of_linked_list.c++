

#include <iostream>
using namespace std;

class node{
    public:
       int data;
       node *next;
    
    //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }

    //destructor
    ~node(){
        int val=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data:"<<val<<endl;
    }

   //to suno dhyan se jo ham delete forward kiya to ye khud memory deallocate kr dega forward ki ager iska next null hai but by chance aor noodes connected hai
//to unhe delete krne ke liye hamne yha if condition use ki hai o/w it is not required 
Exactly! You’ve got it now!

- **`delete forward;`** will delete the node `forward`. This is always enough to delete that specific node.
- The **if condition** in the destructor (`if (this->next != NULL)`) is there to handle the **recursive case**, where a node might have a `next` node that also needs to be deleted. If there is no `next` node (i.e., `next == NULL`), the deletion stops there.

So in summary:

- **For a single node deletion**: `delete forward;` is enough because that will free the memory of the node and call its destructor.
  
- **For recursive deletion**: The destructor checks if the current node has a `next` node, and if it does, it deletes it, allowing a chain deletion of all subsequent nodes (which can be useful when you want to delete a whole linked list).

Without setting `forward->next = NULL`, calling `delete forward;` would recursively delete all nodes starting from `forward`, which may not be what you want in all cases.

So, the **`if` condition** ensures that recursion only happens when it's needed, and **`delete forward`** alone is enough when you handle the rest of the list carefully (like setting `next = NULL`).
       

};

void insertAthead(node* &head,int data){
    node *temp=new node(data);
    temp->next=head;
    head=temp;
}

void insertAtTail(node* &head,int data){
    node *temp=new node(data);
    node *var=head;
    while(var->next!=NULL){
        var=var->next;
    }
    var->next=temp;
    temp->next=NULL;
}

or can also do this 

void insertAtTail(node* &head,int data){
    node *temp=new node(data);
    node *var=head;
    while(var->next!=NULL){
        var=var->next;
    }
    var->next=temp;
    temp->next=NULL;
}


void printList(node* &head){
    node *temp=head;
    while(temp!=NULL){//dont do temp->next!=NULL because then the last value will be skipped bs jab tk temp hmara NULL ke equal nhi hota tb tk loop run karna okk
        cout<<temp->data;
        temp=temp->next;
        cout<<" ";
    }
}

void insertAtpos(node* &tail,node* &head,int pos,int data){
  // it is required because we are starting from the head so it can't insert at start
    if(pos==1){
        insertAthead(head,data);
        return ;//it is necessary because o/w the remaining part will be performed
    }
  
    node *current=head;
    int count=1;
    while(count<pos-1){
        current=current->next;
        count++;
    }

  //means ager last me add kr rhe hai ham to surely current hmara null ko point kr rha hoga
   if(current->next==NULL){
        insertAtTail(tail,data);
        return;
    }
    node *nodetoInsert=new node(data);
    nodetoInsert->next=current->next;
    current->next=nodetoInsert;
}

or can also do this



void insertAtpos(node* &head,int pos,int data){
    // it is required because we are starting from the head so it can't insert at start
    if(pos==1){
        insertAthead(head,data);
        return ;//it is necessary because o/w the remaining part will be performed
    }
    node *temp=new node(data);
    node *current=head;
    node *forward=head->next;
    int count=1;
    while(count<pos-1){
        current=current->next;
        forward=forward->next;
        count++;
    }
   //iske bina bhi ho jata but hmara tail update nhi hota okk
     if(current->next==NULL){
        insertAtTail(tail,data);
        return;
    }
    current->next=temp;
    temp->next=forward;
}

void deleteAtPos(node* &tail,node* &head,int pos){
    
    if(pos==1){
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node *current=head;
        node *forward=head->next;
        int count=1;
        while(count<pos-1){
            current=current->next;
            forward=forward->next;
            count++;
        }
        if(forward->next==NULL){
            // current->next=NULL;
            current->next=forward->next;
            tail=current;
        }
         else{
            current->next=forward->next;
        }
        forward->next=NULL;
        delete forward;
    }
}

int main(){
    // node *head=node1;
    node* node1=new node(40);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
     
    node *head=node1;//so dekho yha pe hamne node1 ki memory pe hi head ko point krvaya hai okkk this is very imp
    node *tail=node1;//as initially to dono ek node jo create kiya uspe point krenge
    insertAthead(head,3);
    printList(head);

     cout<<"head:"<<head->data<<endl;
    cout<<"tail:"<<tail->data;
}
