Mirror Tree
Difficulty: EasyAccuracy: 72.67%Submissions: 214K+Points: 2
Given a binary tree, convert the binary tree to its Mirror tree.

Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.     

Examples:

Input: root[] = [1, 2, 3, N, N, 4]
Output: [1, 3, 2, N, 4]
Explanation: 

In the inverted tree, every non-leaf node has its left and right child interchanged.
Input: root[] = [1, 2, 3, 4, 5]
Output: [1, 3, 2, N, N, 5, 4]
Explanation:

In the inverted tree, every non-leaf node has its left and right child interchanged.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105





in below code we used swap function or can do manually also

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node==NULL) return;
        
        Node *temp=node->left;
        Node *t=node->right;
        node->left=t;
        node->right=temp;
        
        mirror(node->left);
        mirror(node->right);
    }
};

like above alright

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node==NULL) return;
        
        swap(node->left,node->right);
        
        mirror(node->left);
        mirror(node->right);
    }
};


t.c:- O(n) and s.c:- O(h)

Yes, when we use swap(node->left, node->right), we are swapping the pointers (addresses) to the left and right child nodes, but the actual links between the nodes remain intact. Let's break it down.


but if we have to return new mirror tree

class Solution {
  public:
    Node* createMirror(Node* root){
        if (root == NULL) return NULL;

        Node* mirror = new Node(root->data);

        mirror->left = createMirror(root->right);
        mirror->right = createMirror(root->left);

        return mirror;
    }

    Node* mirror(Node* node) {
        return createMirror(node); // returns a new mirrored root
    }
};
