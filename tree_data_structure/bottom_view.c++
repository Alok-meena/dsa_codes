Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root,
then print the later one in level traversal. For example, in the below diagram,
3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

Note: The Input/Output format and Example given are used for the system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem,
hence a user should not read any input from the stdin/console. The task is to complete the function specified, and not to write the full code.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
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
            
            topnode[hd]=frontnode->data; // bs yha change kya kiya hai ki value dalte jao aor remove hoti jayegi last me jo values updated bchegi vhi answer hoga

            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i:topnode){
            ans.push_back(i.second);
        }
        return ans;
    }
};


Expected Time Complexity: O(N*logN). // ye honi chahihe thi but hmare code ki O(N) hai 
Expected Auxiliary Space: O(N).
