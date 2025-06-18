Add Number Linked Lists
Difficulty: MediumAccuracy: 34.52%Submissions: 293K+Points: 4
Given two numbers, num1, and num2, represented by linked lists. The task is to return the head of the linked list representing the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 45 (4->5->null), num2 = 345 (3->4->5->null)
Output:  3->9->0->null  
 
Explanation: 
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Input: num1 = 0063 (0->0->6->3->null), num2 = 07 (0->7->null)
Output: 7->0->null
 
Explanation: 
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
Expected Time Complexity: O(n+m)
Expected Space Complexity: O(max(n,m)) for the resultant list.

Constraints:
1 <= size of both linked lists <= 106
0 <= elements of both linked lists <= 9



brute force t.c:-O(n+m) and s.c is O(max(n,m)) alright


#include <bits/stdc++.h>

class Solution {
  public:
    vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
    	int i=n-1;
    	int j=m-1;
    
    	vector<int>ans;
    	int carry=0;
    
    	while(i>=0 and j>=0){
    		int value=a[i]+b[j]+carry;
    		ans.push_back(value%10);
    		carry=value/10;
    		i--;j--;
    	}
    
    	while(i>=0){
    		int value=a[i]+carry;
    		ans.push_back(value%10);
    		carry=value/10;
    		i--;
    	}
    
    	while(j>=0){
    		int value=b[j]+carry;
    		ans.push_back(value%10);
    		carry=value/10;
    		j--;
    	}
    
    	while(carry){
    		ans.push_back(carry%10);
    		carry/=10;
    	}
    
    	reverse(ans.begin(),ans.end());
    
    	return ans;
}
    
    void insertattail(Node* &head,Node* &tail,int value){
        if(head==NULL){
            Node *newnode=new Node(value);
            head=newnode;
            tail=newnode;
        }
        else{
            Node *newnode=new Node(value);
            tail->next=newnode;
            tail=newnode;
        }
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        vector<int>a;
        vector<int>b;
        
        Node *temp=num1;
        
        while(temp->data==0) temp=temp->next;
        while(temp!=NULL){
            a.push_back(temp->data);
            temp=temp->next;
        }
        
        temp=num2;
        while(temp->data==0) temp=temp->next;
        while(temp!=NULL){
            b.push_back(temp->data);
            temp=temp->next;
        }
        
        vector<int>ans=findArraySum(a,a.size(),b,b.size());
        
        Node *head=NULL;
        Node *tail=NULL;
        
        for(auto i:ans){
            insertattail(head,tail,i);
        }
        
        return head;
    }
};







#include <bits/stdc++.h>

class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node* reverseList(Node *head){
        Node *prev=NULL;
        Node *curr=head;
        Node *forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    
    void insertAthead(Node* &head,int val){
        if(head==NULL){
           Node *temp=new Node(val);
           head=temp;
       }
       else{
            Node *temp=new Node(val);
            temp->next=head;
            head=temp;
       }
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        
        num1=reverseList(num1);
        num2=reverseList(num2);
        
        Node *curr1=num1;
        Node *curr2=num2;
        int carry=0;
        vector<int>ans;
        
        while(curr1!=NULL && curr2!=NULL){
            int sum=curr1->data + curr2->data + carry;
            
            ans.push_back(sum%10);
            carry=sum/10;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        while(curr1!=NULL){
            int sum=curr1->data + carry;
            
            ans.push_back(sum%10);
            carry=sum/10;
            curr1=curr1->next;
        }
        
        while(curr2!=NULL){
            int sum= curr2->data + carry;
            
            ans.push_back(sum%10);
            carry=sum/10;
            curr2=curr2->next;
        }
        
        if(carry){
            ans.push_back(carry);
        }
        

        Node *head=NULL;
        
        for(auto i:ans){
            insertAthead(head,i);
        }
        
        return head;
    }
};

t.c:-O(n+m) and s.c:-O(max(n,m))


2nd

#include <bits/stdc++.h>

class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node* reverseList(Node *head){
        Node *prev=NULL;
        Node *curr=head;
        Node *forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    
    void insertAttail(Node* &head,Node* &tail,int val){
        Node *temp=new Node(val);
        
        if(head==NULL){
           tail=temp;
           head=temp;
           return;
       }
       else{
            tail->next=temp;
            tail=temp;
            return;
       }
    }
    
    Node* addList(Node* &first,Node* &second){
        
        Node *ansHead=NULL;
        Node *ansTail=NULL;
        
        int carry=0;

        //here we did insertAtTail 

        //but if we do insertAThead then no need of reversal of the list okk
        
        while(first!=NULL && second!=NULL){
            int sum=first->data + second->data + carry;
            
            insertAttail(ansHead,ansTail,sum%10);
            
            carry=sum/10;
            first=first->next;
            second=second->next;
        }
        
        while(first!=NULL){
            int sum=first->data + carry;
            
            insertAttail(ansHead,ansTail,sum%10);
            
            carry=sum/10;
            first=first->next;
        }
        while(second!=NULL){
            int sum=second->data + carry;
            
            insertAttail(ansHead,ansTail,sum%10);
            
            carry=sum/10;
            second=second->next;
        }
        while(carry){
            insertAttail(ansHead,ansTail,carry%10);
            
            carry/=10;
        }
        
        return ansHead;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        
        num1=reverseList(num1);
        num2=reverseList(num2);
        
        Node *ans=addList(num1,num2);
        
        ans=reverseList(ans);
        return ans;
    }
};

same t.c and s.c


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

void insertathead(node* &head,int data){
	node *temp=new node(data);
	if(head==NULL){
		head=temp;
	}
	else{
		temp->next=head;
		head=temp;
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

node* add(node *h1,node *h2){
	node *head=NULL;
	node *a=h1;
	node *b=h2;
	int carry=0;

	while(a!=NULL and b!=NULL){
		int sum=a->data+b->data+carry;
		carry=sum/10;
		insertathead(head,sum%10);
		a=a->next;
		b=b->next;
	}

	while(a!=NULL){
		int sum=a->data+carry;
		carry=sum/10;
		insertathead(head,sum%10);
		a=a->next;
	}

	while(b!=NULL){
		int sum=b->data+carry;
		carry=sum/10;
		insertathead(head,sum%10);
		b=b->next;
	}

	while(carry){
		insertathead(head,carry);
		carry=carry/10;
	}

	return head;

	
	
}
int main() {
	int n,m;
	cin>>n>>m;
	node *h1=NULL,*h2=NULL;
	// node *t1=NULL,*t2=NULL;

	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		insertathead(h1,val);
	}

	for(int i=0;i<m;i++){
		int val;
		cin>>val;
		insertathead(h2,val);
	}
	
	node *temp=NULL;

	temp=add(h1,h2);
	print(temp);
	
}

t.c:-O(N+m) and s.c:-O(max(n,m))
