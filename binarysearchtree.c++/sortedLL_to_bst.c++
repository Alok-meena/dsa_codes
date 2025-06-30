You have been given a singly linked list in which nodes are present in increasing order.
Your task is to construct a Balanced Binary Search Tree with the same data elements as the given Linked List.

A Balanced BST is defined as a BST in which the height of two subtrees of every node differs no more than 1.

code t.c:-O(n) and s.c:-O(h) because we visit every node once and then returns alright

class Solution {
public:
    TreeNode* solve(ListNode* start,ListNode* end){
        if(start==end) return NULL;

        ListNode* slow=start;
        ListNode* fast=start;

        while(fast!=end and fast->next!=end){  //end ke equal check kiya why ? because in other part of list fast will never reach NULL alright 
            slow=slow->next;
            fast=fast->next->next;
        }

        TreeNode *newnode=new TreeNode(slow->val);

        newnode->left=solve(start,slow);
        newnode->right=solve(slow->next,end);

        return newnode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head,NULL);
    }
};



second:





int nodes(Node<int>*head){
    int count=0;
    Node<int>* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

TreeNode<int>* sortlinkedlisttobst(Node<int>* &head,int n){
    if(n<=0 || !head){
        return NULL;
    }

   TreeNode<int>* left=sortlinkedlisttobst(head,n/2);
    TreeNode<int>* root = new TreeNode<int>(head->data);

    head=head->next;
    
    root->left=left;
    root->right=sortlinkedlisttobst(head,n-1-n/2);
    return root;
    
}
TreeNode<int>* sortedListToBST(Node<int>* head) 
{
	// Write your code here.
    int length=nodes(head);
    if(!head){
        return NULL;
    }
    return sortlinkedlisttobst(head,length);
}


t.c:-O(n) and s.c:-O(h) if excluding the tree building space 
