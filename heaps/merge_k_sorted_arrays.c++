You have been given ‘K’ different arrays/lists, 
which are sorted individually (in ascending order).
You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.


approach 1: using minheap just push all the elments in the min heap and then push each min element in the ans and pop it and then next min element until 
minheap becomes empty
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int>ans;

    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        for(int j=0;j<kArrays[i].size();j++){
            pq.push(kArrays[i][j]);
        }
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

time complexity: O((N * k) * log (N * k)). 
space complexity: O(N*K) due to ans vector and minheap combined



approach 2: firstly push all the elements in a vector and then sort and return 

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
   vector<int> result;
    
    // Traverse all the k vectors.
    for(int i = 0;i < k; i++)
    {
        for(int j = 0; j < kArrays[i].size(); j++)
        {
            // Add the element to the output array.
            result.push_back(kArrays[i][j]);
        }
    }
    
    // Sort the output array.
    sort(result.begin(), result.end());
    
    return result;
}
Time Complexity
O((N * K) *  log(N * K)), Where ‘K’ is the number of arrays and ‘N’ is the average number of elements in every array.

 

We are traversing all the ‘K’ arrays and then we are sorting the output array. Thus, the total time complexity will be O((N * K) *  log(N * K)). 

Space Complexity
O(N * K), Where ‘K’ is the number of arrays and ‘N’ is the average number of elements in every array.

 

We are using an array/list of size O(N * K) to store all the elements of the ‘K’ arrays/lists.
Then, we are sorting the output array in ascending order which takes at-least log(N * K) additional space. Thus, the total space complexity is O(K * N).
