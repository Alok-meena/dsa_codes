Given 'k' sorted linked lists,
each list is sorted in increasing order.
You need to merge all these lists into one single sorted list. You need to return the head of the final linked list.


#include <queue>
class compare{
    public:
      bool operator()(Node* a,Node *b){
          return a->data>b->data;
      }
};
Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<Node*,vector<Node*>,compare>minheap;

    int k=listArray.size();
    if(k==0){
        return NULL;
    }

    for(int i=0;i<k;i++){
        if(listArray[i]!=NULL){
            minheap.push(listArray[i]);//O(klogk) because k lists and insertion in heap takes log k time
        }
    }

    Node* head=NULL;
    Node* tail=NULL;

    while(minheap.size()>0){
        Node* top=minheap.top();
        minheap.pop();

        if (top->next!=NULL) {
            minheap.push(top->next);
        }
        if(head==NULL){
            head=top;
            tail=top;
        }
        else{
            tail->next=top;
            tail=top;
        }
    }
    return head;

}


Time Complexity
O(n*klogk) n is no. of nodes in a LL and n*k is total no. of nodes
O(N * log k), where ‘N’ is the total number of nodes and ‘k’ is the number of lists.

 

.

Space Complexity
O(K), where ‘k’ is the number of lists.

 

In the worst case, we are making a priority queue of size ‘k’.

