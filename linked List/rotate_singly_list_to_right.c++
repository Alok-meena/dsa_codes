61. Rotate List
Solved
Medium
Topics
Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]






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
     int getlength(ListNode *head){
        ListNode *temp=head;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int p=k;
        if(!head || p==0) return head;
        
        int len=getlength(head);
        
        p=p % len;
        
        if(p==0) return head;
        p=len-p;
        
        ListNode *temp=head;
        
        while(--p){
            temp=temp->next;
        }
        
        ListNode *newhead=temp->next;
        ListNode *newtail=temp;
        
        ListNode *oldtail=newhead;
        while(oldtail->next!=NULL){
            oldtail=oldtail->next;
        }
        
        oldtail->next=head;
        // head->prev=oldtail;
        
        newtail->next=NULL;
        
        return newhead;
    }
};

t.c:-O(n) and s.c:-O(1)
