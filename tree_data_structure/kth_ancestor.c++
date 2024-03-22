Given a binary tree of size  N, a node, and a positive integer k.,
Your task is to complete the function kthAncestor(), 
the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.

Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

 Time Complexity: O(N)
 Auxiliary Space: O(height)

Constraints:
1<=N<=105
1<= K <= 100
1 <= Node.data <= N




Node *solve(Node *root,int &k,int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    
    Node * leftans=solve(root->left,k,node);
    Node * rightans=solve(root->right,k,node);
    
    if(leftans!=NULL && rightans==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;// to lock the answer taki fir k-- hoke ye k<=0 na ho paye aor root hi answer me return ho
            return root;
        }
        return leftans;
    }
    
    if(rightans!=NULL && leftans==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
   Node *ans=solve(root,k,node);
   if(ans==NULL || ans->data==node){ // ager node root itself hui to answer -1 return karna pdega because hm root of the tree ke liye aor uper nhi ja skte hai
       //and we are given with condition also 1<= K <= 100 so k can't be 0
       return -1;
   }
   else{
       return ans->data;
   }
}




























approach 2: using vector 
int solve(Node *root, int k, int node, vector<int> &path){
    // base case
    if(root == NULL) return 0;
    // if node found
    if(root->data == node) return node;
    
    path.push_back(root->data);
    
    // traverse
    int left = solve(root->left, k, node, path);
    int right = solve(root->right, k, node, path);
    
    if(left == node){
        return left;
    }
    else if(right == node){
        return right;
    }
    else if(left != node){
        path.pop_back();
        return 0;
    } 
    else if(right != node){
        path.pop_back();
        return 0;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    solve(root, k, node, path);
    int response = -1;

    int size = path.size();
    for(int idx = 0; idx<=size-k; idx++){
        response = path[idx];
    }
    return response;
}
