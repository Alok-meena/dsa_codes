to bhai suno normal kya krna chaihe hame har node pe jake left ki height right ki height add kro 

class Solution {
  public:
    int height(Node* root){
        //aor ager nodes ki terms me pucha ho to just 0 return kro yha pe because n nodes hai to n-1 edges hogi to ek km ke liye -1 bhej rhe the ham
        if(root==NULL) return -1; //height in terms of edges nikal rhe hai right to -1 return kiya 
        
        int left=height(root->left);
        int right=height(root->right);
        int ans=max(left,right)+1;
        return ans;
    }
    void solve(Node* root,int &maxi){
        if(root==NULL) return ;
        
        int left=height(root->left);
        int right=height(root->right);
        
        maxi=max(maxi,left+right+2); //aor jaise ham height me +1 kr rhe the longer height ki side ki ek edge ko include krne ke liye same yha dono ko krna hai
        //to +2 kiya hai alright 
        
        solve(root->left,maxi);
        solve(root->right,maxi);
    }
    int diameter(Node* root) {
        // Your code here
        int maxi=0;
        solve(root,maxi);
        return maxi;
    }
};

t.c:-O(N^2) and s.c:-O(height)


and isika optimized version


class Solution {
  public:
    pair<int,int> solve(Node* root){
        if(root==NULL) return {-1,0}; //return {0,0} if count in terms of nodes alright
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        int currheight=max(left.first,right.first)+1;
        
        int diameter=left.first+right.first+2; //yha pe left se height 2 aa rhi right se 1 to 2 add krna pdega dono taraf ke edges ko add krne ke liye alright
        //and nodes ki term me krte to just add 1 
        
        pair<int,int> ans;
        ans.first=currheight;
        ans.second=max({left.second,right.second,diameter});
        
        return ans;
    }
    int diameter(Node* root) {
        // Your code here
        return solve(root).second;
    }
};



t.c:-O(n) and s.c:-O(h) 

to bhai ye hai code jo smja hai not learnt like pahle diametr call kro then right etec isse smajo niche ese hi hai
















or written differently

to bhai suno as here we are counting no. of edges not no. of nodes so in height we have to return -1 if NULL and just +1 alright and in diameter we have to
+2 as if we have one node to left and one to right then height of left is 0 and height of right is 0 but
  1         in this two edges are included so we have to do +2 here 
2   3


o/w if we are returning 0 in height then we dont have to add anything in diameter fun as correct height will be returned alright

class Solution {
  public:
    int height(Node* root){
        if(root==NULL) return -1;
        
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        int Height=max(leftheight,rightheight)+1;
        return Height;
    }
    int diameter(Node* root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        
        int d1=diameter(root->left);
        int d2=diameter(root->right);
        
        int h1=height(root->left);
        int h2=height(root->right);
        int ans=max({d1,d2,h1+h2+2});
        
        return ans;
    }
};

#approach 2 : using pair <int,int> .... first is diameter and second value is height ..........

#include <algorithm>
class Solution {
    private:
     
    pair<int,int> diameterFast(Node *root){
        //base case
        if(root==NULL){
            pair<int,int>p=make_pair(0,0); //do make both values 0
            return p;
        }
        
        pair<int,int>left=diameterFast(root->left);// to lef vale me lef ke sare diameter aa jayenge aor same for right aor left ke second me height hogi same
        //for right
        pair<int,int>right=diameterFast(root->right);
        
        
        int a1=left.first;//getting diameter of first
        int a2=right.first;//getting diameter of second
        int a3=left.second + right.second + 1;//getting height of left and right subtree #### if no. of edges we have to calculate just remove this +1 from here
        // then adding 1 also in it to include the root node
        
        pair<int,int>ans;//then making ans to return it
        ans.first=max(a1,max(a2,a3));//same as old concept
        ans.second=max(left.second,right.second)+1; // ye hmne height bhejne ke liye kiya hai bs use nhi hui because we want diameter which we get from first
        
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        
        return diameterFast(root).first;//aor return first krvaya because first contain the diameter and second one height
    }
};

T.C:-O(N)
S.C:-O(H) H--->height of the tree


to bhai suno pichle me diameter and height dono ko alg alg calculate kr rhe the to t.c:-O(n^2) ho gyi thi alright 

to bs yha ham dono ko sath sath calculate kr rhe hai

class Solution {
  public:
    pair<int,int> solve(Node* root){
        if(root==NULL){
            return {-1,0};
        }
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        int op1=left.second;
        int op2=right.second;
        int op3=left.first+right.first+2;
        
        int ans=max({op1,op2,op3});
        
        pair<int,int>answer;
        answer.first=max(left.first,right.first)+1;
        answer.second=ans;
        
        return answer;
    }
    int diameter(Node* root) {
        // Your code here
        return solve(root).second;
    }
};

same approach ek side height and ek side diameter ka ans store kr liya hai bs to dkeho simple ans jo hai pahle jaise diameter calculate kr rhe the vese hi hai right
and first me ham normal height calculate kr rhe hai alright vhi simple max of left and right height + 1 that's it okk and store krke ans ko return kr do


and it will run if we pass 0 in case of null node height and dont add anything in op3

class Solution {
  public:
    pair<int,int> solve(Node* root){
        if(root==NULL){
            return {0,0};
        }
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        int op1=left.second;
        int op2=right.second;
        int op3=left.first+right.first;
        
        int ans=max({op1,op2,op3});
        
        pair<int,int>answer;
        answer.first=max(left.first,right.first)+1;
        answer.second=ans;
        
        return answer;
    }
    int diameter(Node* root) {
        // Your code here
        return solve(root).second;
    }
};
