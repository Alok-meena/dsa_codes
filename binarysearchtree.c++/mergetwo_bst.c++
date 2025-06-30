brute force t.c:-O(n1+n2 log (n1+n2)) and s.c:-O(n1+n2)


void inorder(TreeNode *root,vector<int>&ans){
    if(root==NULL) return ;

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int>ans;

    inorder(root1,ans);
    inorder(root2,ans);

    sort(ans.begin(),ans.end());
    return ans;
}

okkk


and now other solutions




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



t.c:-O(n1+n2) and s.c:-O(n1+n2)

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

t.c:-O(m+n) as it is not mergetsort okkk the vertors are already sorted and we just have to merge them okk
s.c:-O(m+n) where m and n is the size of both bst vector storing inorder




3rd approach using doubly linked list

//bst to dll conversion using recursion
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


// mergetwo linked list
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
s.c:-O(h) where h is the height of the tree because sbhi recursions ka space complexity to height ke equal hi hoga right so we choosed it 




t.c:-O(n+m) and s.c:-O(h1+h2) 

void inorder(TreeNode* curr,TreeNode* &prev){
        if(curr==NULL) return ;
    
        inorder(curr->left,prev);
    
        prev->left=NULL;
        prev->right=curr;
        prev=curr;
    
        inorder(curr->right,prev);
    }
    TreeNode *flattenBST(TreeNode *root) {
        // code here
        TreeNode* dummy=new TreeNode(-1);
        TreeNode* prev=dummy;
        
        inorder(root,prev);
    
        return dummy->right;
    }

 TreeNode* solve(TreeNode *&a,TreeNode *&b){
        if(a->right==NULL){
            a->right=b;
            return a;
        }


        TreeNode *curr1=a;
        TreeNode *next1=curr1->right;
        TreeNode *curr2=b;
        TreeNode *next2=curr2->right;

        while(next1!=NULL and curr2!=NULL){
            if(curr2->data>=curr1->data and curr2->data<=next1->data){
                curr1->right=curr2;
                next2=curr2->right;
                curr2->right=next1;
                curr1=curr2;
                curr2=next2;
            }
            else{
                curr1=next1;
                next1=next1->right;

                if(next1==NULL){
                    curr1->right=curr2;
                    return a;
                }
            }
        }

        return a;
    }
    TreeNode* mergeTwoLists(TreeNode* list1, TreeNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        if(list1->data<=list2->data){
            return solve(list1,list2);
        }
        else{
            return solve(list2,list1);
        }
    }
    
    void inorder2(TreeNode* root,vector<int>&v){
        if(root==NULL) return;

        v.push_back(root->data);
        inorder2(root->right,v);
    }
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    root1=flattenBST(root1);
    root2=flattenBST(root2);

    TreeNode* root=mergeTwoLists(root1,root2);

    vector<int>v;
    inorder2(root,v);
    return v;
}

isme step 1: convert bst to sorted list
     step 2: merge sorted lists
     step 3: return inorder / convert inorder bst ( if converted to bst then s.c:-O(N+m) due to new nodes created alright )
