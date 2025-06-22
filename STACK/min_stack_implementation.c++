










brute force :

t.c:-O(n) and s.c:-O(n)

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
	    stack<int>a;
		stack<int>b;
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			a.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(!a.empty()){
				int val=a.top();
				a.pop();
				return val;
			}
			return -1;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(!a.empty()){
				return a.top();
			}
			return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(!a.empty()){
				int min_val=INT_MAX;
				while(!a.empty()){
					min_val=min(min_val,a.top());
					b.push(a.top());
					a.pop();
				}

				while(!b.empty()){
					a.push(b.top());
					b.pop();
				}

				return min_val;
			}
			return -1;
		}
};

optimized

t.c:-O(1) and s.c:-O(2*N)=O(N)
  

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
	    stack<pair<int,int>>a;
		int mini;
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
			mini=INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			mini=min(mini,num);

			a.push({num,mini});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(!a.empty()){
				int val=a.top().first;
				a.pop();
				if(!a.empty()) mini=a.top().second;
				else mini=INT_MAX;
				return val;
			}
			return -1;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(!a.empty()){
				return a.top().first;
			}
			return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(!a.empty()){
				return a.top().second;
			}
			return -1;
		}
};

most optimized O(1) t.c and s.c

here what we are doing we are using only one variable and modifying it in a way that we can reverse it during pop and top operations okk

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
	    stack<int>s;
		int mini;
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(s.size()==0){
				s.push(num);
				mini=num;
				return;
			}

			if(num<mini){
        // we did used this formula because we want that value to be smaller than the mini but if we used 3* then it wont be possible so choose formula wisely
				s.push(2*num-mini); //now due to this if the s.top() is smaller than the min then it represents a change in the min value and modify it
				mini=num;
				 //to yha mini ko update bad me karna pahle purana mini use ho rha hai alright 
			}
			else{
				s.push(num);
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(s.size()==0) return -1;

			int tp=s.top();
			s.pop();

			if(tp<mini){
				int original=mini;
				mini=2*mini-tp; 
				return original;
			}

			return tp;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(s.size()==0) return -1;

			if(s.top()<mini) return mini;
			return s.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(s.size()==0) return -1;
			return mini;
		}
};

