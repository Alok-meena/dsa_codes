You have been given a singly linked list in which nodes are present in increasing order.
Your task is to construct a Balanced Binary Search Tree with the same data elements as the given Linked List.

A Balanced BST is defined as a BST in which the height of two subtrees of every node differs no more than 1.




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

