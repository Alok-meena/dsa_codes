




simplest of all


Node* solve(Node* &a,Node* &b){
        Node *prev=a;
        Node *curr1=a->next;
        
        Node *curr2=b;
        
        while(curr1!=NULL and curr2!=NULL){
            if(prev->data<=curr2->data and curr2->data<=curr1->data){
                prev->next=curr2;
                Node *forward=curr2->next;
                curr2->next=curr1;
                prev=curr2;
                curr2=forward;
            }
            else{
                prev=curr1;
                curr1=curr1->next;
            }
        }
        
        if(curr2!=NULL) prev->next=curr2;
        
        return a;
    }
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        if(!head1) return head2;
        if(!head2) return head1;
        
        if(head1->data<head2->data){
            return solve(head1,head2);
        }
        else{
            return solve(head2,head1);
        }
    }


O(n) t.c and s.c: O(1) alright that's it



class Solution {
  public:
    void insertatTail(int val,Node* &tail,Node* &head){
        Node *newNode=new Node(val);
        
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        
    
        Node *newHead=NULL;
        Node *tail=newHead;
        Node *t1=head1;
        Node *t2=head2;
        
        while(t1!=NULL && t2!=NULL){
            if(t1->data<t2->data){
                insertatTail(t1->data,tail,newHead);
                t1=t1->next;
            }
            else{
                insertatTail(t2->data,tail,newHead);
                t2=t2->next;
            }
        }
        
        while(t1!=NULL){
            insertatTail(t1->data,tail,newHead);
            t1=t1->next;
        }
        while(t2!=NULL){
            insertatTail(t2->data,tail,newHead);
            t2=t2->next;
        }
        
        
        return newHead;
        
        
    }
};


t.c:-O(n+m) and s.c:-O(n+m)

and we can also use a dummy node then no need of more if conditions 

class Solution {
  public:
    void insertatTail(int val, Node* &tail) {
        Node *newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }

    Node* sortedMerge(Node* head1, Node* head2) {
        // Dummy node to simplify insertion logic
        Node *dummy = new Node(-1);
        Node *tail = dummy;

        Node *t1 = head1;
        Node *t2 = head2;

        // Merge nodes from both lists
        while (t1 != NULL && t2 != NULL) {
            if (t1->data < t2->data) {
                insertatTail(t1->data, tail);
                t1 = t1->next; // Move t1 forward
            } else {
                insertatTail(t2->data, tail);
                t2 = t2->next; // Move t2 forward
            }
        }

        // Append remaining nodes from t1 (if any)
        while (t1 != NULL) {
            insertatTail(t1->data, tail);
            t1 = t1->next;
        }

        // Append remaining nodes from t2 (if any)
        while (t2 != NULL) {
            insertatTail(t2->data, tail);
            t2 = t2->next;
        }

        // Update the head of the merged list
        Node *newHead = dummy->next;

        // Free the dummy node
        delete dummy;

        return newHead;
    }
};


another method is making changes in the original list only

class Solution {
  public:
    Node* solve(Node* &first,Node* &second){
        if(first->next==NULL){
            first->next=second;
            return first;
        }
        
        Node *curr1=first;
        Node *next1=curr1->next;
        Node *curr2=second;
        Node *next2=second->next;//to have pointer to the remaining list
        
        while(next1!=NULL && curr2!=NULL){
            
            if(curr2->data>=curr1->data && curr2->data<=next1->data){
                curr1->next=curr2;
                next2=curr2->next;
                curr2->next=next1;
                curr1=curr2;
                curr2=next2;
            }
            else{
                curr1=next1;
                next1=next1->next;

                //if first list is fully traversed then connect remaining seconnd list okk
                
                if(next1==NULL){
                    curr1->next=curr2;
                    return first;
                }
            }
        }
        return first;
    }
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;


        //insert values in the list whose head value is smaller
        if(head1->data<=head2->data){
            return solve(head1,head2);
        }
        else{
            return solve(head2,head1);
        }
    }
};

same t.c and s.c
