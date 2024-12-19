 Flatten A Linked List
Easy
40/40
Average time to solve is 15m
Contributed by
289 upvotes
Asked in companies
Problem statement
You are given a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:



(1) ‘next’ which points to the next node in the list

(2) ‘child’ pointer to a linked list where the current node is the head.



Each of these child linked lists is in sorted order and connected by 'child' pointer.



Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.



Example:
Input: Given linked list is:

Output:
1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → 12 → 20 → null.


Explanation:
The returned linked list should be in a sorted order. All the elements in this returned linked list are connected by 'child' pointers and 'next' pointers point to null.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
4
3
1 2 3
3
8 10 15
2
18 22
1
29


Sample Output 1 :
1 2 3 8 10 15 18 22 29


Explanation For Sample Input 1:
The given linked list is 

Therefore after flattening the list will become-
1 -> 2 -> 3 -> 8 -> 10 -> 15 -> 18 -> 22 -> 29 ->null


Sample Input 2 :
5
2
4 6
2
5 71
3
7 8 9
3 
11 12 19
3
14 15 17


Sample Output 2 :
4 5 6 7 8 9 11 12 14 15 17 19 71


Expected Time Complexity:
Try solving this in O(n*n*k), where ‘n’ denotes the number of head nodes and ‘k’ is the average number of child nodes in all 'n' sub-lists.     


Expected Space Complexity:
Try solving this without using any extra space.   


Constraints:
1 <= n <= 100
1 <= k <= 20
1 <= Node.data <= 10^9

Time Limit: 1 sec




class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    
   void insertattail(Node* &tail, Node* &head, int val) {
    Node *newnode = new Node(val);
    if (head == NULL) {
        // If the list is empty, set both head and tail to the new node
        head = newnode;
        tail = newnode;
    } else {
        // If the list is not empty, append the new node at the end

        //the thing is by means of flatten list means we have to return the vertical list okk not the horizontal one right
        tail->bottom = newnode;
        tail = newnode;  // Move the tail pointer to the new last node
    }
}

    Node *flatten(Node *root) {
        // Your code here
        vector<int>ans;
        
        Node *temp=root;
        
        while(temp!=NULL){
            ans.push_back(temp->data);
            
            Node *t=temp->bottom;
            while(t!=NULL){
                ans.push_back(t->data);
                t=t->bottom;
            }
            
            temp=temp->next;
        }
        
        sort(ans.begin(),ans.end());

        Node *newhead=NULL;
        Node *newtail=NULL;
        for(auto i:ans){
            insertattail(newtail,newhead,i);
        }
        
        Node *d=newhead;
        
        return d;
        
    }
};

t.c:-O(n*m)*2 + n*m log(n*m) where n is horizontal length and m is vertical length
and s.c:-O(n*m)*2 for ans array and list created



perfect optimized code:--


in the above code we didnt utilize the thing that the vertical lists are already sorted so we just have to merge them from the last using recursion

Node* merge(Node* &first,Node* &second){
    Node *dummy=new Node(-1);
    Node *ans=dummy;
    Node *l1=first;
    Node *l2=second;

    while(l1!=NULL && l2!=NULL){
        if(l1->data<l2->data){
            ans->child=l1;
            ans=l1;
            l1=l1->child;
        }
        else{
            ans->child=l2;
            ans=l2;
            l2=l2->child;
        }
        ans->next=NULL;
    }

    while(l1!=NULL){
        ans->child=l1;
        ans=l1;
        l1=l1->child;
        ans->next=NULL;
    }
    while(l2!=NULL){
        ans->child=l2;
        ans=l2;
        l2=l2->child;
        ans->next=NULL;
    }

    return dummy->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *mergeHead=flattenLinkedList(head->next);
    head= merge(mergeHead,head);

    return head;
}

t.c:-O(n*(n+m)) and s.c:-O(n) due to recursive calls
