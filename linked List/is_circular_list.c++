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
