Reverse a linked list
Difficulty: EasyAccuracy: 73.11%Submissions: 310K+Points: 2
Given the head of a linked list, the task is to reverse this list and return the reversed head.

Examples:

Input: Linked list: 1->2->3->4->5->6
Output: 6->5->4->3->2->1
Explanation:

Input: Linked list: 2->7->10->9->8 
Output: 8->9->10->7->2
Explanation:

Input: Linked List: 10
Output: 10
Explanation: For a single node list, the reverse would be same as original
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)



class Solution {
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
      if(head==NULL || head->next==NULL){
        return head;
      }
        // code here
        // return head of reversed list

       //so basically start kro head se right and curr ke next linked list pe pointer rkh lo and then curr ko reverse me prev pe point krva do 
      //then prev ko curr pe lao and curr ko forward pe and do until curr reaches NULL right
        struct Node *prev=NULL;
        struct Node *current=head;
        struct Node *forward;
        
        while(current!=NULL){
            forward=current->next;
            current->next=prev;
            prev=current;
            current=forward;
        }
        return prev;
    }
};


recursive

//to make changed in the original linked list pass values by reference

void reverse(Node* &head,Node* &curr,Node* &prev){
    if(curr==NULL){
        head=prev;
        // 1-2-3-4-5-6-null to is point pe to curr null pe hai but jab hmne return kiya then vo 6 pe hoga and bs vhi se fun call ki next line hi print hogi
        // right to bs curr->next=prev krte jao
        return;
    }

    Node*forward=curr->next;
    //to same to same pahle jaisa haijust current->next=prev hamne last me karna start kiya hai ye list ke end tk jayega fir jaise jaise vapas aayega vha se 
  //reverse dirn me curr->next=prev krta jayega okkk
    reverse(head,forward,curr);
    curr->next=prev;
}
Node *reverseLinkedList(Node *head) {
    Node *curr=head;
    Node *prev=NULL;
    reverse(head,curr,prev);
    return head;
    
}


can also do like 

class Solution {
  public:
    Node* solve(Node* &prev,Node* &curr){
        if(curr==NULL) return prev;
        
        Node *forward=curr->next;
        curr->next=prev;
        
        return solve(curr,forward);
    }
    Node* reverseList(struct Node* head) {
        // code here
        Node *prev=NULL;
        Node *curr=head;
        
        return solve(prev,curr);
    }
};

or


class Solution {
  public:
    void solve(Node* &head,Node* &prev,Node* &curr){
        if(curr==NULL){
            head=prev;
            return;
        }
        
        Node *forward=curr->next;
        solve(head,curr,forward);
        curr->next=prev;
    }
    Node* reverseList(struct Node* head) {
        // code here
        Node *prev=NULL;
        Node *curr=head;
        
        solve(head,prev,curr);
        return head;
    }
};



2nd approach in recursive approach

LinkedListNode<int>* reverse(LinkedListNode<int>* &head){
  //for empty and single node linked list
    if(head==NULL || head->next==NULL){
        return head;
    }

  //so it will return the new head of the reversed linked list 
  //to bhai ye newhead k koi kam nhi bs yhi kam hai ki reverselist ka head return ho jayega alright
    LinkedListNode<int> *newhead=reverse(head->next);

    head->next->next=head;//to point 1->2-> this pointer which is head->next->next to the head itself we did so
    head->next=NULL;
    return newhead;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
   return reverse(head);
    
}
