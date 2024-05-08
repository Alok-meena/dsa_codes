so if we have to return the elements of both the bst in sorted order then code :-

void inorder(TreeNode *root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}
vector<int> mergettwosortedlist(vector<int>& a, vector<int>& b) {
    vector<int> ans(a.size()+b.size());
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans.push_back(a[i++]);
        } else {
            ans.push_back(b[j++]);
        }
    }
    while (i < a.size()) {
        ans.push_back(a[i++]);
    }
    while (j < b.size()) {
        ans.push_back(b[j++]);
    }
    return ans;
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int>bst1;
    inorder(root1,bst1);
    vector<int>bst2;
    inorder(root2,bst2);
    
    vector<int>ans=mergettwosortedlist(bst1,bst2);
    return ans;
}


2)..but if we have to return the root of the merged bst then code is:--

void inorder(TreeNode *root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}
vector<int> mergettwosortedlist(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans.push_back(a[i++]);
        } else {
            ans.push_back(b[j++]);
        }
    }
    while (i < a.size()) {
        ans.push_back(a[i++]);
    }
    while (j < b.size()) {
        ans.push_back(b[j++]);
    }
    return ans;
}

TreeNode* inordertobst(int s,int e,vector<int>&in){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode* root=new TreeNode(in[mid]);
    root->left=inordertobst(s,mid-1,in);
    root->right=inordertobst(mid+1,e,in);
    return root;
}
TreeNode* mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    // to pahle dono bst ka inorder store kra liya
    vector<int>bst1;
    inorder(root1,bst1);
    vector<int>bst2;
    inorder(root2,bst2);


    // then dono ke inorder ko sort kr liya
    vector<int>ans=mergettwosortedlist(bst1,bst2);
    int s=0;
    int end=ans.size()-1;
    // then dono ke mergedinorder se tree create kr liya
    return inordertobst(s,end,ans);
}

t.c:-O(m+n) 
s.c:-O(m+n) where m and n is the size of both bst vector storing inorder




2nd approach using doubly linked list
void converIntoSortedDLL(TreeNode* root,TreeNode *&head){
    //base case
    if(root==NULL){
        return NULL;
    }

    converIntoSortedDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    converIntoSortedDLL(root->left,head);
}

TreeNode* mergeLinkedList(TreeNode* head1,TreeNode* head2){
    TreeNode *head=NULL;
    TreeNode *tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head1=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head1;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
               tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
    }
    while(head2!=NULL){
                tail->right=head2;
                head2->left=tail;
                tail=head1;
                head2=head2->right;
    }
    return head;
}

int countNodes(TreeNode* head){
    int count=0;
    TreeNode* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->right;
    }
    return count;
}

TreeNode *sortedLLTOBST(TreeNode* &head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    TreeNode *left=sortedLLTOBST(head,n/2);
    TreeNode *root=head;

    head=head->next;

    root->right=sortedLLTOBST(head,n-n/2-1);
    return root;
}
TreeNode* mergeBST(TreeNode *root1, TreeNode *root2)
{
    

    TreeNode *head1=NULL;
    converIntoSortedDLL(root1,head1);
    head1->left=NULL;

    TreeNode *head2=NULL;
    converIntoSortedDLL(root1,head2);
    head2->left=NULL;

    // merge sorted linked list
    TreeNode *head=mergeLinkedList(head1,head2);

    //convert singly LL into BST
    return sortedLLTOBST(head,countNodes(head));
    
}
t.c:-O(m+n)
s.c:-O(h) where h is the height of the tree
