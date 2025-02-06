Replace with Sum of greater nodes
Medium
Difficulty
2
Submissions
100
Max Points
Status: Contest Over

0/100 Points
Problem
Submissions
Leaderboard
Discuss
Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. Include the current node's data also.


Input Format
The first line contains a number n showing the length of the inorder array of BST. The next line contains n integers denoting the elements of the array.


Constraints
2 ≤ N ≤ 10^3


Output Format
Print the preorder traversal of the new tree.


Sample Input
7
20 
30 
40 
50 
60 
70 
80
Sample Output
260 330 350 300 150 210 80
Explanation
The original tree looks like

            50             
        /        \                
      30          70
    /    \       /   \ 
  20    40      60    80
We are supposed to replace the elements by the sum of elements larger than it.
80 being the largest element remains unaffected .
70 being the second largest element gets updated to 150 (70+80)
60 becomes 210 (60 + 70 + 80)
50 becomes 260 (50 + 60 + 70 + 80)
40 becomes 300 (40 + 50 + 60 + 70 + 80)
30 becomes 330 (30 + 40 + 50 + 60 + 70 + 80)
20 becomes 350 (20 + 30 + 40 + 50 + 60 + 70 + 80)

The new tree looks like

           260             
        /        \                
     330         150
    /    \       /   \ 
  350    300   210    80
The Pre-Order traversal (Root->Left->Right) looks like :
260 330 350 300 150 210 80.




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

node* createbst(vector<int>&in,int low,int high){
	if(low>high) return NULL;

	int mid=(low+high)/2;

	node *root=new node(in[mid]);

	root->left=createbst(in,low,mid-1);
	root->right=createbst(in,mid+1,high);

	return root;
}

void preorder(node* &root,int &sum){
	if(root==NULL) return;

	preorder(root->right,sum); //to hame largest value ko change nhi krna to vo to vese bhi nhi hogi as we are just replacing it with itself as our sum is 0 currently
  //alright 
  //and we have to modify root after coming from right subtree o/w it will not work

  //u will understand after one dry run 

	sum+=root->data;
	root->data=sum;

	preorder(root->left,sum);


}

void preorderTraversal(node *root){
	if(root==NULL) return;

	cout<<root->data<<" ";

	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
int main() {
	int n;
	cin>>n;

	vector<int>in(n);

	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		in[i]=val;
	}

	node *root=createbst(in,0,n-1);

	int sum=0;

	preorder(root,sum);

	preorderTraversal(root);

	return 0;
}

t.c:- O(n) and s.c:-O(H)
