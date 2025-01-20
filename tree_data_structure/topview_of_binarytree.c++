Given below is a binary tree. The task is to print the top view of binary tree. 
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.
Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>topnode;// pahla horizontal distance btayega aor doosra node ka data
        queue<pair<Node*,int>>q;
        
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            
            Node *frontnode=temp.first;
            
            int hd=temp.second;
            
            if(topnode.find(hd)==topnode.end()){//ager topnode me value hd nhi hogi to ye pahlie entry hogi aor topnode.end() ke equal hogi ager ager
              // pahle se hogi value to fir map nhi karna hme bs yhi extra condition hai yha pe
                topnode[hd]=frontnode->data;// to topnode[hd] ka mtlb hai ki hm map me 2nd int tk pahuch gye h aor vo node ke data ki value store krega
            }
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i:topnode){
            ans.push_back(i.second);// because hme 2nd int yani node ka data ko push karna hai answer me
        }
        return ans;
        
    }

};

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).


but in reality of our code
Time Complexity: O(n)
Space Complexity: O(n)



just one change and u are done with it 

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,vector<int>>m;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty()){
            pair<Node*,int>p = q.front();
            q.pop();

            //if the distance is already present then dont add any other value corresponding to it okk
            if(m.find(p.second)==m.end()) m[p.second].push_back(p.first->data);
            
            if(p.first->left) q.push({p.first->left,p.second-1});
            if(p.first->right) q.push({p.first->right,p.second+1});
        }
        
        for(auto i:m){
            for(auto j:i.second){
                ans.push_back(j);
            }
        }
        
        return ans;
    }
};

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).


we cannot do this using dfs without more updates we can do use dfs if we manage a level and update the curr node if it's level is less than the level with same hd

like this 

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    
    // Helper function to perform DFS traversal and update the top view
    void dfs(Node* root, map<int, pair<int, int>>& m, int hd, int level) {
        // Base case: If the node is NULL, return
        if (root == NULL) {
            return;
        }
        
        // If the horizontal distance (hd) is not in the map, or if the level of the current node
        // is less than the level already recorded at that horizontal distance, update the map.
        if (m.find(hd) == m.end() || m[hd].second > level) {
            m[hd] = {root->data, level};
        }
        
        // Recur for the left and right child nodes
        dfs(root->left, m, hd - 1, level + 1);  // Move to left child, hd decreases by 1
        dfs(root->right, m, hd + 1, level + 1); // Move to right child, hd increases by 1
    }

    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        map<int, pair<int, int>> m; // Map to store node data and level for each horizontal distance
        dfs(root, m, 0, 0); // Start DFS from root with hd=0 and level=0
        
        // Extract the top view from the map (nodes are sorted by horizontal distance)
        for (auto i : m) {
            ans.push_back(i.second.first); // i.second.first contains the node's data
        }
        
        return ans;
    }
};


Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N). logn for inserting into map
