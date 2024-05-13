Given an array of integers, find the Kth largest sum subarray
For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.


#include <algorithm>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	vector<int>ans; // O(n2) space complexity to store the sum due to two inner loops...
	int n=arr.size();
	for(int i=0;i<n;i++){//O(n2) time complexity
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			ans.push_back(sum);
		}
	}

	sort(ans.begin(),ans.end());//O(n^2*logn) 
	return ans[ans.size()-k];

}
Time Complexity
O(N ^ 2 * log(N), where ‘N’ is the length of the given array/list.

 

We are iterating through each subarray of the given array/list using a nested loop which takes O(N ^ 2).
And then sorting the “bin” array/list which contains (N * (N + 1)) / 2 elements. Sorting takes O((N ^ 2) * log(N ^ 2)) = O((N ^ 2) * log(N)).
So the overall time complexity will be O((N ^ 2) * log(N)).

Space Complexity
O(N ^ 2), where ‘N’ is the length of the given array/list.




2nd approach:
using min heap to find the largest sum of the subarray
#include <algorithm>
#include <queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	int n=arr.size();
    priority_queue<int,vector<int>, greater<int>>pq;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(pq.size()<k){// vhi hai ki largest ke liye min heap create kiya first k sum's ko dala min heap me and then baki ke sath condition 
				pq.push(sum);
			}
			else{
				if(sum>pq.top()){//check kr li as we have done previously
					pq.pop();
					pq.push(sum);
				}
			}
		}
	}

	return pq.top();

}
 
Time Complexity
O(N ^ 2 * log(K), where ‘N’ is the length of the given array/list and ‘K’ is the given number.

 

We are iterating through each subarray of the given array/list using a
nested loop and then performing the push and pop operations on min-heap which takes O(log(K)) time. So the overall time complexity will be O( N ^ 2 * log(K).

Space Complexity
O(K), where ‘K’ is the given number.

 

Since we are using a min-heap that stores ‘K’ elements (at max). So the overall space complexity will be O(K).


