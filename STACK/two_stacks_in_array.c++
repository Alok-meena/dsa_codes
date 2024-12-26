Two Stacks in an Array
Difficulty: MediumAccuracy: 56.49%Submissions: 162K+Points: 4
Your task is to implement  2 stacks in one array efficiently. You need to implement 4 methods.

twoStacks : Initialize the data structures and variables to be used to implement  2 stacks in one array.
push1 : pushes element into the first stack.
push2 : pushes element into the second stack.
pop1 : pops an element from the first stack and returns the popped element. If the first stack is empty, it should return -1.
pop2 : pops an element from the second stack and returns the popped element. If the second stack is empty, it should return -1.

Examples:

Input:
push1(2)
push1(3)
push2(4)
pop1()
pop2()
pop2()
Output: [3, 4, -1]
Explanation:
push1(2) the stack1 will be {2}
push1(3) the stack1 will be {2,3}
push2(4) the stack2 will be {4}
pop1()   the poped element will be 3 from stack1 and stack1 will be {2}
pop2()   the poped element will be 4 from stack2 and now stack2 is empty
pop2()   the stack2 is now empty hence returned -1.
Input:
push1(1)
push2(2)
pop1()
push1(3)
pop1()
pop1()
Output: [1, 3, -1]
Explanation:
push1(1) the stack1 will be {1}
push2(2) the stack2 will be {2}
pop1()   the poped element will be 1 from stack1 and stack1 will be empty
push1(3) the stack1 will be {3}
pop1()   the poped element will be 3 from stack1 and stack1 will be empty
pop1()   the stack1 is now empty hence returned -1.
Input:
push1(2)
push1(3)
push1(4)
pop2()
pop2()
pop2()
Output: [-1, -1, -1]
Explanation:
push1(2) the stack1 will be {2}
push1(3) the stack1 will be {2,3}
push1(4) the stack1 will be {2,3,4}
pop2()   the stack2 is empty hence returned -1.
pop2()   the stack2 is empty hence returned -1.
pop2()   the stack2 is empty hence returned -1.
Constraints:
1 <= number of queries <= 104
1 <= number of elements in the stack <= 100
The sum of the count of elements in both the stacks < size of the given array






class twoStacks {
  public:
    int *arr;
    int top1;
    int top2;

    twoStacks() {
        arr=new int[100];
        top1=-1;
        top2=100;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(top1<top2-1){
            top1++;
            arr[top1]=x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        // code here
        if(top1<top2-1){
            top2--;
            arr[top2]=x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        // code here
        if(top1>=0){
            int val=arr[top1];
            top1--;
            return val;
        }
        else{
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(top2<100){
            int val=arr[top2];
            top2++;
            return val;
        }
        else{
            return -1;
        }
    }
};
