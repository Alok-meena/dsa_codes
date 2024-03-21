Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

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
    	vector<int>result;
    	if(root==NULL){
    	    return result;
    	}
    	queue<Node*>q;
    	q.push(root);
    	
    	bool lefttoright=true;
    	
    	while(!q.empty()){
    	    int size=q.size();
    	     
    	    vector<int>ans(size);
    	    //Level Process

    	    for(int i=0;i<size;i++){
    	        Node *frontnode=q.front();
    	        q.pop();
    	         //normal insert or reverse insert 

    	        int index=lefttoright?i:size-i-1;
    	        ans[index]=frontnode->data;
    	        
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
    	        result.push_back(i);
    	    }
    	}
    	return result;
    }
};



Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
