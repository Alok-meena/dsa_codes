Given a binary tree and a node data called target.
Find the minimum time required to burn the complete binary tree if the target is set on fire.
It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.



class Solution {
    private:
    Node *createNodetoparentmapping(Node *root,int target,map<Node*,Node*>&nodetoparent){
        Node *res=NULL;// to initially result ko NULL man liya
        
        queue<Node*>q;// ye kiya basically to do level order traversal
        q.push(root);
        nodetoparent[root]=NULL;// root ka parent to null hi hoga 
        
        while(!q.empty()){
            Node *frontnode=q.front();
            q.pop();
            
            if(frontnode->data==target){// to ye kiya add to store the target node
                res=frontnode;
            }
            if(frontnode->left){ // aor bs ager left not null hai to nodetoparent ke node me parent node ko map kr lo same for right aor sath me queue me push bhi kro
                nodetoparent[frontnode->left]=frontnode;
                q.push(frontnode->left);
            }
            if(frontnode->right){
                nodetoparent[frontnode->right]=frontnode;
                q.push(frontnode->right);
            }
            
        }
        return res;
    }
    
    int burntree(Node* root,map<Node*,Node*>&nodetoparent){
        map<Node*,bool>visited;// ye bnaya to check ki already burnt or not or visited or not
        queue<Node*>q;
        q.push(root);
        
        visited[root]=true;// to hmne target node ko root name se liya and ye to already visited hoga 
        int ans=0;// initially ans 0 le liya
        
        while(!q.empty()){
            bool flag=0;// ye hai ki ager koi bhi node ka addition hua ho queue ke ander to add time to +1 second
            int size=q.size();// aor size le li taki sbhi nodes ke left right aor root ko access kr ske
            
            
            for(int i=0;i<size;i++){
                Node *front=q.front();
                q.pop();// pop kr rhe means already traversed and all nodes connected to it are burnt
                
                if(front->left && !visited[front->left]){// to ager left part not null hai and not visited bhi to flag=1 because queue me add krenge
                    // and visited ko true kr diya same for right
                    flag=1;
                    q.push(front->left);
                    visited[front->left]=1;
                }
                if(front->right && !visited[front->right]){
                    flag=1;
                    q.push(front->right);
                    visited[front->right]=1;
                }
                if(nodetoparent[front] && !visited[nodetoparent[front]]){
                    flag=1;// ye kam parent node ke liye bhi kr diya jo ki map se nodeto parent se mil jayegi
                    q.push(nodetoparent[front]);
                    visited[nodetoparent[front]]=1;
                }
                
            }
            if(flag==1){
                ans++;
            }
        }
        return ans;
    }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>nodetoparent;// to sbse pahle node to parent ka map bna liya 
        Node *targetnode=createNodetoparentmapping(root,target,nodetoparent);// then ye map bhi create krega aor target node ko return bhi krega jo
        // hm burntree function me bhej denge
        int time=burntree(targetnode,nodetoparent);// to burn tree me targetnode aor node toparent map pass kr diya
        return time;
    }
};

 Time Complexity: O(N) // O(N) for levelorder traversal + O(N) for burn tree + ) =O(N) if insertion in map is O(1) and if logn then is is O(NlogN)
 Auxiliary Space: O(n) for map



code that i coded is ::::


class Solution {
  public:
  
    Node* findnode(Node *root,int target,map<Node*,Node*>&nodetoParent){
        queue<Node*>q;
        
        Node *res;
        
        q.push(root);
        nodetoParent[root]=NULL;
        
        while(!q.empty()){
            
            Node *front=q.front();
            q.pop();
            
            if(front->data==target) res=front;
            
            if(front->left){
                nodetoParent[front->left]=front;
                q.push(front->left);
            }
            
            if(front->right){
                nodetoParent[front->right]=front;
                q.push(front->right);
            }
        }
        
        return res;
    }
    
    int burnTree(Node *root,Node *target,map<Node*,Node*>&nodetoParent){
        queue<Node*>q;
        q.push(target);
        
        map<Node*,bool>visited;
        visited[target]=true;
        
        int time=0;
        
        while(!q.empty()){
            int size=q.size();
            bool addition=false;
            
            for(int i=0;i<size;i++){
                Node *temp=q.front();
                q.pop();
                
                if(temp->left and !visited[temp->left]){
                    visited[temp->left]=true;
                    q.push(temp->left);
                    addition=true;
                }
                
                if(temp->right and !visited[temp->right]){
                    visited[temp->right]=true;
                    q.push(temp->right);
                    addition=true;
                }
                
                if(nodetoParent[temp] and !visited[nodetoParent[temp]]){
                    visited[nodetoParent[temp]]=true;
                    q.push(nodetoParent[temp]);
                    addition=true;
                }
            }
            
            if(addition) time++;
        }
        
        return time;
    }
    int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*>nodetoParent;
        
        Node *tar=findnode(root,target,nodetoParent);
        
        int ans=burnTree(root,tar,nodetoParent);
        
        return ans;
    }
};

using dfs we can do like this : ---
          

class Solution {
  public:
    // Function to set parent pointers using DFS
void setParent(Node* root, unordered_map<Node*, Node*>& nodeToParent) {
    if (!root) return;
    
    if (root->left) {
        nodeToParent[root->left] = root;
        setParent(root->left, nodeToParent);
    }
    
    if (root->right) {
        nodeToParent[root->right] = root;
        setParent(root->right, nodeToParent);
    }
}

// Function to find the target node using DFS
Node* findTarget(Node* root, int target) {
    if (!root) return NULL;
    
    if (root->data == target) return root;
    
    Node* leftSearch = findTarget(root->left, target);
    if (leftSearch) return leftSearch;
    
    return findTarget(root->right, target);
}

    int burnTree(Node *root,unordered_map<Node*,Node*>nodetoParent,Node *target){
        queue<Node*>q;
        q.push(target);
        
        unordered_map<Node*,bool>visited;
        visited[target]=true;
        
        bool addition;
        int time=0;
        
        while(!q.empty()){
            addition=false;
            int size=q.size();

            for(int i=0;i<size;i++){
                Node *front=q.front();
                q.pop();
                
                
                if(front->left and !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                    addition=true;
                }
                
                if(front->right and !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                    addition=true;
                }
                
                if(nodetoParent[front] and !visited[nodetoParent[front]]){
                    q.push(nodetoParent[front]);
                    visited[nodetoParent[front]]=true;
                    addition=true;
                }
                
            }
            
            if(addition) time++;
        }
        
        return time;
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*>nodetoParent;
        setParent(root,nodetoParent);
        
        Node *tar=findTarget(root,target);
        
        return burnTree(root,nodetoParent,tar);
    }
};


