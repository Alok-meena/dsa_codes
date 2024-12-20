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

Time Complexity : O(n * log n) , sort takes O(n * log n) time complexity.
Space Complexity : O(n) , due to space consumed by ans vector.




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
