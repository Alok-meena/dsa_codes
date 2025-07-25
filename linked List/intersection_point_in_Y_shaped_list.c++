Intersection in Y Shaped Lists
Difficulty: MediumAccuracy: 44.67%Submissions: 294K+Points: 4
Given two singly linked lists, return the point where two linked lists intersect.

Note: If the linked lists do not merge at any point, return -1.

Examples:

Input: Linked list 1: 4->4->4->4->4, Linked list 2: 4->4->4
 
Output: 4
Explanation: From the above image, it is clearly seen that the common part is 4->4 whose starting point is 4.

Input: Linked list 1: 4->1->8->4->5, Linked List 2: 5->6->1->8->4->5
 
Output: 8
Explanation: From the above image, it is clearly seen that the common part is 8->4->5 whose starting point is 8.
Input: Linked list 1: 1->2->3, Linked list 2: 4->5->6
Output: -1
Explanation: There is no common part, so there is no interaction point.
Try to solve the problem without using any extra space.

Constraints:
2 ≤ size of first linkedist + size of second linkedlist ≤ 2*105
-10000 ≤ data of nodes ≤ 10000






using map we can store the nodes address and then compare

class Solution {
  public:
  
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        Node *t1=head1;
        Node *t2=head2;
        
        unordered_map<Node*,int>mp;
        
        while(t1!=NULL){
            mp[t1]=t1->data;
            t1=t1->next;
        }
        
        while(t2!=NULL){
            if(mp.find(t2)!=mp.end()) return t2->data;
            t2=t2->next;
        }
        
        return -1;
        
    }
}

t.c:-O(n+m) because O(1) for find operation in unordered_map okk and log(n) in ordred_map okk s.c:-O(n)



class Solution {
  public:
  
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        Node *t1=head1;
        Node *t2=head2;
        
        int len1=0;
        int len2=0;
        
        while(t1!=NULL){
            len1++;
            t1=t1->next;
        }
        
        while(t2!=NULL){
            len2++;
            t2=t2->next;
        }
        
        t1=head1;
        t2=head2;
        
        if(len1>len2){
            int diff=len1-len2;
            while(diff--){
                t1=t1->next;
            }
        }
        else{
            int diff=len2-len1;
            while(diff--){
                t2=t2->next;
            }
        }
        
        while(t1!=NULL && t2!=NULL){
            if(t1==t2) return t1->data;
                t1=t1->next;
                t2=t2->next;
        }
        
        return -1;
        
    }
};

t.c:-O(n+m) both list length and s.c:-O(1)


class Solution {
  public:
  
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        Node *t1=head1;
        Node *t2=head2;
        
        unordered_map<Node*,int>mp;
        
        while(t1!=NULL && t2!=NULL){
            t1=t1->next;
            t2=t2->next;
            
            if(t1==t2) return t1->data;
            
            if(t1==NULL) t1=head2;
            if(t2==NULL) t2=head1;
        }
        
       
        
        return -1;
        
    }
}; 

just similar to prev if the smaller list is traversed then put both pointers or swap them to headd after reaching NULL then both will start at the same distance

t.c:-O(n1+n2)



or 

same code

class Solution {
  public:
    int length(Node* head){
        Node *temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        return count;
    }
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int len1=length(head1);
        int len2=length(head2);
        Node *a=NULL;
        Node *b=NULL;
        
        if(len1>len2){
            int steps=len1-len2;
            a=head1;
            b=head2;
            while(steps){
                a=a->next;
                steps--;
            }
            
            while(a!=b){
                a=a->next;
                b=b->next;
            }
        }
        else{
            int steps=len1-len2;
            a=head1;
            b=head2;
            while(steps){
                b=b->next;
                steps--;
            }
            
            while(a!=b){
                a=a->next;
                b=b->next;
            }
        }
        
        return a;
    }
};


3rd time

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }

        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=length(headA);
        int l2=length(headB);

        int cnt;

        if(l1>l2){
            cnt=l1-l2;
            ListNode *b=headB;
            ListNode *a=headA;
            while(cnt--) a=a->next;

            while(a!=NULL and b!=NULL){
                if(a==b){
                    return a;
                    break;
                }
                a=a->next;b=b->next;
            }
        }
        else{
            cnt=l2-l1;
            ListNode *b=headB;
            ListNode *a=headA;
            while(cnt--) b=b->next;


            while(a!=NULL and b!=NULL){
                if(a==b){
                    return a;
                    break;
                }
                a=a->next;b=b->next;
            }
        }

        return NULL;
    }
};
