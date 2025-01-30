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

node* preorder(node *root){
	if(root==NULL){
		return NULL;
	}

  //to yha only given tree me jo leaf hai unhe hi delete kro unke delete hone ke turant bad return ho rhe so new leaf node delete nhi hogi is case me
  //to aapka tree empty nhi hoga jo aap soch rhe the okk

	if(root->left==NULL and root->right==NULL){
		delete root;
		return NULL;
	}

	root->left=preorder(root->left);
	root->right=preorder(root->right);

	

	return root;
}

void Preorder(node *root){
	if(root==NULL){
		return;
	}

	if(root->left) cout<<root->left->data<<" => ";
	else cout<<"END => ";

	cout<<root->data;

	if(root->right) cout<<" <= "<<root->right->data;
	else cout<<" <= END ";
	cout<<endl;

	Preorder(root->left);
	Preorder(root->right);

}


int main(){
	node *root;
	root=buildTree();
	root=preorder(root);
	Preorder(root);
	cout<<endl;
}
