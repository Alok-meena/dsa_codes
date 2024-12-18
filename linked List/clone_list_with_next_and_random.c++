






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
