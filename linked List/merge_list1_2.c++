struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int x) : data(x), next(nullptr) {}
};
Function to Merge Lists:
cpp
Copy code
SinglyLinkedListNode* mergeInBetween(SinglyLinkedListNode* list1, SinglyLinkedListNode* list2, int a, int b) {
    // Find the (a-1)th node
    SinglyLinkedListNode* prev = list1;
    for (int i = 0; i < a - 1; ++i) {
        prev = prev->next;
    }

    // Find the (b+1)th node
    SinglyLinkedListNode* after = prev;
    for (int i = a - 1; i <= b; ++i) {
        after = after->next;
    }

    // Connect the end of list2 to the (b+1)th node
    SinglyLinkedListNode* tail = list2;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = after->next;

    // Connect the (a-1)th node to the head of list2
    prev->next = list2;

    return list1;
}
