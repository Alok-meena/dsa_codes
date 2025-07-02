Median of BST
Difficulty: EasyAccuracy: 27.43%Submissions: 97K+Points: 2
Given a Binary Search Tree, find the Median of its Node values.

Examples:

Input: root = [6, 3, 8, 1, 4, 7, 9]
       6
     /   \
   3      8   
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be: 1, 3, 4, 6, 7, 8, 9. So, here median will 6.
Input: root = [6, 3, 8, 1, 4, 7, N]
       6
     /   \
   3      8   
 /   \    /   
1    4   7   
Output: 5
Explanation:Inorder of Given BST will be: 1, 3, 4, 6, 7, 8. So, here median will (4 + 6)/2 = 10/2 = 5.
Input: root = [18, 16, 20, 7]
Output: 17
Constraints:
1<=n<=105




  
void inorder(struct Node* root,vector<int>&v){
        if(root==NULL) return;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
float findMedian(struct Node *root) {
    // Code here
    
    vector<int>in;
    
    inorder(root,in);
    
    int n=in.size();
    
    if(in.size()%2!=0) return in[n/2];
    
    int val1=in[n/2];
    int val2=in[(n-1)/2];
    
    return float(val1+val2)/2;
}
