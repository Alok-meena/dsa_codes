Reverse First K elements of Queue
Difficulty: EasyAccuracy: 81.28%Submissions: 136K+Points: 2
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

Example 1:

Input:
5 3
1 2 3 4 5
Output: 
3 2 1 4 5
Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.
Example 2:

Input:
4 4
4 3 2 1
Output: 
1 2 3 4
Explanation: 
After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.
Your Task:
Complete the provided function modifyQueue() that takes queue and K as parameters and returns a modified queue. The printing is done automatically by the driver code.

Expected Time Complexity : O(N)
Expected Auxiliary Space : O(K)

Constraints:
1 <= K <= N <= 105





class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        vector<int>ans;
        if(k==1) return q;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        
        reverse(ans.begin(),ans.begin()+k);
        for(auto i:ans){
            q.push(i);
        }
        return q;
    }
};


t.c:-O(n) and s.c:-O(n) 

and can also use a stack


class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        if(k>arr.size()) return q;
        int n=q.size();
        stack<int>s;

        //push first k elements into stack then push again into queue
        
        for(int i=0;i<k;i++){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }

        //and now put n-k elements from start to the end in queue itself
        
        for(int i=0;i<n-k;i++){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};

O(k) + O(k) + O(n-k) so same t.c and s.c
