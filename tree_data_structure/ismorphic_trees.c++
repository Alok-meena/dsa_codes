Isomorphic Trees
Difficulty: MediumAccuracy: 49.11%Submissions: 112K+Points: 4Average Time: 20m
Given two Binary Trees. Check whether they are Isomorphic or not.

Note: 
Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
ISomorphicTrees

Examples:

Input: root1[] = [1, 2, 3, 4, 5, 7, 6, N, 7, 8], root2[] = [1, 3, 2, N, 6, 4, 5, 8, 7]

ISomorphicTrees
Output: true
Input: root1[] = [1, 2, 3, 4], root2[] = [1, 3, 2, 4]
     1            1  
    / \          /    \  
  2    3      3       2  
 /           /  
4          4
Output: false
Input: root1[] = [1, 2, 3, 4], root2[] = [1, 3, 2, N, N, N, 4]

     1           1
    /  \         /   \
   2    3      3     2
  /                    \
 4                        4
Output: true
Constraints:
1<=number of nodes<=105
1<= node->data <=105




t.c:-O(n) and s.c:-O(h)



class Solution {
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2) {
        // add code here.
        if(root1==NULL and root2==NULL) return true;
        if(!root1 or !root2) return false;
        
        if(root1->data!=root2->data) return false;
        
        bool c1=isIsomorphic(root1->left,root2->left) and isIsomorphic(root1->right,root2->right);
        bool c2=isIsomorphic(root1->right,root2->left) and isIsomorphic(root1->left,root2->right);
        
        return c1 or c2;
    }
};

khuch nhi hai 4 case hai 
