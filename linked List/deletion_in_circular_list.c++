 Deletion In Circular Linked List
Easy
40/40
Average time to solve is 30m
Contributed by
26 upvotes
Asked in companies
Problem statement
You are given a Circular Linked List of integers, and an integer, 'key'.

You have to write a function that finds the given key in the list and deletes it. If no such key is present, then the list remains unchanged.

For Example :
This is a visualization of the Circular Linked List, represented by:
1 2 3 4 5 -1

Note :
The Circular Linked List before/after deletion may happen to be empty. In that case, only print -1.

All integers in the list are unique.


Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10 ^ 5
1 <= key <= 10 ^ 5

Where 'N' is the length of the Circular Linked List.

Time limit: 1 sec
Sample Input 1 :
1 2 3 4 5 -1
3
Sample Output 1 :
1 2 4 5 -1
Explanation for Sample 1 :
The given linked list, before deletion:

After deletion :

Sample Input 2 :
1 2 3 4 5 -1
1
Sample Output 2 :
2 3 4 5 -1





Node* deleteNode(Node* head, int key) 
{
    // Write your code here.
        if(head==NULL) return head;
        if(head->next==head && head->data==key){
                delete head;
                return NULL;
        }
        Node *curr=head->next;
        Node *prev=head;

        do{
            if(curr->data==key) break;
            prev=curr;
            curr=curr->next;
        }
        while(curr!=head);

        if(curr->data!=key) return head;

        if(curr==head){
            prev->next=curr->next;
            head=head->next;
            curr->next=NULL;
            delete curr; 
            return head;
        }
        
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        
        return head;
}
