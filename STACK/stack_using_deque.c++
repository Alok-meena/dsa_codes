Stack Using Deque
Easy
40/40
Average time to solve is 15m
Contributed by
46 upvotes
Asked in companies
Problem statement
Design a data structure to implement a stack, using only deque (double-ended queue). It should support the following operations :

push(X): Pushes an element X into the stack. Returns true if the element is pushed into the stack, otherwise false.

pop(): Pops the top element from the stack. Returns -1 if the stack is empty, otherwise, returns the popped element.

top(): Returns the topmost element of the stack. In case the stack is empty, it returns -1.

isEmpty() : Returns true if the stack is empty, otherwise false.

size(): Returns the number of elements currently present in the stack.
Following type of queries denote these operations :

Type 1 : for push(X) operation.

Type 2 : for pop() operation.

Type 3 : for top() operation.

Type 4 : for isEmpty() operation.

Type 5 : for size() operation.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= Q <= 10^5 
1 <= P <= 5
1 <= X <= 10^5

Time Limit: 1 sec
Sample Input 1 :
6
4
1 10
1 20
5
2
3
Sample Output 1 :
True 
True
True
2
20
10
Explanation 1 :
For the given input, we have the number of queries, Q = 6.
Operations performed on the stack are as follows:

isEmpty() : Stack is initially empty. So, this returns true.
push(10) : Push element ‘10’ into the stack. This returns true.
push(20) : Push element ‘20’ into the stack. This returns true.
size() : Stack has two elements in it. So, this returns 2.
pop() : Pop the top element from the stack. This returns 20.
top() : Return the topmost element of the stack i.e 10.

The following image shows the snapshots of the stack (implement using deque) after each operation:

Sample Input 2 :
5
1 15
1 25
4
1 30
5
Sample Output 2 :
True
True
False
True
3


#include <bits/stdc++.h> 
class Stack
{
public:
    // Initialize your data structure.
    deque<int>dq;
    Stack()
    {
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        // Write your code here.
        dq.push_back(x);
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        // Write your code here.
        if(dq.empty()) return -1;
        int val=dq.back();
        dq.pop_back();
        return val;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        // Write your code here.
        if(dq.empty()) return -1;
        return dq.back();
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        // Write your code here.
        return dq.empty();
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        // Write your code here.
        return dq.size();
    }
};
