Node* reverse(Node* head) {
        // code here
        Node *prev=head;
        Node *curr=head->next;
        
        
        while(curr!=head){
            Node *forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        curr->next=prev;
        
        return prev;
    }
