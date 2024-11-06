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
