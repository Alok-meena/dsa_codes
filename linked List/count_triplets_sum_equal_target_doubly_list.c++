 Count triplets in a sorted doubly linked list whose sum is equal to a given value x
Moderate
80/80
Average time to solve is 15m
Contributed by
34 upvotes
Asked in companies
Problem statement
You are given a sorted doubly linked list of distinct nodes that means no two nodes present in the list have the same data. You are also given an integer 'X'.Your task is to count the number of triplets in the list that sum up to a given value 'X'.

A doubly linked List (DLL) contains an extra pointer, called the previous pointer, together with the next pointer and data, which are there in the singly linked list such that both forward and backward navigation is possible.

For example, DLL is 1<->2<->3<->4 NULL and the given integer 'X' is 9, then the number of triplets having the sum 9 is only one, and that is (2,3,4).

Note:
1. If no such triplets exist, return zero.
2. At least three elements will always be present in the linked list.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 10
3 <= 'N' <= 100
1 <= 'X' <= 10^8
1 <= 'V' <= 10^8

Where 'V' denotes any linked list element.

Time Limit: 1 sec
Sample Input 1 :
3
1 2 3 8 9 -1
13
1 2 3 4 5 6 7 8 9 -1
15
7 33 88 91 -1
40
Sample Output 1 :
2
8
0
Explanation of the Sample Input 1:
For the first test case:
The linked List is 1<-->2<-->3<-->8<-->9 NULL
We can clearly see that 2 triplets exist for this case, i.e., (2,3,8) and (1,3,9)

For the second test case:
The linked List is :1<-->2<-->3<-->4←>5<-->6<-->7<-->8<-->9 NULL
For this case we can see that there are total of eight triplets i.e. (2,4,9),(4,5,6),(2,6,7),(3,4,8),(1,5,9),(1,6,8),(2,5,8)and (3,5,7)

For the third test case:
The Linked List is 7<-->33<-->88<-->91 NULL
For this test case, we can see that there is no such triplet that gives us the 40, so the answer will be zero here.
Sample Input 2 :
1
3 7 9 23 45 -1
19
8 13 16 -1
37
Sample Output 2 :
1 
1
Explanation of the Sample Input 2:
In the first test case only the triplets (3, 7, 9) sum up to 19, Therefore the answer is 1.

In the second test case there is only 1 triplet (8, 13, 16) and that does sum to 37. Therefore the answer is 1.







int countTriplets(DLLNode* head, int x)
{
    // WRITE YOUR CODE HERE
    int ans=0;
        
        DLLNode *temp=head;
        while(temp->next->next!=NULL){
            DLLNode *ptr1=temp->next;
            DLLNode *ptr2=temp;
            while(ptr2->next!=NULL){
                ptr2=ptr2->next;
            }
            
            while(ptr1!=ptr2 && ptr2->next!=ptr1){
                int sum=ptr1->data + ptr2->data + temp->data; 
                
                if(sum==x){
                    ans++;
                    ptr2=ptr2->prev;
                    ptr1=ptr1->next;
                }
                else if(x>sum){
                    ptr1=ptr1->next;
                }
                else{
                    ptr2=ptr2->prev;
                }
            }
            temp=temp->next;
        }
        
        return ans;
    

}  


t.c:-O(n^2) and s.c:-O(1)
