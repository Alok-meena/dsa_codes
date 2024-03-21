Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

means all the elements at the boundary

class Solution {
    private:
      void lefttraversal(Node *root,vector<int>&ans){
          if((root==NULL) || (root->left==NULL && root->right==NULL)){
              return ;
          }
          ans.push_back(root->data);
          if(root->left){
              lefttraversal(root->left,ans);
          }
          else{
              lefttraversal(root->right,ans);
          }
      }
      
      void leaftraversal(Node *root,vector<int>&ans){
          if(root==NULL){
              return;
          }
          if(root->left==NULL && root->right==NULL){
              ans.push_back(root->data);
              return;
          }
          
          leaftraversal(root->left,ans);
          leaftraversal(root->right,ans);
      }
      
      void righttraversal(Node *root,vector<int>&ans){
          if((root==NULL) || (root->left==NULL && root->right==NULL)){
              return ;
          }
          if(root->right){
              righttraversal(root->right,ans);
          }
          else{
              righttraversal(root->left,ans);
          }
          //aor ager vapas aa gye to ans ko store kr lo
          
          ans.push_back(root->data);
      }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data); // tree ke root ki value store krayi then baki functions me left or right subtree ki roots hai vo na ki ye vali
        lefttraversal(root->left,ans);//ye only left elements ke liye h 
        
        leaftraversal(root->left,ans); // to jb call kiya pahle left subtree ke liye then isme left aor right ko function sambhal lega
        leaftraversal(root->right,ans);// then right subtree isme bhi function sambhal lega
        
        righttraversal(root->right,ans);// then right most elements at boundary ko print krne ke liye  ye function
        
        return ans;
    }
};
