Add duplicate ( BST )
Medium
Difficulty
16
Submissions
100
Max Points
Status: Contest Over

0/100 Points
Problem
Submissions
Leaderboard
Discuss
For each node in a binary search tree, create a new duplicate node, and insert the duplicate as the left child of the original node.


Input Format
Enter the number of nodes N and add N more numbers to the BST


Constraints
None


Output Format
Display the tree


Sample Input
3
2
1
3
Sample Output
2 => 2 <= 3
1 => 2 <= END
1 => 1 <= END
END => 1 <= END
3 => 3 <=END
END => 3 <=END







i tried this but wrong for one case also takes more memory okk

#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	   int data;
	   node *left;
	   node *right;

	   node(int data){
		   this->data=data;
		   this->left=NULL;
		   this->right=NULL;
	   }

};

node* solve(vector<int>&preorder,int mini,int maxi,int &i){
	if(i>=preorder.size()) return NULL;

	if(preorder[i]<mini || preorder[i]>maxi) return NULL;

	node *root=new node(preorder[i++]);

	root->left=solve(preorder,mini,root->data,i);
	root->right=solve(preorder,root->data,maxi,i);

	return root;
}

node* createBst(vector<int>&preorder){
	int mini=INT_MIN;
	int maxi=INT_MAX;
	int i=0;
	return solve(preorder,mini,maxi,i);
}

void preorderTraversal(node *root){
	if(root==NULL) return ;
	
	if(root->left){
		cout<<root->left->data<<" => ";
	}
	else cout<<"END => ";

	cout<<root->data;

	if(root->right){
		cout<<" <= "<<root->right->data;
	}
	else cout<<" <= END";

	cout<<endl;

	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

int main() {
	int n;
	cin>>n;

	vector<int>pre(2*n);

	for(int i=0;i<2*n;i=i+2){
		int val;
		cin>>val;
		pre[i]=val;
	}


	for(int i=0;i<2*n;i=i+2){
		pre[i+1]=pre[i];
	}

	node *root=createBst(pre);

	if(root==NULL){
		cout<<"END"<<endl;
		return 0;
	}

    preorderTraversal(root);




	return 0;
}


but we just have to create the duplicate nodes in the tree itself  

#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	   int data;
	   node *left;
	   node *right;

	   node(int data){
		   this->data=data;
		   this->left=NULL;
		   this->right=NULL;
	   }

};

node* solve(vector<int>&preorder,int mini,int maxi,int &i){
	if(i>=preorder.size()) return NULL;

	if(preorder[i]<mini || preorder[i]>maxi) return NULL;

	node *root=new node(preorder[i++]);

	root->left=solve(preorder,mini,root->data,i);
	root->right=solve(preorder,root->data,maxi,i);

	return root;
}

node* createBst(vector<int>&preorder){
	int mini=INT_MIN;
	int maxi=INT_MAX;
	int i=0;
	return solve(preorder,mini,maxi,i);
}

void duplicate(node* root){
   //bs duplicate me khuch nhi kiya hai ager node null nhi hai to iski hi copy hame iske left me lgana hai right so create a node and root left 
  //will be connected to this duplicate node's left and root's left now will be this duplicate okk and when we call function for left part then call for duplicate left
  //part as it is now introduced okk o/w one node will be missed okk
	if(root==NULL) return;

	node *duplicateNode=new node(root->data);
	duplicateNode->left=root->left;
	root->left=duplicateNode;

	duplicate(duplicateNode->left);
	duplicate(root->right);
}

void preorderTraversal(node *root){
	if(root==NULL) return ;

	if(root->left){
		cout<<root->left->data<<" => ";
	}
	else cout<<"END => ";

	cout<<root->data;

	if(root->right){
		cout<<" <= "<<root->right->data;
	}
	else cout<<" <= END";

	cout<<endl;

	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

int main() {
	int n;
	cin>>n;

	vector<int>pre(n);

	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		pre[i]=val;
	}



	node *root=createBst(pre);

	duplicate(root);

    preorderTraversal(root);




	return 0;
}

t.c:-O(3N)=O(n) and s.c:O(height) worst O(n) okk
