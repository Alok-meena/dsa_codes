Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

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
             ans.second=2*root->data;// are bhai hme uper niche ka total sum bhejna hai yad rkha kro ye cheez
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
