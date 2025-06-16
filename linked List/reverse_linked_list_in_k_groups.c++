Given a linked list, the task is to reverse every k node (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

Examples:

Input: Linked List: 1->2->2->4->5->6->7->8, k = 4
Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5 

Explanation: The first 4 elements 1,2,2,4 are reversed first and then the next 4 elements 5,6,7,8. Hence, the resultant linked list is 4->2->2->1->8->7->6->5.
Input: LinkedList: 1->2->3->4->5, k = 3
Output: 3 -> 2 -> 1 -> 5 -> 4

Explanation: The first 3 elements 1,2,3 are reversed first and then element 4,5 are reversed. Hence, the resultant linked list is 3->2->1->5->4.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)




t.c:-O(n) and s.c:-O(n) due to n/k recursive stack calls alright


class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
        // Complete this method
        if(head==NULL){
        return NULL;
    }

    //reverse first k nodes
struct node *forward=NULL;
   struct node *prev=NULL;
   struct node *curr=head;
    int count=0;
    while(curr!=NULL && count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }

    if(forward!=NULL){
        head->next=reverseIt(forward,k);
    }
    return prev;
    }
};


if the last pair is <k then 
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
int getlength(Node *head){
    int len=0;
    while(head!=NULL){
        head=head->next;
        len++;
    }
    return len;
}
Node *kReverse(Node *head, int k) {
  if(head==NULL){
      return NULL;
  }
  int n=getlength(head);
  Node *current = head;

  //to ye n hmara har ek l.l ke part ki length caluclate kr rha hai and if it's len is less than k than it will not reverse it just pass the head ookk
  if(n<k){
      return head;
  }
  Node *next = NULL;
  Node *prev = NULL;
  int count = 0;
    while(current!=NULL && count<k){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(next!=NULL){
        head->next=kReverse(next,k);
    }
    return prev;
}


easily understandable code

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode *head){
        ListNode *temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(length(head)<k) return head;

        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode * forward;

        int count=0;

        while(curr!=NULL && count<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }

        //here it should be forward ! = NULL not head->next because it will be NULL only becaue till now you didnt connecte it with the next part
        if(forward!=NULL){
            head->next=reverseKGroup(forward,k);
        }
       

        return prev;
    }
};
