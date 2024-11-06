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
        Node *prev=NULL;
        Node *curr=head;
        Node *forward;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
};
