Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

             1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 



brute force

class Solution {
  public:
    void preorder(Node *root,int x,map<int,vector<int>>&mapping){
        if(root==NULL) return;
        
        mapping[x].push_back(root->data);
        
        preorder(root->left,x-1,mapping);
        preorder(root->right,x+1,mapping);
    }
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        map<int,vector<int>>mapping;
        
        int x=0;
        
        preorder(root,x,mapping);
        
        vector<vector<int>>ans;
        
        for(auto i:mapping){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};


bhai ye to bilkul galat hai because basis hi hmara x aor level hai 




2nd try


vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        return d(root);
        map<int,vector<int>>mapping;
        
        int x=0;
        
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            Node *front=q.front().first;
            int x=q.front().second;
            q.pop();
            
            mapping[x].push_back(front->data);
            
            if(front->left) q.push({front->left,x-1});
            if(front->right) q.push({front->right,x+1});
        }
        
        
        vector<vector<int>>ans;
        
        for(auto i:mapping){
            ans.push_back(i.second);
        }
        
        return ans;
    }


ye shi hai for gfg as vha bs hme level ke according chaihhe and vo hai no sorting etc alright




aor leetcode pe kya hai x ke according to chaihhe hi but suppose x=0 pe level 1 pe 3 nodes aa rhi okk to vo sorted honi chaiahe and niche vali level ki
bad me hi ayegi  so do like below


only this is accepted at leetcode at same level should be sorted alright

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        // Your code here
        vector<vector<int>>answer;
        if(root==NULL) return answer;
        
        map<int,map<int,vector<int>>>ans; //hz dist ke corresponding ans store can use multiset also in place of vector then no sorting required 
        
        queue<pair<int,pair<int,TreeNode*>>>q;
        q.push({0,{0,root}});
        
        while(!q.empty()){
            int hz=q.front().first;
            int level=q.front().second.first;
            TreeNode *temp=q.front().second.second;
            q.pop();
            
            ans[hz][level].push_back(temp->val);
            
            if(temp->left) q.push({hz-1,{level+1,temp->left}});
            if(temp->right) q.push({hz+1,{level+1,temp->right}});
        }
        

        for(auto i:ans){
            vector<int>v;
            for(auto j:i.second){ //to i jo tha i.first me x ke corresponding hai aor values sorted chaihe to map hi use kro unordered nhi 
              //and yha j.first me level hai to same level hogi to unhe sort krke dal rhe that's it okk 
              //or can use multiset also to get all values instead of unique and sorted also at same level 
                sort(j.second.begin(),j.second.end());
                for(auto val:j.second) v.push_back(val);
            }
            answer.push_back(v);
        }
        
        return answer;
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return verticalOrder(root);
    }
};


bhai bahut imp hai acche se krna 





class solution {
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int>ans;//answer jo hai vector type ka return karna hai to bna liya
        if(root==NULL){
            return ans;
        }

        map<int,map<int,vector<int>>>nodes;// to pahla int btayega horizontal distance doosra konsi level h
        // aor then we have a list of nodes or node->data
        queue<pair<Node*,pair<int,int>>>q;// to queue ka use kiya for level order traversal jo node ke sath
        //sath pair contain krega pahla horizontal distance aor doosra level ko darshayega
        // aor queue bhi pair store kr rhi to pair lga diya
        
        //then push the fisrt node and we know that at starting level is 0 and horizontal distance hd is also 0
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            // so now hme ab hme pahle front node nikalna h;
            pair<Node*,pair<int,int>>temp=q.front();
            q.pop();//pop bhi krna pdega
            // to queue ka type leke usi type ki value jo queue me h
            // vo store kra li temp me
            Node *frontnode=temp.first;// then temp ke first me node hogi to le li
            
            int hd=temp.second.first;// and temp ke second ke first me hd and second me level
            int level=temp.second.second;
            
            nodes[hd][level].push_back(frontnode->data);//yha vector me value dal rhe isliye pushback aayega aor [hd][level] se vecetor tk pahuche h hm
            //to kya kiya hd level likha to map me vector tk pahuch gye to usme ans dal diya
            if(frontnode->left){
                q.push(make_pair(frontnode->left,make_pair(hd-1,level+1)));// to hd left left me -- hoga and level har ek level ke sath increase by 1
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,make_pair(hd+1,level+1)));//right me hd increase hoga by 1 and level same increase hogi
            }
            
        }
        for(auto i:nodes){
            for(auto j:i.second){// to we have this  map<int,map<int,vector<int>>>nodes; to i btayega ,map<int,vector<int>>>nodes ise 
                for(auto k:j.second){// then i.second ise .second btayega ise,map<int,vector<int>>>nodes 
                    ans.push_back(k);//then j.second btayega  vector<int> ko aor ise hi answer me dalenge 
                }
            }
        }
        return ans;
    }
};

Expected Time Complexity: O(N*log(m)) // due to map and m is hd distance alright
Expected Auxiliary Space: O(N)


t.c:-O(n*logm) and s.c:-O(n) due to the map and queue also
m is the unique horizonatal distance okk


