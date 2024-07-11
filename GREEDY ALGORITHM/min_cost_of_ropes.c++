

There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 

Example 1:

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
Explanation:
We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3.
Which makes the array {4, 5, 6}. Cost of
this operation 2+3 = 5. 
2) Now connect ropes of lengths 4 and 5.
Which makes the array {9, 6}. Cost of
this operation 4+5 = 9.
3) Finally connect the two ropes and all
ropes have connected. Cost of this 
operation 9+6 =15
Total cost for connecting all ropes is 5
+ 9 + 15 = 29. This is the optimized cost
for connecting ropes. 
Other ways of connecting ropes would always 
have same or more cost. For example, if we 
connect 4 and 6 first (we get three rope of 3,
2 and 10), then connect 10 and 3 (we get
two rope of 13 and 2). Finally we
connect 13 and 2. Total cost in this way
is 10 + 13 + 15 = 38.


we can do it by sorting also but pq gives O(1) to find min element so we use it



class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        long long cost=0;
        while(pq.size()>1){
            long long first=pq.top();
            pq.pop();
            
            long long second=pq.top();
            pq.pop();
            
            long long mergelength=first+second;
            cost=cost+mergelength;
            pq.push(mergelength);
        }
        return cost;
    }
};


it is like this for 1 2 3
    long long first = pq.top(); // first = 1
pq.pop(); // pq = [2, 3]

long long second = pq.top(); // second = 2
pq.pop(); // pq = [3]

long long mergelength = first + second; // mergelength = 1 + 2 = 3
cost += mergelength; // cost = 0 + 3 = 3

pq.push(mergelength); // pq = [3, 3]

that's why we did pq.size()>1 o/w we will get wrong ans as we want 2 elements in the pq to go on
