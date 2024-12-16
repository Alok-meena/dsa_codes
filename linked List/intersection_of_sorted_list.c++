Intersection Sorted Linked Lists
Difficulty: EasyAccuracy: 48.63%Submissions: 141K+Points: 2
Given that two linked lists are sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made without changing the original lists.

Note: The elements of the linked list are not necessarily distinct.

Examples:

Input: LinkedList1 = 1->2->3->4->6, LinkedList2 = 2->4->6->8
Output: 2->4->6
Explanation: For the given two linked list, 2, 4 and 6 are the elements in the intersection.

Input: LinkedList1 = 10->20->40->50, LinkedList2 = 15->40
Output: 40
Explaination:

Expected Time Complexity: O(n+m)
Expected Space Complexity: O(n+m)
Note: n, m are the size of the respective linked lists.

Constraints:
1 <= size of linked lists <= 104
1 <= node->data<= 104






class Solution {
  public:
    void insertAtTail(Node* &head,Node* &tail,int val){
        Node *newNode=new Node(val);
        if(head==NULL){
            tail=newNode;
            head=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* findIntersection(Node* head1, Node* head2) {
        // code goes here.
        set<int>ans;
        set<int>ans1;
        
        Node *temp1=head1;
        
        while(temp1!=NULL){
            ans1.insert(temp1->data);
            temp1=temp1->next;
        }
        
        Node *temp2=head2;
        
        while(temp2!=NULL){

            int val=temp2->data;
            if(ans1.find(val)!=ans1.end()){
                ans.insert(val);
            }
            
            temp2=temp2->next;
        }
        
        Node *newHead=NULL;
        Node *newTail=NULL;
        for(auto i:ans){
            insertAtTail(newHead,newTail,i);
        }
        
        
        return newHead;
        
        
        
    }
};
