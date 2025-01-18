
class Solution {
  public:
    void preorder(Node *root,vector<int>&a){
        if(root==NULL){
            return ;
        }
        
        a.push_back(root->data);
        preorder(root->left,a);
        preorder(root->right,a);
    }
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        vector<int>a;
        vector<int>b;
        preorder(r1,a);
        preorder(r2,b);
        
        if(a==b) return true;
        return false;
    }
};

t.c:-O(n) and s.c:O(n)

bool isIdentical(Node *r1, Node *r2) {
        
        
        if(r1==NULL and r2==NULL){
            return true;
        }
        if((r1==NULL and r2!=NULL) or (r1!=NULL and r2==NULL)) return false;
        
        if(r1->data!=r2->data) return false;
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        
        if(left and right) return true;
        
        return false;
    }

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL){
            return true;
        }
        if(r1==NULL && r2!=NULL){
            return false;
        }
        if(r1!=NULL && r2==NULL){
            return false;
        }
        
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        
        bool value=r1->data==r2->data;
        if(left && right && value){
            return true;
        }
        else{
            return false;
        }

        
    }
}; T.C:-O(N)   and Space Complexity = O(max(h1, h2))
