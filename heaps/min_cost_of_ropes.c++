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


 class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(long long i=0;i<n;i++){ // O(logn) for insertion
            pq.push(arr[i]);
        }
        long long sum=0;
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            long long ans=a+b;
            sum+=ans;
            pq.push(ans); // we need to insert n-1 elements to get a single rope so O((n-1)*logn)
        }
        return sum;
    }
};

Expected Time Complexity : O(nlogn) //n insertion kiye
Expected Auxilliary Space : O(n) // because pq bnayi aor element dale n times

