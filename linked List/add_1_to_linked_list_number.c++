

class Solution {
  public:
  
    void insertAthead(Node* &head,int data){
        if(head==NULL){
           Node *temp=new Node(data);
           head=temp;
        }
        else{
            Node *temp=new Node(data);
            temp->next=head;
            head=temp;
        }
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        vector<int>digits;
        Node *temp=head;
        while(temp!=NULL){
            digits.push_back(temp->data);
            // ans.push_back(temp->data);
            temp=temp->next;
        }
        
        vector<int>ans;
        int n=digits.size()-1;

        int carry=1;

        for(int i=n;i>=0;i--){
            int sum=digits[i]+carry;
            ans.push_back(sum%10);
            carry=sum/10;
        }

        while(carry){
            ans.push_back(carry%10);
            carry/=10;
        }
        

        Node *newHead=NULL;
        for(auto i:ans){
            insertAthead(newHead,i);
        }
        
        
        
        return newHead;
    }
};


t.c:-O(n) and s.c:-O(n)


but what if we want to reduce the space complexity then what ???????

class Solution {
  public:
    Node* reverseList(Node *head){
        Node *prev=NULL;
        Node *curr=head;
        Node *forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        head=reverseList(head);
        
        int carry=1;
        
        Node *temp=head;
        Node *prev=NULL;
        
        while(temp!=NULL){
            int sum=temp->data + carry;
            temp->data=sum%10;
            carry=sum/10;
            prev=temp;
            temp=temp->next;
        }

       //then here we did store the value  of carry in a single node only because it is the last value right
        
        if(carry){
            Node *newNode=new Node(carry);
            prev->next=newNode;
        }
        
        head=reverseList(head);
        return head;
    }
};

so same code as in array we did 

in array we start from last so here we did reverse the array and follow the same procedure now the temp at the end will point to NULL so take a prev pointer
before it to point a carry node if any remains




t.c:O(n) and s.c:-O(1)
