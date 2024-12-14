Problem statement
A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.



You are given a sorted doubly linked list of size 'n'.



Remove all the duplicate nodes present in the linked list.



Example :
Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3

Output: Modified Linked List: 1 <-> 2 <-> 3

Explanation: We will delete the duplicate values ‘2’ present in the linked list.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
5
1 2 2 2 3


Sample Output 1 :
1 2 3


Explanation For Sample Input 1 :
We will delete the duplicate values ‘2’ present in the linked list.



Node * removeDuplicates(Node *head)
{
    // Write your code here
    if(head==NULL) return NULL;
    Node *curr=head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node *duplicate=curr->next;
            curr->next=duplicate->next;
            if(duplicate->next!=NULL){
                duplicate->next->prev=curr;
            }
            delete(duplicate);
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}
