Rotate doubly Linked List
Difficulty: EasyAccuracy: 74.54%Submissions: 22K+Points: 2
Given a doubly linked list, rotate the linked list counter-clockwise by P nodes. Here P is a given positive integer and is smaller than the count of nodes(N) in a linked list.

Examples :

Input: Doubly Linkedlist: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 ,p = 2
Output: 3 <-> 4 <-> 5 <-> 6 <-> 1 <-> 2
Explanation: Doubly linked list after rotating
2 nodes is: 3 4 5 6 1 2.
Input: Doubly Linkedlist: 3 <-> 4 <-> 5 <-> 1 ,p = 3
Output: 1 <-> 3 <-> 4 <-> 5
Input: Doubly Linkedlist: 1 <-> 2 <-> 3 <-> 1 ,p = 2
Output: 3 <-> 1 <-> 2
Constraints:
1 <= p <=  number of nodes
2 <= number of nodes <= 105









class Solution {
  public:
    int getlength(Node *head){
        Node *temp=head;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    Node *rotateDLL(Node *head, int p) {

        // code here..
        int len=getlength(head);
        if(len==p) return head;
        if(p>len) p=p%len;
        if(p==0) return head;
        
        
        vector<int>value;
        Node *temp=head;
        while(p-- && temp!=NULL){
            value.push_back(temp->data);
            temp=temp->next;
        }
        head=temp;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        
        Node *tail=temp;
        int count=value.size();
        int i=0;
        while(count--){
            int val=value[i++];
            Node *newnode=new Node(val);
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        
        tail->next=NULL;
        
        return head;
    }
};

t.c:-O(n) and s.c:-O(n)

but this code is little clumsy and takes space

t.c:-O(n) and s.c:-O(1) more optimized

class Solution {
  public:
    int getlength(Node *head){
        Node *temp=head;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    Node *rotateDLL(Node *head, int p) {

        // code here..
        if(!head || p==0) return head;
        
        int len=getlength(head);
        
        p=p % len;
        
        if(p==0) return head;
        
        Node *temp=head;
        
        while(--p){
            temp=temp->next;
        }
        
        Node *newhead=temp->next;
        if(newhead==NULL) return head; // case of p==len
        temp->next=NULL;

        Node *t=newhead;
        while(t->next!=NULL){
            t=t->next;
        }
        
        t->next=head;
        head->prev=t;
        
        temp->next=NULL;
        
        return newhead;
        
    }
};
