bool isCircular(Node* head){

    if (head==nullptr)

    {

        return true ; 

    }

    Node*slow = head ; 

    Node*fast = head ; 

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
