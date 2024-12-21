Kth from End of Linked List
Difficulty: EasyAccuracy: 41.18%Submissions: 403K+Points: 2
Given the head of a linked list and the number k, Your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1.

Examples

Input: LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
Output: 8
Explanation: The given linked list is 1->2->3->4->5->6->7->8->9. The 2nd node from end is 8.

Input: LinkedList: 10->5->100->5, k = 5
Output: -1
Explanation: The given linked list is 10->5->100->5. Since 'k' is more than the number of nodes, the output is -1.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 106
1 <= node->data , x <= 106
1 <= k <= 106





class Solution {
  public:
   Node* reverseList(struct Node* head) {
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
    int getlength(Node *head){
        Node *temp=head;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    int getKthFromLast(Node *head, int k) {
        // Your code here
        int len=getlength(head);
        head=reverseList(head);
        
        if(k>len) return -1;
        Node *temp=head;
        while(--k){
            temp=temp->next;
        }
        return temp->data;
    }
};
