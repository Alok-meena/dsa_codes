Reverse a Doubly Linked List
Difficulty: EasyAccuracy: 70.38%Submissions: 153K+Points: 2
Given a doubly linked list. Your task is to reverse the doubly linked list and return its head.

Examples:

Input: LinkedList: 3 <-> 4 <-> 5
Output: 5 <-> 4 <-> 3

Input: LinkedList: 75 <-> 122 <-> 59 <-> 196
Output: 196 <-> 59 <-> 122 <-> 75

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).





class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode *p=NULL;
        DLLNode *curr=head;
        DLLNode *forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=p;
            p=curr;
            curr->prev=forward;
            curr=forward;
        }
        
        return p;
    }
};

2nd time

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode *temp=head;
        DLLNode *prev=NULL;

        DLLNode *curr_prev=NULL;
        DLLNode *curr_next=temp->next;
        
        while(temp!=NULL){
            prev=temp;
            curr_prev=temp->prev;
            curr_next=temp->next;
            
            temp->next=curr_prev;
            temp->prev=curr_next;
            
            temp=temp->prev;
        }
        
        return prev;
    }
};
