User
TreeNode * minvalue(TreeNode * root){
    TreeNode * temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

TreeNode * maxvalue(TreeNode * root){
    TreeNode *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
TreeNode * search(TreeNode * root, int val) {
    if (root == NULL || root->data == val)
        return root;
    if (root->data < val)
        return search(root->right, val);
    return search(root->left, val);
}
TreeNode * inorderPredecessor(TreeNode * root, int val) {
    TreeNode * target = search(root, val);
    if (target == NULL)
        return NULL;
    if (target->left == NULL)
        return NULL; // No predecessor exists if the target has a left subtree
    return maxvalue(target->left);
}
TreeNode * inorderSuccessor(TreeNode * root, int val) {
    TreeNode * target = search(root, val);
    if (target == NULL)
        return NULL;
    if (target->right == NULL)
        return NULL;
    return minvalue(target->right); 
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key){
    TreeNode *successor = inorderSuccessor(root, key);
    TreeNode *predecessor = inorderPredecessor(root, key);

    int a = (successor != NULL) ? successor->data : -1; // Return -1 if no successor exists
    int b = (predecessor != NULL) ? predecessor->data : -1; // Return -1 if no predecessor exists

    return {b,a};
}









There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

Example 1:

Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
key = 8 Output: 
4 9 Explanation: 
In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.

class Solution
{
    private:
    Node *minvalue(Node *root){
    Node *temp=root;
    while(temp->left != NULL){
        temp=temp->left;
    }
    return temp;
}

Node *maxvalue(Node *root){
    Node *temp=root;
    while(temp->right != NULL){
        temp=temp->right;
    }
    return temp;
}

Node *search(Node *root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

Node *inorderPredecessor(Node *root, int key) {
    Node *target = search(root, key);

    if (target == NULL) {
        // If target doesn't exist, traverse the tree to find the immediate larger element
        Node *predecessor = NULL;
        Node *current = root;

        while (current != NULL) {
            if (current->key > key) {
                current = current->left;
            } else {
                predecessor = current;
                current = current->right;
            }
        }
        return predecessor;
    }

    if (target->left != NULL) {
        return maxvalue(target->left);
    }

    Node *predecessor = NULL;
    while (root != NULL) {
        if (key > root->key) {
            predecessor = root;
            root = root->right;
        } else if (key < root->key) {
            root = root->left;
        } else {
            break;
        }
    }
    return predecessor;
}

Node *inorderSuccessor(Node *root, int key) {
    Node *target = search(root, key);

    if (target == NULL) {
        // If target doesn't exist, traverse the tree to find the immediate smaller element
        Node *successor = NULL;
        Node *current = root;

        while (current != NULL) {
            if (current->key < key) {
                current = current->right;
            } else {
                successor = current;
                current = current->left;
            }
        }
        return successor;
    }

    if (target->right != NULL) {
        return minvalue(target->right);
    }

    Node *successor = NULL;
    while (root != NULL) {
        if (key < root->key) {
            successor = root;
            root = root->left;
        } else if (key > root->key) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre=inorderPredecessor(root,key);
        suc=inorderSuccessor(root,key);
    }
};

 Time Complexity: O(Height of the BST).
 Auxiliary Space: O(Height of the BST).
