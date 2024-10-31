Insert in Sorted way in a Sorted DLL
Difficulty: MediumAccuracy: 28.25%Submissions: 48K+Points: 4
Given a sorted doubly linked list and an element x, you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).

Note: The DLL is sorted in ascending order

Example:

Input: LinkedList: 3->5->8->10->12 , x = 9

Output: 3->5->8->9->10->12

Explanation: Here node 9 is inserted in the Doubly Linked-List.

class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // If the list is empty or x is less than the head node's data, insert at the beginning
        if (!head || head->data > x) {
            Node* temp = new Node();
            temp->data = x;
            temp->next = head;
            temp->prev = nullptr;
            if (head) head->prev = temp;
            return temp; // New head
        }
        
        // Traverse the list to find the insertion point
        Node* curr = head;
        while (curr->next && curr->next->data < x) {
            curr = curr->next;
        }
        
        // Create a new node to insert
        Node* temp = new Node();
        temp->data = x;
        
        // Case 1: Insert at the end
        if (!curr->next) {
            curr->next = temp;
            temp->prev = curr;
            temp->next = nullptr;
        }
        // Case 2: Insert in the middle
        else {
            temp->next = curr->next;
            temp->prev = curr;
            curr->next->prev = temp;
            curr->next = temp;
        }
        
        return head; // Return the unchanged head
    }
};
