Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.


brute force:

har node pe jao left aor right k sum nikalo aor dekho ki curr ke equal hai y nhi and then go on further left and right nodes that's all

class Solution {
  public:
    int findsum(Node* root){
        if(root==NULL) return 0;
        
        int left=findsum(root->left);
        int right=findsum(root->right);
        int sum=left+right+root->data;
        
        return sum;
    }
    void solve(Node* root,bool &check){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL) return;
        
        int leftsum=findsum(root->left);
        int rightsum=findsum(root->right);
        
        int sum=leftsum+rightsum;
        if(sum!=root->data) check=false;
        
        solve(root->left,check);
        solve(root->right,check);
    }
    
    bool isSumTree(Node* root) {
        // Your code here
        bool check=true;
        solve(root,check);
        return check;
    }
};

t.c:-O(n^2) and s.c:-O(h)

easy code

pair<int,bool> solve(Node* root){
        if(root==NULL) return {0,true};
        
        if(root->left==NULL and root->right==NULL){
            return {root->data,true};
        }
        
        pair<int,bool> left=solve(root->left);
        pair<int,bool> right=solve(root->right);
        
        int sum=left.first+right.first;
        bool check=(sum==root->data);
        
        pair<int,bool> ans;
        ans.first=2*sum;
        ans.second=left.second and right.second and check;
        
        return ans;
    }
    bool isSumTree(Node* root) {
        // Your code here
        return solve(root).second;
    }

t.c:-O(n) and s.c:-O(h)

TO SUNO VERY IMP KI HAM IS TREE ME ROOT KE LIYE PURE LEFT KA SUM AND PURE RIGHT KA SUM NIKAL RHE H NA KI ONLY UNKE LEFT AOR RIGHT KA SUM DHYAN RKHNA YE CHEEZ

class Solution
{
    private:
     pair<bool,int> fastanswer(Node *root){
         if(root==NULL){
             pair<bool,int>p=make_pair(true,0);
             return p;
         }
         if(root->left==NULL && root->right==NULL){
             pair<bool,int>p=make_pair(true,root->data);
             return p;
         }
         
         pair<bool,int> leftans=fastanswer(root->left); //to dhyan se  suno yha same yhi function call ho rha hai to uper jayega aor makepair(ture,koi bhi value)
       // tik h isiliye iska type pair<bool,int> rkha hai okkk
         pair<bool,int> rightans=fastanswer(root->right);
         
         bool isLeftsumtree=leftans.first;//fir jb last me pahucha to first store kr liya  ki sum tree hai ya nhi for both left and right
         bool isRightsumtree=rightans.first;
         
         int leftsum=leftans.second;// then fir sum ko sotre kr liya second valuue jo h
         int rightsum=rightans.second;
         
         bool condition=root->data==leftans.second+rightans.second;// fir condition check kri ager ye ture hoti h to niche dekho
         
         pair<bool,int>ans;
         if(isLeftsumtree && isRightsumtree && condition){
             ans.first=true;// to first ko to ture krna hi h;
             ans.second=2*root->data;// are bhai hme uper niche ka total sum bhejna hai yad rkha kro ye cheez and ye tabhi ho rha hai jab sum equal hai
         }
         else{
             ans.first=false;// ager answer false h to us case me second yani sum calculate krne ki jrurat hi nhi h
         }
         return ans;
         
     }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         return fastanswer(root).first;
    }
};


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the Tree)


class Solution {
  public:
    pair<int,bool> solve(Node* root){
        if(root==NULL){
            return {0,true};
        }
        
        pair<int,bool> left=solve(root->left);
        pair<int,bool> right=solve(root->right);
        
        int sum=left.first+right.first+root->data;
        
        int childsum=left.first+right.first;
        
        pair<int,bool> ans;
        

        if(left.second and right.second){
            if(root->left==NULL and root->right==NULL) ans.second=true;
            else if(root->data==childsum) ans.second=true;
            else ans.second=false;
            ans.first=sum;
        }
        else ans.second=false;
        
        // cout<<ans.first<<" "<<ans.second<<endl;
        
        return ans;
        
        
    }
    bool isSumTree(Node* root) {
        // Your code here
        pair<int,bool> ans=solve(root);
        // cout<<ans.first<<" "<<ans.second;
        return ans.second;
    }
}; it is written in a clumsy way
