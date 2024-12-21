Merge K sorted linked lists
Difficulty: MediumAccuracy: 57.01%Submissions: 86K+Points: 4
Given an array of sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Examples:

Input: arr = [1->2->3, 4->5, 5->6, 7->8]
Output: 1->2->3->4->5->5->6->7->8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be

Input: arr = [1->3, 4->5->6, 8]
Output: 1->3->4->5->6->8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be

Expected Time Complexity: O(n*log(n))
Expected Auxiliary Space: O(n)
Note: n is the maximum size of all the  LinkedList

Constraints
1 <= total no. of nodes <= 105
1 <= node->data <= 103





brute force :

store all of the values and then create list from those values after sorting them

class Solution{
  public:
    // Function to merge K sorted linked lists
    Node* mergeKLists(vector<Node*> arr) {
        int k = arr.size();
        vector<int> ans;
        
        for(int i = 0; i < k; i++) {
            Node* head = arr[i];
            while(head) {
                ans.push_back(head->data);
                head = head->next;
            }
        }
        
        sort(ans.begin(), ans.end());
        
        Node* dummy = new Node(-1);
        Node* current = dummy;
        
        for(int i : ans) {
            current->next = new Node(i);
            current = current->next;
        }
        
        current = dummy->next;
        delete dummy;
        return current;
    }
};


if n is the total number of elements in all of the linked lists

Time Complexity :O(n*k) + O(m * log m)  where m=n+k , sort takes O(n * log n) time complexity.
Space Complexity : 2 * O(n*k) , due to space consumed by ans vector.




class Solution {
  public:
     void insertatTail(int val,Node* &tail,Node* &head){
        Node *newNode=new Node(val);
        
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        
    
        Node *newHead=NULL;
        Node *tail=NULL;
        Node *t1=head1;
        Node *t2=head2;
        
        while(t1!=NULL && t2!=NULL){
            if(t1->data<t2->data){
                insertatTail(t1->data,tail,newHead);
                t1=t1->next;
            }
            else{
                insertatTail(t2->data,tail,newHead);
                t2=t2->next;
            }
        }
        
        while(t1!=NULL){
            insertatTail(t1->data,tail,newHead);
            t1=t1->next;
        }
        while(t2!=NULL){
            insertatTail(t2->data,tail,newHead);
            t2=t2->next;
        }
        
        
        return newHead;
        
        
    }
    // Function to merge K sorted linked list.
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        if(arr.empty()) return NULL;
        Node *mergehead=arr[0];
        for(int i=1;i<arr.size();i++){
            mergehead=sortedMerge(mergehead,arr[i]);
        }
        return mergehead;
        
    }
};

t.c:-O(n*k) and s.c:-O(n*k) where n is size of arr and k is length of each list


in place solution

class Solution {
  public:
    // Function to merge K sorted linked list.
    Node* solve(Node* &first,Node* &second){
        if(first->next==NULL){
            first->next=second;
            return first;
        }
        
        Node *curr1=first;
        Node *next1=curr1->next;
        Node *curr2=second;
        Node *next2=second->next;//to have pointer to the remaining list
        
        while(next1!=NULL && curr2!=NULL){
            
            if(curr2->data>=curr1->data && curr2->data<=next1->data){
                curr1->next=curr2;
                next2=curr2->next;
                curr2->next=next1;
                curr1=curr2;
                curr2=next2;
            }
            else{
                curr1=next1;
                next1=next1->next;

                //if first list is fully traversed then connect remaining seconnd list okk
                
                if(next1==NULL){
                    curr1->next=curr2;
                    return first;
                }
            }
        }
        return first;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node *temp=arr[0];
        for(int i=1;i<arr.size();i++){
            //smaller node is sent first
            if(temp->data<arr[i]->data){
                temp=solve(temp,arr[i]);
            }
            else{
                temp=solve(arr[i],temp);
            }
        }
        return temp;
    }
};

t.c:-O(n*k) and s.c:-O(1)


using priority queue

How to Decide Which Side of the Symbol?
The > or < in the comparator reflects how you want to prioritize the elements:

>: Smaller values have higher priority (min-heap).
<: Larger values have higher priority (max-heap).
Tip:
Read the > or < as a question:
"Should a have lower priority than b?"
If the answer is true, b gets higher priority. okkk


and this operator() is also fixed we cannot change it it is done to call it by creating a object instance in the class itself

Why Use operator() Instead of Other Methods?
Callable Objects:

operator() makes an object callable just like a function. This is particularly useful for custom comparators, functors, or callbacks.
Seamless Integration:

STL algorithms and containers like std::sort, std::priority_queue, and std::transform often require callable objects. Using operator() integrates seamlessly with these.
Readability:

Using operator() makes your code look cleaner and more intuitive because you can treat objects like functions.


Purpose of operator()
The primary purpose of operator() is to make objects of a class behave like functions. 
It does not eliminate the need to create an object of the class.
Instead, it allows you to call the object itself as if it were a function.

#include <queue>
class compare{
    public:
 //lamda function
      bool operator()(Node* a,Node *b){
         //means greater value will go donwn in the heap and min value at the top
          return a->data>b->data;
      }
};
Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    //here we cant use greater<Node*> here for minheap because it works only for standard values like int float etc not for Node okk so make a class of it 
  //and then use
    priority_queue<Node*,vector<Node*>,compare>pq;
        for(auto i:listArray){
            if(i) pq.push(i);
        }
        
        Node *dummy=new Node(-1);
        Node *temp=dummy;
        
        while(!pq.empty()){
            Node *newhead=pq.top();
            pq.pop();
            temp->next=newhead;
            temp=temp->next;
            if(newhead->next){
                //ham esa nhi kr rhe ki only head ko bhej rhe list me and next list  se attach kr rhe hai ham bs har ek element ko dal rhe so min head ka
                //ager next element exist krta hai to use push kr do queue me okk and continue this
                pq.push(newhead->next);
            }
        }
        
        return dummy->next;
}

t.c:-O((n+k)logk) and s.c:-O(n+k)

