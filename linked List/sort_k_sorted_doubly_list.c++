You’re given a doubly-linked list with N nodes, where each node deviates at max K position from its position in the sorted list. Your task is to sort this given doubly linked list.

For example :
Let us consider K is 3, an element at position 4 in the sorted doubly linked list, can be at positions 1, 2, 3, 4, 5, 6, 7 in the given linked list because the absolute difference of all these indices with 4 is at most 3.
Note :
All elements are distinct.

A doubly linked list is a type of linked list that is bidirectional, that is, it can be traversed in both directions, forward and backward. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 10000
1 <= K < N

Time Limit: 1 sec
Sample Input 1 :
1
4 
6 5 3 2 8 10 9 -1
Sample Output 1 :
2 3 5 6 8 9 10 -1
Explanation For Sample Input 1 :
We could move 6 from position 1 to as far as position 5(as K=4) and we moved it to position 4 and it can be seen that after that all elements to the left(i.e position 1 to 3) are less than 6, hence 10 is at its best position now. Similarly, we do this for all the elements, to reach our answer. 
Sample Input 2 :
1
4
10 9 8 7 4 70 60 50 -1
Sample Output 2 :
4 7 8 9 10 50 60 70 -1

before this how to sort k sorted array in O(nlogk) t.c and O(k) s.c

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int i=0;
        for(auto j:arr){
            pq.push(j);
            
            if(pq.size()>k){
                arr[i++]=pq.top();
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            arr[i++]=pq.top();
            pq.pop();
        }
        
    }
};




brute force

Node *sortedDll(Node *head, int k)
{
    // Write your code here
    vector<int>ans;
        Node *temp=head;
        while(temp!=NULL){
            ans.push_back(temp->data);
            temp=temp->next;
        }
        
        
        sort(ans.begin(),ans.end());
        
        temp=head;
        int i=0;
        while(i<ans.size() && temp!=NULL){
            temp->data=ans[i++];
            temp=temp->next;
        }
        
        return head;
}

t.c:-O(nlogn) and s.c:-O(n)

little optimmized code


using priorityqueue

#include <queue>
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int i=k+1;
        DLLNode *temp=head;
        while(temp!=NULL && i){
            pq.push(temp->data);
            i=i-1;
            if(i==0) break;
            temp=temp->next;
        }
        

        DLLNode *forward=temp->next;
        temp=head;
        while(temp!=NULL){
            int val=pq.top();
            pq.pop();
            
            temp->data=val;
            if(forward!=NULL){
                pq.push(forward->data);
                forward=forward->next;
            }
            
            temp=temp->next;
        }

        return head;
    }
};

t.c:-O(nlogk) and s.c:-O(k+1)

as queue takes logk time for it's operations like push and pop okk

if u didnt understand above code so simple code


class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        
        DLLNode *temp=head;
        DLLNode *a=head;
        
        while(temp!=NULL){
            
            if(pq.size()>k){
                a->data=pq.top();
                pq.pop();
                a=a->next;
            }
            pq.push(temp->data);
            temp=temp->next;
        }
        
        while(!pq.empty()){
            a->data=pq.top();
            a=a->next;
            pq.pop();
        }
        
        return head;
    }
}; with same t.c and s.c
