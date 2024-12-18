Palindrome Linked List
Difficulty: MediumAccuracy: 41.48%Submissions: 347K+Points: 4
Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

Examples:

Input: LinkedList: 1->2->1->1->2->1
Output: true
Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

Input: LinkedList: 1->2->3->4
Output: false
Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1) 

Constraints:
1 <= number of nodes <= 105
1 ≤ node->data ≤ 103










bool isPalindrome(Node *head) {
        // Your code here
        Node *t1=head;
        vector<int>ans;

        while(t1!=NULL){
            ans.push_back(t1->data);
            t1=t1->next;
        }
        
        int i=0;
        int j=ans.size()-1;
        while(i<j){
            if(ans[i]!=ans[j]) return false;
            i++;j--;
        }
        
        
        return true;
    }

t.c:-O(n) and s.c:-O(n) 

2nd approach


t.c:-O(n) and s.c:-O(1)

class Solution {
  public:
    Node* reverseList(Node* head){
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
    
    Node *middle(Node *head){
        int count=0;
        Node *slow=head;
        Node *fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        if(head==NULL || head->next==NULL) return true;
        Node *t1=head;
        Node *reversedList=middle(head);
        Node *t2=reversedList->next;
        t2=reverseList(t2);
        
        while(t2!=NULL){
            if(t1->data!=t2->data) return false;
            t1=t1->next;
            t2=t2->next;
        }
        
        reverseList(reversedList);
        return true;
        
    }
};

just reverse the part after middle comparing and then return t/f and the again reverse the part so that original list remains unchanged
