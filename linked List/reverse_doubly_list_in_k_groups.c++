Reverse DLL nodes in groups
Moderate
80/80
Average time to solve is 10m
Contributed by
24 upvotes
Asked in companies
Problem statement
You are given a Doubly Linked List of integers and a positive integer 'K' representing the group size. Modify the linked list by reversing every group of 'K' nodes in the linked list.

A doubly linked list is a type of linked list that is bidirectional, that is, it can be traversed in both directions, forward and backward. 
Note:
If the number of nodes in the list or in the last group is less than K, just reverse the remaining nodes. 
Example:
Linked list: 8 9 10 11 12
K: 3 

Output: 10 9 8 12 11

We reverse the first K (3) nodes. Now, since the number of nodes remaining in the list (2) is less than K, we just reverse the remaining nodes (11 and 12).  
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10    
1 <= N <= 5 * 10^4
1 <= K <=  10^5
-10^3 <= data <= 10^3 and data != -1

Time Limit: 1 sec
Sample Input 1:
1 
1 2 3 4 5 6 7 -1
2  
Sample Output 1:
2 1 4 3 6 5 7 -1
Explanation of sample input 1:
In the given linked list, we have to reverse the first two nodes, then reverse the next two nodes, and so on… until all the nodes are processed in the same way.
The modified linked list after the above process is 2 1 4 3 6 5 7 -1
Sample Input 2:
2
5 10 -6 4 7 -1 
3 
10 20 30 40 50 -1
1 
Sample Output 2:
-6 10 5 7 4 -1
10 20 30 40 50 -1










int length(Node *head){
        Node *temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
Node* reverseDLLInGroups(Node* head, int k)
{	
    // Write your code here.
	if(k==0) return head;

        Node *p=NULL;
        Node *curr=head;
        Node * forward;

        int count=0;

        while(curr!=NULL && count<k){
            forward=curr->next;
            curr->next=p;
			curr->prev=forward;
            p=curr;
            curr=forward;
            count++;
        }


        if(curr!=NULL){
            head->next=reverseDLLInGroups(curr,k);
			if(head->next!=NULL){
				head->next->prev=head;
			}
        }
	else{
		head->next=NULL;
	}
       

        return p; 
}


or

int length(Node *head){
        Node *temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
Node* reverseDLLInGroups(Node* head, int k)
{	
    // Write your code here. 
    if(head==NULL or head->next==NULL) return head;

    int len=length(head);

    Node *curr=head;
    Node *p=NULL;
    int count=0;
    while(curr!=NULL and count<k){
        p=curr;
        Node *curr_prev=curr->prev;
        Node *curr_next=curr->next;

        curr->next=curr_prev;
        curr->prev=curr_next;
        curr=curr_next;

        count++;
    }

    if(p->prev!=NULL){
        p->prev=NULL;
    }

    if(curr!=NULL){
        Node *ans=reverseDLLInGroups(curr,k);
        head->next=ans;
        if(ans!=NULL) ans->prev=head;
    }
    else{
            head->next=NULL;
        }

    return p;
}
