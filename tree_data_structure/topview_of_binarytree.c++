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
