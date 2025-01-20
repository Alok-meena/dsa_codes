Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.


t.c:-O(3N) == O(n) and s.c:(2n)==O(n)

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<vector<int>>ans;
        vector<int>v;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        int i=0;
        
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
            
            if(temp==NULL){
                if(i%2!=0) reverse(v.begin(),v.end());
                ans.push_back(v);
                v.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
                i++;
            }
            else{
                v.push_back(temp->data);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        
        v.clear();
        for(auto i:ans){
            for(auto j:i){
                v.push_back(j);
            }
        }
        
        return v;
    }
};

in the below solution we just removed this overhead

Example 1:

Input:
        1
      /   \
     2    3
    / \    /   \
   4   5 6   7
Output:
1 3 2 4 5 6 7


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>result;//to store the final result
    	if(root==NULL){
    	    return result;
    	}
    	queue<Node*>q;
    	q.push(root);
    	
    	bool lefttoright=true;// ye use kiya mtlb pahle ke liye true to normal left to right traversal in level order then aage false kr denge to reverse 
            //me right to left traversal hoga
    	
    	while(!q.empty()){
    	    int size=q.size();
    	     
    	    vector<int>ans(size);//ans ko size dena jruri h because isme hm data dal rhe hbar bar har ek level ka then isme se hm result me dal rhe aage
    	    //Level Process

    	    for(int i=0;i<size;i++){
    	        Node *frontnode=q.front();
    	        q.pop();
    	         //normal insert or reverse insert 

    	        int index=lefttoright?i:size-i-1; /// vhi mtlb ki ager lefttoright true then i only in left ot right ow in reverse order
    	        ans[index]=frontnode->data;//fir answer me dal diya
    	        
    	        if(frontnode->left){
    	            q.push(frontnode->left);
    	        }
    	        if(frontnode->right){
    	            q.push(frontnode->right);
    	        }
    	    }
    	     //direction change karni h

    	    lefttoright=!lefttoright;
    	    for(auto i:ans){
    	        result.push_back(i);//result.push_back(i): This line adds each element i from the ans vector to the result vector using the push_back function.
    	    }//auto i: This syntax is a range-based for loop in C++, where auto is used to automatically infer the type of elements in ans
                ///very imp that if we have to append the entire ans vector in result then we have to return vector<vector<int>> here we dont have to return 
                //vector of vector that's why we push one by one
    	}
    	return result;
    }
};



Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

similar code diff datastructure

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	queue<Node*>q;
    	q.push(root);
    	int level=0;
    	

    	while(!q.empty()){
    	    vector<int>ele;
    	    queue<Node*>nq;
    	    
    	    while(q.size()){
    	        Node *temp=q.front();
    	        q.pop();
    	        
    	        ele.push_back(temp->data);
    	        
    	        if(temp->left) nq.push(temp->left);
    	        if(temp->right) nq.push(temp->right);
    	    }
    	    
    	    q=nq;
    	    
    	    if(level%2!=0) reverse(ele.begin(),ele.end());
    	    
    	    for(auto i:ele){
    	        ans.push_back(i);
    	    }
    	    
    	    level++;
    	}
    	
    	return ans;
    }
};


in the same queue

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	queue<Node*>q;
    	q.push(root);
    	int level=0;
    	

    	while(!q.empty()){
    	    vector<int>ele;
    	    int size=q.size();
    	    
    	    while(size--){
    	        Node *temp=q.front();
    	        q.pop();
    	        
    	        ele.push_back(temp->data);
    	        
    	        if(temp->left) q.push(temp->left);
    	        if(temp->right) q.push(temp->right);
    	    }
    	    
    	   // q=nq;
    	    
    	    if(level%2!=0) reverse(ele.begin(),ele.end());
    	    
    	    for(auto i:ele){
    	        ans.push_back(i);
    	    }
    	    
    	    level++;
    	}
    	
    	return ans;
    }
};
