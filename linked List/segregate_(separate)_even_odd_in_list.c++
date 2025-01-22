Segregate even and odd nodes in a Linked List
Difficulty: MediumAccuracy: 49.8%Submissions: 89K+Points: 4
Given a link list, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be the same as that in the original list.

NOTE: Don't create a new linked list, instead rearrange the provided one.

Examples:

Input: Linked list: 17->15->8->9->2->4->6
Output: 8->2->4->6->17->15->9

Explaination: 8,2,4,6 are the even numbers so they appear first and 17,15,9 are odd numbers that appear later.
Input: Linked List: 1 -> 3 -> 5 -> 7
Output: 1->3->5->7

Explaination: There is no even number. So no need for modification.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)






#include <bits/stdc++.h>
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        queue<int>even;
        queue<int>odd;
        
        Node *temp=head;
        while(temp!=NULL){
            int d=temp->data;
            if(d%2==0) even.push(d);
            else odd.push(d);
            temp=temp->next;
        }
        temp=head;
        while(!even.empty()){
            temp->data=even.front();
            temp=temp->next;
            even.pop();
        }
        
        while(!odd.empty()){
            temp->data=odd.front();
            temp=temp->next;
            odd.pop();
        }
        
        return head;
    }
};

t.c:-O(n) and s.c:-O(n)

optimized

class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node *evenhead=NULL,*eventail=NULL;
        Node *oddhead=NULL,*oddtail=NULL;
        
        Node *temp=head;
        while(temp!=NULL){
            if(temp->data%2==0){
                if(evenhead==NULL){
                    evenhead=temp;
                    eventail=temp;
                }
                else{
                    eventail->next=temp;
                    eventail=eventail->next;
                }
            }
            else{
                if(oddhead==NULL){
                    oddhead=temp;
                    oddtail=temp;
                }
                else{
                    oddtail->next=temp;
                    oddtail=oddtail->next;
                }
            }
            temp=temp->next;
        }
        if(eventail!=NULL) eventail->next=oddhead;
        if(oddtail!=NULL) oddtail->next=NULL;
        
        if(evenhead==NULL) return oddhead;
        return evenhead;
    }
};


at the last we can also use these 3 conditions instead of all those 3
  //this is necessary as if even does not exist return odd
   if(evenhead==NULL) return oddhead;

//make eventail->next=odd and no need to check null as it will never occur okk
        eventail->next=oddhead;
        oddtail->next=NULL;

t.c:-O(n) and s.c:-O(1)




normal vs code code

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

void solve(node *head){
	node *oddhead=NULL;
	node *oddtail=NULL;
	node *evenhead=NULL;
	node *eventail=NULL;

	node *temp=head;
	while(temp!=NULL){
		int val=temp->data;

		if(val%2!=0){
			if(val%2!=0 and oddhead==NULL){
				oddhead=temp;
				oddtail=temp;
			}
			else{
				oddtail->next=temp;
				oddtail=temp;
			}
		}
		else{
			if(evenhead==NULL){
				evenhead=temp;
				eventail=temp;
			}
			else{
				eventail->next=temp;
				eventail=temp;
			}
		}
		

		temp=temp->next;
	}

	if(oddhead==NULL){
		print(evenhead);
		return;
	}

	oddtail->next=evenhead;
	if(evenhead!=NULL) eventail->next=NULL;
	print(oddhead);
	return;


}
int main() {
	int n;
	cin>>n;

	node *head=NULL;
	node *tail=NULL;

	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		insertattail(head,tail,val);
	}
	
	solve(head);
}
