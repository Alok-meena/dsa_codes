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

simplest

Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node *curr=head;

    while(curr!=NULL and curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node *temp=curr->next;
            curr->next=temp->next;
            if(temp->next!=NULL) temp->next->prev=curr;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
        else curr=curr->next;
    }

    return head;
}


same code for singly list also alright



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


can do this also


Node * removeDuplicates(Node *head)
{
    // Write your code here
    if(head==NULL or head->next==NULL) return head;
    Node *p=head;
    Node *curr=head;

    while(curr!=NULL){
        if(curr->next!=NULL and curr->data!=curr->next->data){
            p=p->next;
            curr=curr->next;
            continue;
        }

        if(curr->next!=NULL) curr=curr->next;

        while(curr!=NULL and curr->data==p->data) curr=curr->next;
        p->next=curr;
        if(curr!=NULL) curr->prev=p;
        p=curr;
    }

    return head;
}


for singly list can do the same code


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode *p=head;
        ListNode *curr=head;

        while(curr!=NULL){
            if(curr->next!=NULL and curr->val!=curr->next->val){
                p=p->next;
                curr=curr->next;
                continue;
            }

            if(curr->next!=NULL) curr=curr->next;

            while(curr!=NULL and curr->val==p->val) curr=curr->next;
            p->next=curr;
            p=curr;
        }

        return head;
    }
};

t.c:-O(n) and s.c:-O(1) alright


OR CAN DO THIS ALSO FOR DOUBLY

Node * removeDuplicates(Node *head)
{
    // Write your code here
    if(head==NULL or head->next==NULL) return head;
    Node *curr=head;

    while(curr!=NULL){
        if(curr->next!=NULL and curr->data==curr->next->data){
            Node *next_to_next=curr->next->next;
            Node *temp=curr->next;
            curr->next=next_to_next;
            if(next_to_next!=NULL) next_to_next->prev=curr;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
        else curr=curr->next;
    }

    return head;
}



or


Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node *pre=head;
    Node *curr=head->next;

    while(curr!=NULL){
        if(pre->data==curr->data){
            Node *temp=curr;
            while(temp!=NULL and temp->data==pre->data){
                temp=temp->next;
                curr=temp;
            }
            pre->next=temp;
            if(temp!=NULL) temp->prev=pre;
        }
        pre=curr;
        if(curr!=NULL) curr=curr->next;
    }

    return head;
}
