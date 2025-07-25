//to detect the loop one of the solution is 

using map as visited array

bool isCircular(Node* head){
    // Write your code here.
    if(head==NULL) return true;
    
    map<Node*,bool>visited;

    Node *temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}


2nd: is using the fast and slow pointer approach

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return NULL;
        }
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next!=NULL && slow!=NULL){ ///to ye update jruri hai ki next ko pahle check kro then aage badhao varna mt badhao
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};


2nd: find the start of the loop

  Node* hasCycle(Node *head) {
        if(head==NULL){
            return NULL;
        }
        Node *fast=head;
        Node *slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
           
            slow=slow->next;
            if(fast==slow){
                return slow;
            }
        }
        return NULL;
    }

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node *intersection=hasCycle(head);

    //after finding the intersection point of slow and fast we have to move a pointer to head and move pointers from both location 1 place and
    //at the point they meet is the start of loop
    if(intersection==NULL) return NULL;
    Node *start=head;
    while(start!=intersection){
        start=start->next;
        intersection=intersection->next;
    }
    return start;

}



3rd: detect and remove the loop

Node* flyod(Node *head){
    if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return NULL;
        }
       
        Node *fast=head;
        Node *slow=head;
        while(fast!=NULL && slow!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(fast==slow){
                return slow;
            }
        }
        return NULL;
}

Node* getStartingNode(Node* head) {

   if(head==NULL){
        return NULL;
    }
    Node *f=flyod(head);
    if(f==NULL){
        return NULL;
    }
    Node *slow=head;
    while(slow!=f){
        slow=slow->next;
        f=f->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    Node *startloop=getStartingNode(head);
    if(startloop==NULL){
        return head;
    }
    Node *temp=startloop;
    while(temp->next!=startloop){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;

    or we can also do like without finding the start of loop we can solve like this 
        slow=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }

        fast->next=NULL;
}

O(n) and s.c:-O(1)


just find whether loop is present or not alright if fast and slow meet then find intersection point start from head and fast or slow till both meet then
u will get beginning of list then just go to the end of loop and point it to NULL alright .

Node *removeLoop(Node *head)
{
    // Write your code here.
    Node *slow=head;
    Node *fast=head;

    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) break;
    }

    if(fast==NULL) return head;

    slow=head;

    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }

    fast=fast->next;
    while(fast->next!=slow) fast=fast->next;

    fast->next=NULL;

    return head;
}


or to find the beginning or loop we can use map also but then s.c:-O(n)



another time

Node *removeLoop(Node *head)
{
    // Write your code here.
    Node *slow=head;
    Node *fast=head;

    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }

    if(slow!=fast) return head;

    Node *temp=head;
    while(slow!=temp){
        slow=slow->next;
        temp=temp->next;
    }

    Node *t=temp;
    while(t->next!=temp){
        t=t->next;
    }

    t->next=NULL;

    return head; 
}
