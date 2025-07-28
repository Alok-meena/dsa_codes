Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4




vector<int> diagonal(Node *root)
{
   vector <int> diagonal;
   if(root==NULL) return diagonal;
   
   queue <Node *> q;
   q.push(root);
   
   while(q.empty()!=true){
       Node *temp = q.front();
       q.pop();
       
       while(temp!=NULL){
           diagonal.push_back(temp->data);//to data temp ka dalte jao
           q.push(temp->left);// queue me temp ke sbhi left ko stor krte jao
           
           temp = temp->right;// aor temp ko right me bdate jao jb tk temp NULL na ho jaye ager ho gya then queue ke front ko lo aor uspe yhi repeat kro 
           // until queue become empty
       }
   }
   return diagonal;
}

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N)

or can do like below also alright


class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        Node *curr=root;
        vector<int>ans;
        queue<Node*>q;
        
        while(root!=NULL){
            if(root!=NULL){
                if(root->left) q.push(root->left);
                ans.push_back(root->data);
                root=root->right;
                if(!q.empty() and root==NULL){
                    root=q.front();
                    q.pop();
                }
            }
        }
        
        return ans;
    }
};
