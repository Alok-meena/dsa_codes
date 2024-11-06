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
