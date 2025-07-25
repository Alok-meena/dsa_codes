Merge Sort for Linked List
Difficulty: MediumAccuracy: 74.76%Submissions: 72K+Points: 4
Given a pointer/reference to the head of the linked list, the task is to sort the given linked list using Merge Sort.
Note: If the length of the linked list is odd, then the extra node should go into the first list while splitting.

Examples:

Input: LinkedList: 3->5->2->4->1
Output: 1->2->3->4->5
Explanation: After sorting the given linked list, the resultant matrix will be 1->2->3->4->5.

Input: LinkedList: 9->15->0
Output: 0->9->15
Explanation: After sorting the given linked list , resultant will be 0->9->15.

Expected Time Complexity: O(n*log(n))
Expected Auxiliary Space: O(n)

Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 106









class Solution {
  public:
    
    Node* findmid(Node *head){
        Node *slow=head;
        Node *fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    Node* merge(Node* &left,Node* &right){
        
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        
        Node *dummy=new Node(-1);
        Node *temp=dummy;
        
        while(left!=NULL && right!=NULL){
            if(left->data<right->data){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        
        while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        
        while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        
        
        temp=dummy->next;
        dummy->next=NULL;
        delete dummy;
        
        return temp;
    }
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here

        //base case
        if(head==NULL || head->next==NULL){
            return head;
        }

        //similarly we have finded the mid and then left and right part are initialized
        Node *mid=findmid(head);
        
        Node *left=head;
        Node *right=mid->next;
        mid->next=NULL;
        
        left=mergeSort(left);
        right=mergeSort(right);

        //here we are creating a new sorted list and returning it okk
        return merge(left,right);
        
    }
};



simple



node *findmid(node *head){
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

node* solve(node* &a,node* &b){
    node *prev=a;
    node *curr=a->next;

    node *temp=b;

    while(curr!=NULL and temp!=NULL){
        if(temp->data>=prev->data and temp->data<=curr->data){
            prev->next=temp;
            node *next1=temp->next;
            
            prev=temp;
            temp->next=curr;
            temp=next1;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }

    if(temp!=NULL) prev->next=temp; //imp ager 1 hi ele hua 2nd list me to pahle hi ham prev ko null kr rhe jo shi nhi ager last me temp null nhi h
    //to prev ko temp se jod do aor ager null hai then no tension already merged 

    return a;

}

node *merge(node* &a,node* &b){
    if(a==NULL) return b;
    if(b==NULL) return a;

    if(a->data<=b->data){
        return solve(a,b);
    }
    else return solve(b,a);
}
node* mergeSort(node *head) {
    // Write your code here.
    if(head==NULL or head->next==NULL) return head;

    node *mid=findmid(head);

    node *left=head;
    node *right=mid->next;

    mid->next=NULL;

    //call merge sort for left and right part individually
    left=mergeSort(left);
    right=mergeSort(right);
    
    //type of merge 2 sorted list 
    node *result=merge(left,right);

    return result;
}

