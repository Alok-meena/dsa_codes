 Reverse Stack Using Recursion
Easy
40/40
Average time to solve is 21m
Contributed by
359 upvotes
Asked in companies
Problem statement
Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.



Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.



Example:
Input: [1,2,3,4,5] 
Output: [5,4,3,2,1]

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
2 1 3
Sample Output 1 :
3 1 2
Explanation to Sample Input 1 :
Reverse of a give stack is 3 1 2 where first element becomes last and last becomes first.                   
Sample Input 2 :
2
3 2
Sample Output 2 :
2 3
Constraints :
0 <= N <= 10^3
Where 'N' is the number of elements in the given stack.

Time Limit: 1 sec







#include <stack>
void reverseStack(stack<int> &stack) {
    // Write your code here
    vector<int>v;
    while(stack.size()!=0){
        v.push_back(stack.top());
        stack.pop();
    }

    int n=v.size();
    int i=0;
    while(i<n){
        stack.push(v[i++]);
    }
}

t.c:-O(n) and s.c:-O(n)


using recursion

void insertatBottom(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    int val=s.top();
    s.pop();
    insertatBottom(s,x);
    s.push(val);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return;
    }

    int val=stack.top();
    stack.pop();

    reverseStack(stack);

    insertatBottom(stack,val);
}

for ex: stack 1 2 3 4 to 1 ko nikalo bche hue ko reverse kro 4 3 2 and insert 1 at bottom simple
t.c:-O(N^2) and s.c:-O(n)
