




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
        tail->next = newnode;
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

t.c:-O(n) and s.c:-O(n)
