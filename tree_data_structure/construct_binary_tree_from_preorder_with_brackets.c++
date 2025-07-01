Construct Binary Tree from String with bracket representation
Difficulty: MediumAccuracy: 59.15%Submissions: 23K+Points: 4
Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the roots value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists. The integer values will be less than or equal to 10^5.

Example 1:

Input: "1(2)(3)" 
Output: 2 1 3
Explanation:
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Inorder of above tree is "2 1 3".
Example 2:

Input: "4(2(3)(1))(6(5))"
Output: 3 2 1 4 5 6
Explanation:
           4
         /   \
        2     6
       / \   / 
      3   1 5   
Your Task:
You don't need to read input or print anything. Your task is to complete the function treeFromString() which takes a string str as input parameter and returns the root node of the tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 <= |str| <= 106













good question


class Solution {
  public:
    // function to construct tree from string
    void solve(Node* &root,string &s,int &i){
        if(i>=s.length() or s[i]==')'){ //yha condition me or rkhna hi hai ex 1()(2) hua to and satisfy nhi hoga to ager closing hai to bhi i++ krke skip krke return kr do alright
            i++;
            return;
        }
        
        int sum=0;
        
        while(i<s.length() and isdigit(s[i])){
                sum*=10;
                sum+=s[i]-'0';
                i++;
            }
        
        root=new Node(sum);
        
        if(i<s.length() and s[i]=='('){ //jab pahla open bracket aaye to left subtree create kro
            i++;
            solve(root->left,s,i);
        }
        
        if(i<s.length() and s[i]=='('){ //jab doosra aaye to right subtree alright
            i++;
            solve(root->right,s,i);
        }
        
        if(i<s.length() and s[i]==')'){
            i++;
        }
    }
    Node *treeFromString(string str) {
        // code here
        int n=str.length();
        
        int i=0;
        
        Node *root=NULL;
        

        solve(root,str,i);
        
        return root;
    }
};
