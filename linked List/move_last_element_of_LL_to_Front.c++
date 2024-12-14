You are given the head of a Linked List. You have to move the last element to the front of the Linked List and return the head the modified linked list.

Examples:

Input: Linked List: 2->5->6->2->1
Output: 1->2->5->6->2

Explanation: In the given linked list, the last element is 1, after moving the last element to the front the linked list will be 1->2->5->6->2
Input: Linked List: 2
Output: 2
Explanation: Here 2 is the only element so, the linked list will remain the same.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= size of linked list <= 106
0 <= elements of list <= 109



class Solution {
  public:
    Node *moveToFront(Node *head) {
        // code here
        int val;
        Node *prev=head;
        Node *temp=head->next;
        while(temp!=NULL){
            if(temp->next==NULL){
                val=temp->data;
                prev->next=NULL;
                delete(temp);
                break;
            }
            temp=temp->next;
            prev=prev->next;
        }
        
        Node *nodetoInsert=new Node(val);
        nodetoInsert->next=head;
        head=nodetoInsert;
        return head;
        
        
    }
};
