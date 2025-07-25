Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Examples:

Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
 
Input: LinkedList: 2->2->0->1
Output: 0->1->2->2
Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).





class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        int zero=0;
    int one=0;
    int two=0;

    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero++;
        }
        if(temp->data==1){
            one++;
        }
        if(temp->data==2){
            two++;
        }
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){
        if(zero){
            temp->data=0;
            zero--;
        }
        else if(one){
            temp->data=1;
            one--;
        }
        else{
            temp->data=2;
            two--;
        }
        temp=temp->next;
    }
    return head;
    }
};


t.c:O(n) s.c:-O(1)

but if in ques given we cant replace the values then 

use this



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

Node* sortList(Node *head){
    // Write your code here.
    vector<int>s;
    Node *temp=head;

    while(temp!=NULL){
        s.push_back(temp->data);
        temp=temp->next;
    }

    sort(s.begin(),s.end());


    Node *newhead=NULL;
    Node *tail=NULL;

    for(auto i:s){
        insertattail(newhead,tail,i);
    }

    return newhead;
}

t.c:-O(nlogn) and s.c:-O(n)

next approach::


below one takes O(1) space alright



void insertattail(Node* &tail,Node *curr){ //here curr is passed by value but only address is copied not entire node alright so points to same node
    tail->next=curr;
    tail=curr;
}

Node* sortList(Node *head){
    // Write your code here.

    Node *zerohead=new Node(-1);
    Node *zerotail=zerohead;
    Node *onehead=new Node(-1);
    Node *onetail=onehead;
    Node *twohead=new Node(-1);
    Node *twotail=twohead;

    Node *curr=head;
    
    while(curr!=NULL){
        int val=curr->data;

        if(val==0){
            insertattail(zerotail,curr);
        }
        else if(val==1){
            insertattail(onetail,curr);
        }
        else{
            insertattail(twotail,curr);
        }

        curr=curr->next;
    }

    if(onehead->next!=NULL){
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;

    head=zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

same t.c and s.c



another time



Node* sortList(Node *head){
    // Write your code here.
    Node *zerohead=new Node(-1);
    Node *onehead=new Node(-1);
    Node *twohead=new Node(-1);

    Node *zerotail=zerohead;
    Node *onetail=onehead;
    Node *twotail=twohead;

    Node *curr=head;

    while(curr!=NULL){
        if(curr->data==0){
            zerotail->next=curr;
            zerotail=curr;
        }
        else if(curr->data==1){
            onetail->next=curr;
            onetail=curr;
        }
        else{
            twotail->next=curr;
            twotail=curr;
        }
        curr=curr->next;
    }

    if(onehead->next!=NULL){
        zerotail->next=onehead->next;
        onetail->next=twohead->next;
    }
    else zerotail->next=twohead->next;

    twotail->next=NULL;

    head=zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

and also we dont need to create the nodes with values but then we have to do like below


if (curr->data == 0) {
    if (zeroHead == NULL) {
        zeroHead = curr;
        zeroTail = curr;
    } else {
        zeroTail->next = curr;
        zeroTail = curr;
    }
}
// same for 1s and 2s


separatly handle if first node to connect as set both head and tail to the start node like this then can use only tail
