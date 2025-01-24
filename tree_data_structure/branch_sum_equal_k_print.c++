Root to Leaf ( Binary Tree)
Medium
Difficulty
1
Submissions
100
Max Points
Status: Accepted

100/100 Points
Problem
Submissions
Leaderboard
Discuss
Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number.


Input Format
First line contains the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL. Second line contains the number k.


Constraints
None


Output Format
Display the root to leaf path whose sum is equal to k.


Sample Input
10 true 20 true 30 false false true 50 false false true 40 true 60 false false true 73 false false
60
Sample Output
10 20 30
Explanation
The given tree is in pre order traversal. So convert it into binary tree and check root to leaf path sum.



#include <bits/stdc++.h>
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

node* buildTree(){
	int data;
	cin>>data;

	node *root=new node(data);

	string l,r;
	cin>>l;

	if(l=="true"){
		root->left=buildTree();
	}

	cin>>r;
	if(r=="true"){
		root->right=buildTree();
	}

	return root;

}

void preorder(node *root,vector<int>&v,int k,int &sum){
	if(root==NULL){
		return;
	}
	
	
	sum+=root->data;
	v.push_back(root->data);

  //and this sum thing we have to check here only if reached leaf node and if the branch sum is equal to k then do print it
	
	if(root->left==NULL and root->right==NULL and sum==k){
		for(auto i:v){
			cout<<i<<" ";
		}
		return;
	}

	preorder(root->left,v,k,sum);
	// v.pop_back();
	// sum-=root->data;
	preorder(root->right,v,k,sum);

  //very imp ki left bhi dekh liya right bhi dekh liya puri branch ka leaf tk then vapas jate time sum ko decrease kro and vector me se ans ko nikalo right

	sum-=root->daa;
	v.pop_back();
}


int main(){
	node *root;
	vector<int>v;
	root=buildTree();
	int k;
	cin>>k;
	int sum=0;
	preorder(root,v,k,sum);
}
