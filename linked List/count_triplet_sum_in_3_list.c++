Triplet from three linked lists
Medium
Difficulty
2
Submissions
100
Max Points
Status: Accepted

100/100 Points
Problem
Submissions
Leaderboard
Discuss
Given three linked lists, say a, b and c, find one node from each list such that the sum of the values of the nodes is equal to a given number say, Target. As any number of answers can be possible return the first one you get while traversing.


Input Format
The First Line contains 3 Integers n, m and k as the Size of the Three LinedLists. Next 3 Lines contains n, m and k integers Respectively as the elements of Linked Lists. Next Line contains the an Integer as Target.


Constraints
The Size of the Lists can be different.


Output Format
Display the 3 elements from each of the Lists whose sum is equals to the target separated by space.


Sample Input
3 3 3
12 6 29
23 5 8
90 20 59
101
Sample Output
6 5 90
Explanation
In the Given Sample Input, 6, 5 and 90 from lists 1, 2 and 3 respectively add to give 101.


#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	  int data;
	  node *next;

	  node(int data){
		  this->data=data;
		  this->next=NULL;
	  }
};

void insertattail(node* &head,node* &tail,int data){
	node *temp=new node(data);
	if(tail==NULL){
		head=temp;
		tail=temp;
	}
	else{
		tail->next=temp;
		tail=temp;
	}
}

void print(node *head){
	node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void solve(node *a,node *b,node *c,int target,vector<int>&ans){
	node *x=a;
	bool found=false;

	while(x!=NULL){
		int rem1=target-x->data;
		node *y=b;

		while(y!=NULL){
			int rem2=rem1-y->data;
			node *z=c;

			while(z!=NULL){
				if(z->data==rem2){
					ans.push_back(z->data);
					found=true;
					break;
				}
				z=z->next;
			}

			if(found){
				ans.push_back(y->data);
				break;
			}
			y=y->next;
		}

		if(found){
			ans.push_back(x->data);
			break;
		}
		x=x->next;

	}
}
int main() {
    int n,m,k;
	cin>>n>>m>>k;

	node *h1=NULL,*h2=NULL,*h3=NULL;
	node *t1=NULL,*t2=NULL,*t3=NULL;

	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		insertattail(h1,t1,val);
	}
	for(int i=0;i<m;i++){
		int val;
		cin>>val;
		insertattail(h2,t2,val);
	}
	for(int i=0;i<k;i++){
		int val;
		cin>>val;
		insertattail(h3,t3,val);
	}

	int target;
	cin>>target;

	vector<int>ans;
	solve(h1,h2,h3,target,ans);
	reverse(ans.begin(),ans.end());
	for(auto i:ans){
		cout<<i<<" ";
	}
	cout<<endl;
}

t.c:-O(n*m*n) and s.c:O(1)


  optimized

#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	  int data;
	  node *next;

	  node(int data){
		  this->data=data;
		  this->next=NULL;
	  }
};

void insertattail(node* &head,node* &tail,int data){
	node *temp=new node(data);
	if(tail==NULL){
		head=temp;
		tail=temp;
	}
	else{
		tail->next=temp;
		tail=temp;
	}
}

void print(node *head){
	node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void solve(node *a,node *b,node *c,int target,vector<int>&ans){
	node *x=a;
	bool found=false;

	node *z=c;
	set<int>s;
	while(z!=NULL){
		s.insert(z->data);
		z=z->next;
	}

	while(x!=NULL){
		int rem=target-x->data;
		node *y=b;

		while(y!=NULL){
			int rem2=rem-y->data;
			if(s.find(rem2)!=s.end()){
				ans.push_back(x->data);
				ans.push_back(y->data);
				ans.push_back(rem2);
				found=true;
				break;
			}
			y=y->next;
		}

		if(found) break;
		x=x->next;

	}
}
int main() {
    int n,m,k;
	cin>>n>>m>>k;

	node *h1=NULL,*h2=NULL,*h3=NULL;
	node *t1=NULL,*t2=NULL,*t3=NULL;

	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		insertattail(h1,t1,val);
	}
	for(int i=0;i<m;i++){
		int val;
		cin>>val;
		insertattail(h2,t2,val);
	}
	for(int i=0;i<k;i++){
		int val;
		cin>>val;
		insertattail(h3,t3,val);
	}

	int target;
	cin>>target;

	vector<int>ans;
	solve(h1,h2,h3,target,ans);
	for(auto i:ans){
		cout<<i<<" ";
	}
	cout<<endl;
}

t.c:-O(n*m*log(k)) and s.c:-O(k)
