 Sort linked list of 0s 1s 2s
Easy
40/40
Average time to solve is 10m
Contributed by
246 upvotes
Asked in companies
Problem statement
Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.



Example:
Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7
1 0 2 1 0 2 1


Sample Output 1:
0 0 1 1 1 2 2


Explanation Of Sample Input 1:
Input: 1 -> 0 -> 2 -> 1 -> 0 -> 2 -> 1

Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

Explanation: 
In this example, the original linked list contains two 0s, three 1s, and two 2s. The sorted linked list has all the 0s at the beginning, followed by all the 1s, and finally, all the 2s at the end.


Sample Input 2:
8
2 1 0 2 1 0 0 2


Sample Output 2:
0 0 0 1 1 2 2 2


Follow Up:
Can you solve this without updating the Nodes of the given linked list?


Constraints :
1 <= N <= 10^3
0 <= data <= 2 

Where 'N' is the length of the linked list.

Time Limit: 1 sec




/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    // Write your code here.
    int zero=0;
    int one=0;
    int two=0;

    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero++;
        }
        if(temp->data==1){
            one++;
        }
        if(temp->data==2){
            two++;
        }
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){
        if(zero){
            temp->data=0;
            zero--;
        }
        else if(one){
            temp->data=1;
            one--;
        }
        else{
            temp->data=2;
            two--;
        }
        temp=temp->next;
    }
    return head;
}

t.c:-O(n) and s.c:-O(1)


but if replacement of data is not allowed then do 
