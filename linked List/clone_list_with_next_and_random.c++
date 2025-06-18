






approach 2 

t.c:-O(n) and s.c:-O(n)

class Solution {
  public:
    
    void insertattail(Node* &head,Node* &tail,int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            tail=newnode;
            head=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    Node *copyList(Node *head) {
        // Write your code here
        Node *cloneHead=NULL;
        Node *cloneTail=NULL;
        
        Node *temp=head;
        while(temp!=NULL){
            insertattail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        unordered_map<Node*,Node*>oldTOnew;
        
        temp=head;
        Node *t=cloneHead;
        while(temp!=NULL && t!=NULL){
            oldTOnew[temp]=t;
            temp=temp->next;
            t=t->next;
        }
        
        Node *original=head;
        
        Node *clone=cloneHead;
        while(clone!=NULL){
            clone->random=oldTOnew[original->random];
            
            clone=clone->next;
            original=original->next;
        }
        
        return cloneHead;
    }
};

t.c:-O(n) and s.c:-O(n)


instead of this short code with same t.c and s.c

class Solution {
  public:
    void insertattail(Node* &head,Node* &tail,int value){
        if(head==NULL){
            Node *newnode=new Node(value);
            head=newnode;
            tail=newnode;
        }
        else{
            Node *newnode=new Node(value);
            tail->next=newnode;
            tail=newnode;
        }
    }
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node *clonehead=NULL;
        Node *clonetail=NULL;
        
        unordered_map<Node*,Node*>oldtonew;
        
        Node *oldhead=head;
        while(oldhead!=NULL){
            insertattail(clonehead,clonetail,oldhead->data);
            oldtonew[oldhead]=clonetail;
            
            oldhead=oldhead->next;
        }
        
        oldhead=head;
        Node *temp=clonehead;
        
        while(oldhead!=NULL){
            temp->random=oldtonew[oldhead->random];
            oldhead=oldhead->next;
            temp=temp->next;
        }
        
        return clonehead;
        
        
    }
};


optimized with s.c:-O(1) and t.c:-O(n)

class Solution {
  public:
    
    void insertattail(Node* &head,Node* &tail,int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            tail=newnode;
            head=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    
    
    Node *copyList(Node *head) {
        // Write your code here
        
        if(head==NULL) return NULL;
                
        Node *cloneHead=NULL;
        Node *cloneTail=NULL;
        
        //step1 create normal list without random pointers
        
        Node *temp=head;
        while(temp!=NULL){
            insertattail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        //step2 link both original and clone ist together
        
        Node *original=head;
        Node *clone=cloneHead;
        
        while(original!=NULL && clone!=NULL){
            //for original list
            Node *next1=original->next;
            original->next=clone;
            original=next1;
            
            //for clone list
            Node *next2=clone->next;
            clone->next=original;
            clone=next2;
        }
        
        //step3 add random pointers
        
        original=head;

        while(original!=NULL){
            if(original->next!=NULL){
                original->next->random=original->random? original->random->next:NULL;
            }
            original=original->next->next;
        }
        
        //step4 reverse the arrangement to normal
        original=head;
        clone=cloneHead;
        
        while(original!=NULL && clone!=NULL){
            original->next=clone->next;
            original=original->next;

            //suppose we are at the last node of original and now it's next is set to the NULL pointer then null exception can occur in next step so check here
            //if original !=null not it's next because then it will be normally set to the null okk
            if(original!=NULL){
                clone->next=original->next;
            }
            clone=clone->next;
        }
        
        return cloneHead;
    }
};


2nd time

class Solution {
  public:
    void insertattail(Node* &head,Node* &tail,int value){
        if(head==NULL){
            Node *newnode=new Node(value);
            head=newnode;
            tail=newnode;
        }
        else{
            Node *newnode=new Node(value);
            tail->next=newnode;
            tail=newnode;
        }
    }
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node *clonehead=NULL;
        Node *clonetail=NULL;
        
        Node *oldhead=head;
        while(oldhead!=NULL){
            insertattail(clonehead,clonetail,oldhead->data);
            oldhead=oldhead->next;
        }
        
        oldhead=head;
        Node *cloneptr=clonehead;
        
        while(cloneptr!=NULL and oldhead!=NULL){
            Node *old_next=oldhead->next;
            oldhead->next=cloneptr;
            oldhead=old_next;
            
            Node *clone_next=cloneptr->next;
            cloneptr->next=oldhead;
            cloneptr=clone_next;
        }
        
        oldhead=head;

        while(oldhead!=NULL){
            if(oldhead->next!=NULL and oldhead->random!=NULL){
                oldhead->next->random=oldhead->random->next;
            }
            else oldhead->next->random=NULL;
            oldhead=oldhead->next->next;
        }
        
        oldhead=head;
        cloneptr=clonehead;
        
        while(oldhead!=NULL){
            Node *old_next=cloneptr->next;
            oldhead->next=old_next;
            oldhead=old_next;
            
            Node *clone_next=NULL;
            if(oldhead!=NULL) clone_next=oldhead->next;
            cloneptr->next=clone_next;
            cloneptr=clone_next;
        }
        
        return clonehead;
        
        
    }
};
