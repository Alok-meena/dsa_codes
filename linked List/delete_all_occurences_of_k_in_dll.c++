Delete all occurrences of a given key in a doubly linked list
Moderate
80/80
Average time to solve is 30m
Contributed by
117 upvotes
Asked in company
Problem statement
A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.



You’re given a doubly-linked list and a key 'k'.



Delete all the nodes having data equal to ‘k’.



Example:
Input: Linked List: 10 <-> 4 <-> 10 <-> 3 <-> 5 <-> 20 <-> 10 and ‘k’ = 10

Output: Modified Linked List: 4 <-> 3 <-> 5 <-> 20

Explanation: All the nodes having ‘data’ = 10 are removed from the linked list.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7
10 4 10 3 5 20 10
10


Sample Output 1:
4 3 5 20


Explanation Of Sample Input 1:
All the nodes having ‘data’ = 10 are removed from the linked list.


Sample Input 2:
7
10 4 10 3 5 20 10
30


Sample Output 2:
10 4 10 3 5 20 10


Explanation Of Sample Input 2:
The linked list does not have any node with ‘data’ = 30. So the linked list is unchanged.


Expected Time Complexity:
The expected time complexity is O(‘n’).


Constraints:
0 <= ‘n’ <= 100000
1 <= ‘data’ in any node <= 10^9
1 <= ‘k’ <= 10^9






Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    while(head!=NULL and head->data==k) head=head->next;
    if(head==NULL) return NULL;
    Node *pre=head;
    Node *curr=head->next;

    while(curr!=NULL){
        if(curr->data==k){
            pre->next=curr->next;
            if(curr->next!=NULL) curr->next->prev=pre;
            Node *temp=curr;
            curr=curr->next;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
        else{
            pre=curr;
            curr=curr->next;
        }
    }

    return head;
}
