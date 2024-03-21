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

class solution {
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,map<int,vector<int>>>nodes;// to pahla int btayega horizontal distance doosra konsi level h
        // aor then we have a list of nodes or node->data
        queue<pair<Node*,pair<int,int>>>q;// to queue ka use kiya for level order traversal jo node ke sath
        //sath pair contain krega pahla horizontal distance aor doosra level ko darshayega
        // aor queue bhi pair store kr rhi to pair lga diya
        
        vector<int>ans;//answer jo hai vector type ka return karna hai to bna liya
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
            
            nodes[hd][level].push_back(frontnode->data);//yha vector me value dal rhe isliye pushback aayega
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
