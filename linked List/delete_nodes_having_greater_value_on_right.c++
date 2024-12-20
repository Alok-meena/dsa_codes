Delete nodes having greater value on right
Difficulty: EasyAccuracy: 35.51%Submissions: 143K+Points: 2
Given a singly linked list, remove all the nodes with any node on their right whose value is greater and return the head of the modified linked list.  (Not just the immediate Right, but the entire List on the Right)

Examples:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15->11->6->3

Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes. So, after deleting them, the linked list would like be 15, 11, 6, 3.
Input:
LinkedList = 10->20->30->40->50->60
Output: 60

Explanation: All the nodes except the last node has a greater value node on its right, so all the nodes except the last node must be removed.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 ≤ size of linked list ≤ 106
1 ≤ element of linked list ≤ 106





in ques given that remove nodes having greater value on right means we have to arrange it in descending order so it will be difficult to remove the current node
so instead reverse list and try to sort it if next value is smaller then skip that value okk


class Solution {
  public:
   Node* reverselist(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *compute(Node *head) {
        // your code goes here
        head=reverselist(head);
        
        Node *curr=head;

        while(curr!=NULL && curr->next!=NULL){
            if(curr->data>curr->next->data){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
        head=reverselist(head);
        return head;
    }
};

t.c:-O(n) and s.c:-O(1)
