void solve(TreeNode *root,TreeNode* &prev){
    if(root==NULL) return;

    solve(root->left,prev);

    root->left=NULL;
    prev->right=root;
    prev=root;

    solve(root->right,prev);
}
TreeNode* flatten(TreeNode *root){
    TreeNode *dummy=new TreeNode(-1);
    TreeNode *prev=dummy;

    solve(root,prev);

    return dummy->right;
}

TreeNode* mergesortelist(TreeNode *root1,TreeNode *root2){
    TreeNode *dummy=new TreeNode(-1);
    TreeNode *ans=dummy;

    TreeNode *a=root1;
    TreeNode *b=root2;

    while(a!=NULL and b!=NULL){
        if(a->data<b->data){
            ans->right=a;
            ans=a;
            a=a->right;
        }
        else{
            ans->right=b;
            ans=b;
            b=b->right;
        }
    }

    while(a!=NULL){
        ans->right=a;
        ans=a;
        a=a->right;
    }

    while(b!=NULL){
        ans->right=b;
        ans=b;
        b=b->right;
    }
    

    TreeNode *root=dummy->right;
    dummy->right=NULL;
    delete dummy;
    return root;
}

// TreeNode* sortedlisttobst(TreeNode* start,TreeNode* end){
//         if(start==end) return NULL;

//         TreeNode* slow=start;
//         TreeNode* fast=start;

//         while(fast!=end and fast->right!=end){  //end ke equal check kiya why ? because in other part of list fast will never reach NULL alright 
//             slow=slow->right;
//             fast=fast->right->right;
//         }

//         TreeNode *newnode=new TreeNode(slow->data);

//         newnode->left=sortedlisttobst(start,slow);
//         newnode->right=sortedlisttobst(slow->right,end);

//         return newnode;
//     }


TreeNode* sortedlisttobst(TreeNode* &head,int n){
    if(n<=0 or head==NULL) return NULL;

    TreeNode *left=sortedlisttobst(head,n/2);

    TreeNode *root=new TreeNode(head->data);
    root->left=left;

    head=head->right;
    root->right=sortedlisttobst(head,n-n/2-1);
    return root;
}

    void inorder(TreeNode *root,vector<int>&v){
        if(root==NULL) return;

        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }

    int nodes(TreeNode *root){
        int cnt=0;
        TreeNode *temp=root;
        while(temp!=NULL){
            cnt++;
            temp=temp->right;
        }
        return cnt;
    }

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    root1=flatten(root1);
    root2=flatten(root2);

    TreeNode *root=mergesortelist(root1,root2);

    int n=nodes(root);
    root=sortedlisttobst(root,n);
    

    vector<int>ans;
    inorder(root,ans);
    return ans;
}


baki sab to kr loge bs ye 2 code yad rkna of converting sorted list to bst ek to inorder store kra ke bst bna skte ho right but 
ye 2 code yad rkhna
