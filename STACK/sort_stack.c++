 Sort a Stack
Easy
40/40
Average time to solve is 10m
Contributed by
460 upvotes
Asked in companies
Problem statement
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

We can only use the following functions on this stack S.

is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
Note :
1) Use of any loop constructs like while, for..etc is not allowed. 
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 100
1 <=  'N' <= 100
1 <= |'V'| <= 10^9

Where |V| denotes the absolute value of any stack element.

Time limit: 1 sec
Sample Input 1:
1
5
5 -2 9 -7 3
Sample Output 1:
9 5 3 -2 -7
Explanation of Sample Input 1:
9 Is the largest element, hence it’s present at the top. Similarly 5>3, 3>-2 and -7 being the smallest element is present at the last. 
Sample Input 2:
1
5
-3 14 18 -5 30
Sample Output 2:
30 18 14 -3 -5
Explanation of Sample Input 2:
30 is the largest element, hence it’s present at the top. Similarly, 18>14, 14>-3 and -5 being the smallest element is present at the last.





#include <bits/stdc++.h> 
void sortStack(stack<int> &stack)
{
	// Write your code here
	vector<int>v;
	while(stack.size()!=0){
		v.push_back(stack.top());
		stack.pop();
	}

	sort(v.begin(),v.end());

	for(auto i:v){
		stack.push(i);
	}
}

t.c:-O(nlogn) and s.c:-O(N)


using recursion

#include <bits/stdc++.h> 

void sortInsert(stack<int>&s,int num){
	if(s.empty() || s.top()<num){
		s.push(num);
		return;
	}

	int val=s.top();
	s.pop();
	sortInsert(s,num);
	s.push(val);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	//jab tk stack empty nhi hoga jao 
	//then return me values ko sorted way me inesrt kro means

	//bs insert the value in stack if it's top values is less than current to be inserted value o/w go down until stack is empty
	if(stack.empty()){
		return;
	}

	int val=stack.top();
	stack.pop();
	sortStack(stack);

	sortInsert(stack,val);
}

t.c:-O(N^2) and s.c:-O(n)
