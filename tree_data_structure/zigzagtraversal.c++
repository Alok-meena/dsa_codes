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
