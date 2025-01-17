class Solution {
  public:
    // Function to return the level order traversal of a tree.
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        vector<vector<int>>ans;
        vector<int>k;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
    
        // q.push(root);
    
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
    
            if(temp==NULL){
                ans.push_back(k);
                k.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                k.push_back(temp->data);
                if(temp->left){
                    q.push(temp->left);
                }
                
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};

reverse_level_order_traversal

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
         vector<vector<int>>ans;
        vector<int>k;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
    
        // q.push(root);
    
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
    
            if(temp==NULL){
                ans.push_back(k);
                k.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                k.push_back(temp->data);
                if(temp->left){
                    q.push(temp->left);
                }
                
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        
        vector<int>rev;
        int n=ans.size();
        
        for(int i=n-1;i>=0;i--){
            for(auto j:ans[i]){
                rev.push_back(j);
            }
        }
        
        return rev;
    }
};


3rd approach :

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        if (!root) return {};

        vector<int> result;
        queue<Node*> q;
        stack<int> s;

        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            // Push the node data into the stack
            s.push(node->data);

            // Enqueue left and right children
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }

        // Pop all elements from the stack and store them in the result vector
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }

        return result;
    }
};

this is the best approach dry run and u will understand
so if we first go to the right and push it's data then we will get the data in correct reverse level order okkk
