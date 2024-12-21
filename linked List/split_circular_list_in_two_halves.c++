Split a Linked List into two halves
Difficulty: EasyAccuracy: 61.63%Submissions: 56K+Points: 2
Given a Circular linked list. The task is split into two Circular Linked lists. If there are an odd number of nodes in the given circular linked list then out of the resulting two halved lists, the first list should have one node more than the second list.

Examples :

Input: LinkedList : 10->4->9
Output: 10->4 , 9
 
Explanation: After dividing linked list into 2 parts , the first part contains 10, 4 and second part contain only 9.
Input: LinkedList : 10->4->9->10
Output: 10->4 , 9->10
Explanation: After dividing linked list into 2 parts , the first part contains 10, 4 and second part contain 9, 10.
Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)








class Solution {
  public:
    int getlength(Node *head){
        Node *temp=head->next;
        int length=0;
        while(temp!=head){
            length++;
            temp=temp->next;
        }
        return length;
    }

    Node *findMiddle(Node *head) {
        // Write your code here
        int length=getlength(head);
        Node *temp=head;
        if(length%2!=0){
            int count=(length+1)/2;
            count--;
            while(count--){
                temp=temp->next;
            }
            return temp;
        }
        int count=length/2;
            while(count--){
                temp=temp->next;
            }
            return temp;
    
    }
    pair<Node *, Node *> splitList(struct Node *head) {
        // code here
        Node *mid=findMiddle(head);
        Node *temp=mid->next;
        Node *right=temp;
        while(right->next!=head){
            right=right->next;
        }
        
        right->next=temp;
        
        mid->next=head;
        
        return {head,temp};
        
    }
};

Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)
