Brute-Force Approach
Note that the inorder traversal of a BST is always sorted.
So, we can traverse the BST in an inorder manner and store the values in an array.
Then we create a new node for each element in the array, make its left child NULL and right child equal to the node containing the next element in the array.
For the last element, we make both the left and right child NULL.

Time Complexity
O(N), where ‘N’ is the number of nodes in the given BST.

 

We are traversing the BST only once to store all the values in the array after the inorder traversal.
Then, we traverse the array one more time to create the flattened list. Hence, the overall time complexity is O(N).

Space Complexity
O(N), where ‘N’ is the total number of nodes in the given BST.

 

We are storing the values of all the nodes in an array after the inorder traversal. Hence, the overall space complexity will be O(N).


brute force

void solve(TreeNode<int>* root,vector<int>&v){
    if(root==NULL) return;

    solve(root->left,v);
    v.push_back(root->data);
    solve(root->right,v);
}

void insertattail(TreeNode<int>* &head,TreeNode<int>* &tail,int val){
    TreeNode<int> *newnode=new TreeNode(val);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }

    tail->right=newnode;
    tail=newnode;
    return;
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int>in;
    solve(root,in);

    TreeNode<int>* temp=NULL;
    TreeNode<int>* tail=NULL;

    for(auto i:in){
        insertattail(temp,tail,i);
    }

    return temp;
}

or


void inorder(TreeNode<int>* root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int>in;
    inorder(root,in);

    int n=in.size();

    TreeNode<int>* newroot=new TreeNode<int>(in[0]);//root ko first sorted value de di 
    TreeNode<int>* curr=newroot;curr rkha to traverse it
    for(int i=1;i<n;i++){
        TreeNode<int>* temp=new TreeNode<int>(in[i]);//ye bnaya to enter the value
        curr->left=NULL;// then bs right ko next value pe pont krvate jao and left ko null aor current ko bhi temp pe update krte jao
        curr->right=temp;
        curr=temp;
    }

    curr->left=NULL;// at last last node ke left and right dono ko Null kr do
    curr->right=NULL;

    return newroot;
}
t.c:-O(N)
s.c:-O(N)


 instead of creating more nodes we can link the given nodes only by tis


void inorder(TreeNode<int>* curr,TreeNode<int>* &prev){
    if(curr==NULL) return ;

    inorder(curr->left,prev);

    curr->left=NULL; // ya fir prev->left=NULL ye bhi shi hai alright
    prev->right=curr;
    prev=curr;

    inorder(curr->right,prev);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    TreeNode<int>* dummy=new TreeNode(-1);
    TreeNode<int>* prev=dummy;
    
    inorder(root,prev);
    
    prev->left=NULL;
    prev->right=NULL;

    return dummy->right;
}


it is optimized code t.c:-O(n) and s.c:-O(h) but partially accept



void inorder(TreeNode<int>* root,vector<TreeNode<int>*>&ans){
    if(root==NULL) return;

    inorder(root->left,ans);
    ans.push_back(root);
    inorder(root->right,ans);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    if(root==NULL) return root;
    vector<TreeNode<int>*>in;

    inorder(root,in);

    if(in.size()==1){
        return root;
    }


    for(int i=0;i<in.size()-1;i++){
       in[i]->left=NULL;
       in[i]->right=in[i+1];
    }

    in.back()->left=NULL;
    in.back()->right=NULL;

    return in[0];
}


same t.c and s.c
  but dont know why partially accepted


ek bnde ne kiya tha ye code O(n) and s.c:-O(h)

 void makelist(TreeNode<int>* root, TreeNode<int>* &head)

{

    if(!root) return;

 

    makelist(root->right,head);

 

    root->right=head;

    head=root;

 

    makelist(root->left,head);

     root->left=NULL;

     return;

 

}

 

TreeNode<int>* flatten(TreeNode<int>* root)

{

    // Write your code here

    TreeNode<int>* head=NULL;

 

    makelist(root,head);

    return head;

    

}

bhai ye to smj nhi aaya 


now i tried using morris traversal but didnt work 

this is wrong look 

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    TreeNode<int>* curr1=root->left;
    root->left=NULL;

    TreeNode<int>* root1=NULL;
    TreeNode<int>* root2=NULL;

    while(curr1!=NULL){
        if(curr1->left){
            TreeNode<int>* temp=curr1->left;
            while(temp->right!=NULL and temp->right!=curr1){
                temp=temp->right;
            }

            if(temp->right==NULL){
                temp->right=curr1;
                curr1=curr1->left;
            }
            else{
                if(!root1) root1=temp;
                curr1->left=NULL; // if i am doing it then the links will be lost 
                curr1=curr1->right;
            }
        }
        else{
            if(curr1->right==NULL) break;
            curr1=curr1->right;
        }
    }

    curr1->right=root;

    TreeNode<int>* curr2=root->right;

    while(curr2!=NULL){
        if(curr2->left){
            TreeNode<int>* temp=curr2->left;
            while(temp->right!=NULL and temp->right!=curr2){
                temp=temp->right;
            }

            if(temp->right==NULL){
                temp->right=curr2;
                curr2=curr2->left;
            }
            else{
                if(!root2) root2=temp;
                curr2->left=NULL;
                curr2=curr2->right;
            }
        }
        else{
            curr2=curr2->right;
        }
    }

    root->right=root2;


    return root1;
}

