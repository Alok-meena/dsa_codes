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
          ans.push_back(root->data);//ye pe ans uper se niche k order me chahihe that's why we did used it here
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

          //pahle right because we want right part but if does not exist then go to the left part as we want all boundary values 
          if(root->right){
              righttraversal(root->right,ans);
          }
          else{
              righttraversal(root->left,ans);
          }
          //aor ager vapas aa gye to ans ko store kr lo
          
          ans.push_back(root->data); //ye ans hme reverse order me chahihe that's why return kr rhe hai jab ans dal rhe hai 
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


Expected Time Complexity: O(N). ( O(n)+O(n)+O(n) )
Expected Auxiliary Space: O(Height of the Tree).


2nd time


/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverseleft(Node* root,vector<int>&ans){
        if(root==NULL) return;
        
        if(root->left==NULL and root->right==NULL) return;
        
        ans.push_back(root->data);
        
        if(root->left) traverseleft(root->left,ans);
        else traverseleft(root->right,ans);
    }
    
    void traverseleaf(Node* root,vector<int>&ans){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
    }
    
    void traverseright(Node* root,vector<int>&ans){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL) return;
        
        if(root->right) traverseright(root->right,ans);
        else traverseright(root->left,ans);
        
        ans.push_back(root->data); //ye hame reverse order me chahihe tha to last me pahle gye then vapas jate time push kr diya ans ko
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        
        if(root==NULL) return ans;
        
        ans.push_back(root->data);
        
        //left nodes
        traverseleft(root->left,ans);
        
        //leaf nodes
        //left subtree
        traverseleaf(root->left,ans);
        
        //right subtree
        traverseleaf(root->right,ans);
        
        //right nodes
        traverseright(root->right,ans);
        
        return ans;
    }
};

sbse bdi bat to leftsubtree and right ke liye alg se call krna for leaf nodes nhi to root node 2 bar print ho jayega alright
