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




bestm best solution just jis part ko aage ya piche lgana hai utha lo alg kro aor lga do like below

class Solution {
  public:
    int length(Node *head){
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
        int len=length(head);
        if(head==NULL or head->next==NULL or p%len==0 or p==0) return head;
        
        p=p%len;
        
        Node *temp=head;
        int count=1;
        while(count<p and temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        Node *secondhalf=NULL;
        if(temp and temp->next){
            secondhalf=temp->next;
            temp->next=NULL;
            secondhalf->prev=NULL;
        }
        
        temp=secondhalf;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        
        temp->next=head;
        head->prev=temp;
        
        return secondhalf;
    }
};

and aget right me krna hota to n-p times chlate aor kr dete simple




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


or 


class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        d=d%n;
        reverse(arr.begin(),arr.begin()+d);
        reverse(arr.begin()+d,arr.end());
        reverse(arr.begin(),arr.end());
    }
    Node *rotateDLL(Node *head, int p) {

        // code here..
        vector<int>v;
        Node *temp=head;
        
        while(temp!=NULL){
            v.push_back(temp->data);
            temp=temp->next;
        }
    
        
        rotateArr(v,p);
        
        temp=head;
        for(auto i:v){
            temp->data=i;
            temp=temp->next;
        }

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

or

class Solution {
  public:
    int length(Node *head){
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
        int len=length(head);
        if(head==NULL or head->next==NULL or p%len==0 or p==0) return head;
        
        p=p%len;
        
        Node *temp=head;
        int count=1;
        while(count<p and temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        Node *secondhalf=NULL;
        if(temp and temp->next){
            secondhalf=temp->next;
            temp->next=NULL;
            secondhalf->prev=NULL;
        }
        
        temp=secondhalf;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        
        temp->next=head;
        head->prev=temp;
        
        return secondhalf;
    }
};

t.c:-O(n) and s.c:-O(1)

or

array code conversion

void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        d=d%n;
        reverse(arr.begin(),arr.begin()+d);
        reverse(arr.begin()+d,arr.end());
        reverse(arr.begin(),arr.end());
    }

same t.c and s.c


 class Solution {
  public:
    int length(Node *head){
        Node *temp=head;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    Node* reverse2(Node* head) {
        // Your code here
        Node *temp=head;
        Node *prev=NULL;
        
        while(temp!=NULL){
            prev=temp;
            Node *curr_prev=temp->prev;
            Node *curr_next=temp->next;
            
            temp->prev=curr_next;
            temp->next=curr_prev;
            
            temp=curr_next;
        }
        
        return prev;
    }
    
    Node* reverse1(Node* head, int d) {
    int count = 0;
    Node *temp = head;
    Node *p = NULL;
    
    while(count < d && temp != NULL){
        p = temp;
        Node *curr_prev = temp->prev;
        Node *curr_next = temp->next;
        
        temp->prev = curr_next;
        temp->next = curr_prev;
        
        temp = curr_next;
        count++;
    }

    // Now p is the new head of reversed part
    if(p) p->prev = NULL;

    // Find original head (now tail of reversed part)
    Node* tail = p;
    while(tail && tail->next != NULL){
        tail = tail->next;
    }

    if(temp) {
        tail->next = temp;
        temp->prev = tail;
    }

    return p;
}

    
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        d=d%n;
        reverse(arr.begin(),arr.begin()+d);
        reverse(arr.begin()+d,arr.end());
        reverse(arr.begin(),arr.end());
    }
     
    Node *rotateDLL(Node *head, int p) {

        // code here..
        int len=length(head);
        if(head == NULL || head->next == NULL || p == 0 || p % len == 0) return head;
        p=p%len;
        
        head=reverse1(head,p);
        
         Node *temp = head;
        int count = 1;
        while(count < p && temp != NULL){
            temp = temp->next;
            count++;
        }

        Node *secondHalf = NULL;
        if(temp && temp->next){
            secondHalf = temp->next;
            temp->next = NULL;
            secondHalf->prev = NULL;
        }

        Node *second = reverse2(secondHalf);
        

        temp->next = second;
        if(second) second->prev = temp;

        head = reverse2(head);
        
        return head;
        
    }
};
