void reverse_levelordertraversal(node *root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    vector<vector<int>>v;
    vector<int>c;


    while(!q.empty()){
        node *front=q.front();
        q.pop();

        if(front==NULL){
            v.push_back(c);
            c.clear();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            c.push_back(front->data);

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }

    reverse(v.begin(),v.end());

    for(auto i:v){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}





2nd approach :

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
