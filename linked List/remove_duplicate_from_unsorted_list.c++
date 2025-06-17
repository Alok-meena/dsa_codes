Problem statement
You are given a linked list of N nodes. Your task is to remove the duplicate nodes from the linked list such that every element in the linked list occurs only once i.e. in case an element occurs more than once, only keep its first occurrence in the list.

For example :
Assuming the linked list is 3 -> 2 -> 3 -> 4 -> 2 -> 3 -> NULL.

Number ‘2’ and ‘3’ occurs more than once. Hence we remove the duplicates and keep only their first occurrence. So, our list becomes : 3 -> 2 -> 4 -> NULL.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 100   
1 <= N <= 10 ^ 4
1 <= data <= 10 ^ 5 

Where ‘N’ is the number of nodes in the list and 'data' is the value of list nodes.

Time Limit: 1sec
Sample Input 1 :
2
4 2 5 4 2 2 -1
1 2 1 2 2 2 7 7 -1
Sample Output 1 :
4 2 5 -1
1 2 7 -1
Explanation of Sample Input1 :
For the first test case, the linked list is 4 -> 2 -> 5 -> 4 -> 2 -> 2 -> NULL. Number ‘4’ and ‘2’ occurs more than once. Hence, we remove the duplicates and keep only their first occurrence. So, our list becomes : 4 -> 2 -> 5 -> NULL.

For the second test case, the linked list is 1 -> 2 -> 1 -> 2 -> 2 -> 2 -> 7 -> 7 -> NULL. Number ‘1’, ‘2’ and ‘7’ occurs more than once. Hence, we remove the duplicates and keep only their first occurrence. So, our list becomes : 1 -> 2 -> 7 -> NULL.
Sample Input 2 :
2
3 3 3 3 3 -1
10 20 10 20 30 10 20 30 -1
Sample Output 2 :
3 -1
10 20 30 -1


brute force O(n) t.c and s.c

void insertattail(Node* &head,Node* &tail,int value){
    if(head==NULL){
        Node *newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else{
        Node *newnode=new Node(value);
        tail->next=newnode;
        tail=newnode;
    }
}
Node *removeDuplicates(Node *head)
{
    // Write your code here
    vector<int>v;
    Node *temp=head;
    while(temp!=NULL){
        if(find(v.begin(),v.end(),temp->data)==v.end()) v.push_back(temp->data);
        temp=temp->next;
    }

    Node *newhead=NULL;
    Node *tail=NULL;
    for(auto i:v){
        insertattail(newhead,tail,i);
    }

    return newhead;
}

another brute force of same t.c using map but not creating a new list


Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head==NULL or head->next==NULL) return head;
    map<int,bool>m;

    Node *prev=head;
    Node *curr=head->next;

    m[prev->data]=true;
    while(curr!=NULL){
        if(m[curr->data]){
            Node *temp=curr;
            prev->next=curr->next;
            temp->next=NULL;
            delete temp;
            curr=prev->next;
        }
        else{
            m[curr->data]=true;
            prev=prev->next;
            curr=curr->next;
        }
    }

    return head;
}

1) brute force using two loops remove the duplicates 

Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL) return head;

    Node *curr = head;
    while (curr != NULL) {
        Node *runner = curr; // Runner checks for duplicates
        while (runner->next != NULL) {
            if (runner->next->data == curr->data) {
                // Remove duplicate node
                Node *duplicate = runner->next;
                runner->next = duplicate->next;
                delete duplicate;
            } else {
                runner = runner->next; // Move runner to the next node
            }
        }
        curr = curr->next; // Move curr to the next node
    }
    return head;
}


2)gives tle also



Node *removeDuplicates(Node *head)
{
    // Write your code here
    map<int,bool>visited;
    if(head==NULL) return NULL;
    Node *prev=NULL;
    Node *curr=head;
    while(curr!=NULL){
        if(visited[curr->data]){
            Node *duplicate=curr;
            prev->next=duplicate->next;
            curr=curr->next;
            delete(duplicate);
        }
        else{
            visited[curr->data]=true;
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

t.c:-O(n) and s.c:-O(n)

3) sort and then do like with sorted list O(nlogn) and O(1) are t.c and s.c


Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    // Split the list into two halves
    Node* middle = findMiddle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = NULL;

    // Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    return merge(left, right);
}

Node* removeDuplicates(Node* head) {
    // Sort the linked list
    head = mergeSort(head);

    if (head == NULL) return NULL;

    // Remove duplicates from sorted list
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* duplicate = curr->next;
            curr->next = duplicate->next;

            delete(duplicate);
        } else {
            curr = curr->next;
        }
    }
    return head;
}

t.c:-O(nlogn) and s.c:-O(logn) for recursive stack

#include <vector>
#include <algorithm>

Node* sortLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    // Store elements in a vector
    std::vector<int> elements;
    Node* temp = head;
    while (temp != NULL) {
        elements.push_back(temp->data);
        temp = temp->next;
    }

    // Sort the vector
    std::sort(elements.begin(), elements.end());

    // Update the linked list with sorted values
    temp = head;
    for (int value : elements) {
        temp->data = value;
        temp = temp->next;
    }

    return head;
}


t.c:-O(nlogn) s.c:-O(n)

4)

Node *removeDuplicates(Node *head)
{
    // Write your code here
    unordered_map<int,bool>visited;
    if(head==NULL) return NULL;
    Node *prev=NULL;
    Node *curr=head;
    while(curr!=NULL){
        if(visited[curr->data]){
            Node *duplicate=curr;
            prev->next=duplicate->next;
            curr=curr->next;
            delete(duplicate);
        }
        else{
            visited[curr->data]=true;
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}
just use unordered_map



and no other solution is possible if looking for O(n) then must use map



