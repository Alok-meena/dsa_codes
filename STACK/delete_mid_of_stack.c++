Delete Mid of a Stack
Difficulty: EasyAccuracy: 53.71%Submissions: 146K+Points: 2
Given a stack s, delete the middle element of the stack without using any additional data structure.

Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from the bottom of the stack.

Note: The output shown by the compiler is the stack from top to bottom.

Examples:

Input: s = [10, 20, 30, 40, 50]
Output: [50, 40, 20, 10]
Explanation: The bottom-most element will be 10 and the top-most element will be 50. Middle element will be element at index 3 from bottom, which is 30. Deleting 30, stack will look like {10 20 40 50}.
Input: s = [10, 20, 30, 40]
Output: [40, 30, 10]
Explanation: The bottom-most element will be 10 and the top-most element will be 40. Middle element will be element at index 2 from bottom, which is 20. Deleting 20, stack will look like {10 30 40}.
Input: s = [5, 8, 6, 7, 6, 6, 5, 10, 12, 9]
Output: [9, 12, 10, 5, 6, 7, 6, 8, 5]
Constraints:
2 ≤ element of stack ≤ 105
2 ≤ s.size() ≤ 104







#include <bits/stdc++.h> 
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   stack<int>ans;
   int count=0;
   int step=(N+2)/2;

   while(count<step){
      ans.push(inputStack.top());
      inputStack.pop();
      count++;
   }

   ans.pop();

   while(!ans.empty()){
      inputStack.push(ans.top());
      ans.pop();
   }

}
O(n) t.c and s.c

class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int mid=floor((s.size()+1)/2);
        int sz=s.size();
        stack<int>st;
        
        while(mid--){
            st.push(s.top());
            s.pop();
        }
        

        if(sz%2==0) s.pop();
        if(sz%2!=0) st.pop();
        
        while(st.size()){
            s.push(st.top());
            st.pop();
        }
    }
};

t.c:-O(n) and s.c:-O(n)


we can also use recursion for it

#include <bits/stdc++.h>

void solve(stack<int>&s,int n,int count){
   if(count==n/2){
      s.pop();
      return;
   }

   int val=s.top();
   s.pop();
   solve(s,n,count+1);
   s.push(val);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count=0;
   solve(inputStack,N,count);
}

t.c:-O(n) and s.c:-O(n) okkkkkk because atmost recursive calls are n/2 ==> O(n) alright

  
