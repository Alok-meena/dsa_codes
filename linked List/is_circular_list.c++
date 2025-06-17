

normal code

class Solution {
  public:
    bool isCircular(Node *head) {
        // Your code here
        if(head==NULL) return true;
        if(head->next==NULL) return false;
    
        Node *slow=head;
        Node *fast=head;
    
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) return true;
        }
        
        return false;
    }
};


class Solution {
  public:
    bool isCircular(Node *head) {
        // Your code here
        if(head==NULL) return true;
        if(head->next==NULL) return false;
        Node *temp=head->next;
        while(temp!=NULL and temp!=head){
            temp=temp->next;
        }
    
        return temp==head;
    }
};

this code is for normal circualr list alright

bool isCircular(Node* head){

    if (head==nullptr)

    {

        return true ; 

    }

    Node*slow = head ; 

    Node*fast = head ; 

    //and this loop should have condition with fast pointer only because it will be ahead of slow pointer if it is not a circular list then it will be terminated 
    //easily and early
    while(fast!= nullptr && fast->next!=nullptr)

    {

        slow = slow->next ; 

        fast = fast->next->next ; 

        if (slow == fast &&slow == head)

        {

            return true ; 

        }

        if (slow == fast && slow != head)

        {

            return false;

        }

    }

    return false ; 

}

you can check it by drawing it on a paper it works for both even and odd length linked list
