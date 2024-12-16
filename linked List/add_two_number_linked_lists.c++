Add Number Linked Lists
Difficulty: MediumAccuracy: 34.52%Submissions: 293K+Points: 4
Given two numbers, num1, and num2, represented by linked lists. The task is to return the head of the linked list representing the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 45 (4->5->null), num2 = 345 (3->4->5->null)
Output:  3->9->0->null  
 
Explanation: 
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Input: num1 = 0063 (0->0->6->3->null), num2 = 07 (0->7->null)
Output: 7->0->null
 
Explanation: 
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
Expected Time Complexity: O(n+m)
Expected Space Complexity: O(max(n,m)) for the resultant list.

Constraints:
1 <= size of both linked lists <= 106
0 <= elements of both linked lists <= 9









#include <bits/stdc++.h>

class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node* reverseList(Node *head){
        Node *prev=NULL;
        Node *curr=head;
        Node *forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    
    void insertAthead(Node* &head,int val){
        if(head==NULL){
           Node *temp=new Node(val);
           head=temp;
       }
       else{
            Node *temp=new Node(val);
            temp->next=head;
            head=temp;
       }
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        
        num1=reverseList(num1);
        num2=reverseList(num2);
        
        Node *curr1=num1;
        Node *curr2=num2;
        int carry=0;
        vector<int>ans;
        
        while(curr1!=NULL && curr2!=NULL){
            int sum=curr1->data + curr2->data + carry;
            
            ans.push_back(sum%10);
            carry=sum/10;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        while(curr1!=NULL){
            int sum=curr1->data + carry;
            
            ans.push_back(sum%10);
            carry=sum/10;
            curr1=curr1->next;
        }
        
        while(curr2!=NULL){
            int sum= curr2->data + carry;
            
            ans.push_back(sum%10);
            carry=sum/10;
            curr2=curr2->next;
        }
        
        if(carry){
            ans.push_back(carry);
        }
        

        Node *head=NULL;
        
        for(auto i:ans){
            insertAthead(head,i);
        }
        
        return head;
    }
};

t.c:-O(n+m) and s.c:-O(max(n,m))


2nd

#include <bits/stdc++.h>

class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node* reverseList(Node *head){
        Node *prev=NULL;
        Node *curr=head;
        Node *forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    
    void insertAttail(Node* &head,Node* &tail,int val){
        Node *temp=new Node(val);
        
        if(head==NULL){
           tail=temp;
           head=temp;
           return;
       }
       else{
            tail->next=temp;
            tail=temp;
            return;
       }
    }
    
    Node* addList(Node* &first,Node* &second){
        
        Node *ansHead=NULL;
        Node *ansTail=NULL;
        
        int carry=0;

        //here we did insertAtTail 

        //but if we do insertAThead then no need of reversal of the list okk
        
        while(first!=NULL && second!=NULL){
            int sum=first->data + second->data + carry;
            
            insertAttail(ansHead,ansTail,sum%10);
            
            carry=sum/10;
            first=first->next;
            second=second->next;
        }
        
        while(first!=NULL){
            int sum=first->data + carry;
            
            insertAttail(ansHead,ansTail,sum%10);
            
            carry=sum/10;
            first=first->next;
        }
        while(second!=NULL){
            int sum=second->data + carry;
            
            insertAttail(ansHead,ansTail,sum%10);
            
            carry=sum/10;
            second=second->next;
        }
        while(carry){
            insertAttail(ansHead,ansTail,carry%10);
            
            carry/=10;
        }
        
        return ansHead;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        
        num1=reverseList(num1);
        num2=reverseList(num2);
        
        Node *ans=addList(num1,num2);
        
        ans=reverseList(ans);
        return ans;
    }
};

same t.c and s.c
