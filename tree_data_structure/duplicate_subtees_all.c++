Duplicate Subtrees
Difficulty: MediumAccuracy: 23.98%Submissions: 64K+Points: 4
Given a binary tree, your task is to find all duplicate subtrees from the given binary tree.

Duplicate Subtree : Two trees are duplicates if they have the same structure with the same node values.

Note:  Return the root of each tree in the form of a list array & the driver code will print the tree in pre-order tree traversal in lexicographically increasing order.

Examples:

Input : 
 
Output: 2 4   
        4
Explanation: The above tree have two duplicate subtrees.i.e 
  2
 /
4  and 4. Therefore, you need to return the above tree root in the form of a list.  
Input:     5
          / \
         4   6
        / \
       3   4
          / \
         3   6
Output: 
3
6
Explanation: In the above tree, there are two duplicate subtrees.i.e
3 and 6. Therefore, you need to return the above subtrees root in the form of a list. Here, 4 3  is not considered because for a subtree to be equal, it should have the same values as well as structure. If we consider the first subtree on the left, it has  
two children, 3 on the left and 4 3 6   on the right. And for the second subtree it has 3 on the left and 6 on the right.
Since the structures are not same for the subtrees hence they are not equal
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)


simple sa code hai pahle jaisa hi jisme 2 size k duplicate dkehna tha vha leaf tha to string bna ke bhej diya alright bs yha null tk ja rhe and # bhej diya aor
leaf k mt krna and ager string pahle se hai to root ko store kr lo current root alright 


t.c:-O(n^2) and s.c:-O(n) alright



class Solution {
public:
    unordered_map<string, int> mp;
    vector<Node*> ans;

    string serialize(Node* root) {
        if (!root) return "#"; // null marker

        string s=to_string(root->data)+','+serialize(root->left)+','+serialize(root->right);

        // If this serialized subtree is seen exactly once before, it's a duplicate
        if (mp[s] == 1)
            ans.push_back(root);

        mp[s]++;
        return s;
    }

    vector<Node*> printAllDups(Node* root) {
        serialize(root);
        return ans;
    }
};
