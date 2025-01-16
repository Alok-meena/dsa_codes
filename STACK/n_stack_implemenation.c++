
Contributed by
266 upvotes
Asked in companies
Problem statement
Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:

push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.

pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
Two types of queries denote these operations :

Type 1: for push(X, M) operation.
Type 2: for pop(M) operation.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= S <= 1000
1 <= Q <= 10^5 
1 <= P <= 2
1 <= X <= 10^5

Time Limit: 1 sec

Where ‘S’ represents the size of the array, ‘N’ represents the number of stacks, ‘Q’ represents the number of queries, ‘P’ represents the type of operation and ‘X’ represents the element.
Sample Input 1 :
3 6 5
1 10 1
1 20 1
1 30 2
2 1
2 2
Sample Output 1 :
True 
True
True
20
30
Explanation 1 :
For the given input, we have the number of stacks, N = 3, size of the array, S = 6 and number of queries, Q = 5.
Operations performed on the stack are as follows:
push(10, 1): Push element ‘10’ into the 1st stack. This returns true.
push(20, 1): Push element ‘20’ into the 1st stack. This returns true.
push(30, 2): Push element ‘30’ into the 2nd stack. This returns true.
pop(1): Pop the top element from the 1st stack. This returns 20.
pop(2): Pop the top element from the 2nd stack. This returns 30.

The following image shows the snapshots of the stack after each operation:

Sample Input 2 :
1 5 5
1 15 1
1 25 1
2 1
1 30 1
2 1
Sample Output 2 :
True
True
25
True


diving arr into kparts 

/*
	Time complexity: O(1) for all operations.
	Space Complexity: O(S + N)
	
	Where S is the size of the array, 
    N is the number of stacks.
*/

class NStack
{
    // Array to implement the stacks.
    vector<int> arr;

    // Array to keep track of the indices of the top elements of every stack.
    vector<int> top;

    int n, s;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;

        // Create the arrays.
        arr = vector<int>(s);
        top = vector<int>(n);

        // Initialise the 'top' array.
        int count = s / n;
        for (int i = 0; i < n; i++)
        {
            top[i] = i * count - 1;
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (top[m - 1] >= ((m * s) / n - 1))
        {
            // Stack overflow. So, element cannot be inserted.
            return false;
        }

        // Update the index of the new top element.
        top[m - 1]++;

        // Insert the element X into the stack.
        arr[top[m - 1]] = x;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m - 1] < (m - 1) * (s / n))
        {
            // Stack is empty. So, return -1.
            return -1;
        }

        // Pop the top element of Mth stack.
        int element = arr[top[m - 1]];

        // Update the index of the new top element.
        top[m - 1]--;

        return element;
    }
};

not space optimized 

below one is optimzed

but i dont understand that how multiple stacks can be implemented is it like isnertin g value of multiple stacks just like normal array insertion and dont worry due to next top array and freespot is it
ChatGPT said:
ChatGPT
Yes, you are correct! Implementing multiple stacks in a single array is like using an array to store values for all stacks while keeping track of each stack's elements using auxiliary data structures like top, next, and freespot.

    

bus usi array me ham values ko insert kr rhe hai multiple stack ki values okk 


just do DRY RUN AND U WILL UNDERSTAND


#include <bits/stdc++.h> 
class NStack
{
public:
    int *arr;
    int *top;
    int *next;
    int freespot;
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        int n=N;
        int s=S;
        arr=new int[s];
        top=new int[n];
        next=new int[s];

        //initialze
        //firstly top array then next array;
        for(int i=0;i<n;i++){
            top[i]=-1;
        }

        for(int i=0;i<s;i++){
            next[i]=i+1;
        }

        //overwrite and change last to -1
        next[s-1]=-1;
        
        freespot=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(freespot==-1) return false;

        int index=freespot;

        freespot=next[index];

        arr[index]=x;

        next[index]=top[m-1];

        top[m-1]=index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //in pop just reverse what u do in push but firstly check if the stack is empty or not okk
        // Write your code here.
        if(top[m-1]==-1) return -1;

        int index=top[m-1];
        top[m-1]=next[index];
        int x=arr[index];
        next[index]=freespot;
        freespot=index;
        return x;
    }
};



