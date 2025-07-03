z Circular Queue
Easy
40/40
Average time to solve is 15m
Contributed by
128 upvotes
Asked in companies
Problem statement
You will be given ‘Q’ queries. You need to implement a circular queue according to those queries. Each query will belong to one of these two types:

1 ‘X’: Enqueue element ‘X’ into the end of the nth queue. Returns true if the element is enqueued, otherwise false.

2: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.
Note:
Enqueue means adding an element to the end of the queue, while Dequeue means removing the element from the front of the queue.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 1000
1 <= Q <= 10^5 
1 <= P <= 2
1 <= X <= 10^5

Time limit: 1 sec
Sample Input 1:
3 7
1 2 
1 3 
2 
1 4 
1 6 
1 7 
2
Sample Output 1:
True 
True
2
True
True
False
3
Explanation of Sample Output 1:
For this input, we have the size of the queue, 'N' = 3, and the number of queries, 'Q' = 7.

Operations performed on the queue are as follows:

push(2): Push element ‘2’ into the queue. This returns true.
push(3): Push element ‘3’ into the queue. This returns true.
pop(): Pop the top element from the queue. This returns 2.
push(4): Push element ‘4’ into the queue. This returns true.
push(6): Push element ‘6’ into the queue. This returns true.
push(7): Push element ‘7’ into the queue. This returns false because the queue is full.
pop(): Pop the top element from the queue. This returns 3.
Sample Input 2:
4 7
1 11 
1 51 
1 26 
2 
1 6
2
2 
Sample Output 2:
True
True
True
11
True
51
26
Explanation for Sample Output 2:
For this input, we have the size of the queue, 'N' = 3, and the number of queries, 'Q' = 7.

Operations performed on the queue are as follows:

push(11): Push element ‘11’ into the queue. This returns true.
push(51): Push element ‘51’ into the queue. This returns true.
push(26): Push element ‘26’ into the queue. This returns true.
pop(): Pop the top element from the queue. This returns 11.
push(6): Push element ‘6’ into the queue. This returns true.
pop(): Pop the top element from the queue. This returns 51.
pop(): Pop the top element from the queue. This returns 26.








#include <bits/stdc++.h> 
class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    // Initialize your data structure.
    CircularQueue(int n){
        size=n;
        arr=new int[size];
        front=rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //checking if queue is full
        if((front==0 and rear==size-1) or (rear==(front-1)%size)){
            return false;
        }
        //if queue is empty
        else if(front==-1){
            front=rear=0;
        }
        //to maintain circular nature 
        else if(rear==size-1 and front!=0){
            rear=0;
        }
        else{
            rear++;
        }

        arr[rear]=value;

        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        //if queue is empty
        if(front==-1){
            return -1;
        }

        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }
};

t.c:-O(1) and s.c:-O(1)



2nd time :


#include <bits/stdc++.h> 
class CircularQueue{
    public:

    int *arr;
    int size;
    int front;
    int rear;
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        this->size=n;
        arr=new int[n];
        front=-1;
        rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front==0 and rear==size-1) or (rear==(front-1))) return false;
        else if(front==-1){
            front=0;
            rear=0;
        }
        else if(rear==size-1 and front!=0){
            rear=0;
        }
        else{
            rear++;
        }

        arr[rear]=value;

        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front==-1){
            return -1;
        }

        int ans=arr[front];
        
        if(front==rear){  ///bhai ye mat sochna ki jaise aapne 1(f) , 3(r) hai pop kiya 3(f,r)  but jb hi thodi pop hoke f r se age jayega vapas jb call 
            //ayega pop k tb ye condition check hogi alright
            front=-1;
            rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        
        return ans;
    }
};
