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

 

Since we are using an array/list to store the sum of every subarray of the given array/list.
And there will be (N * ( N + 1) ) / 2 such elements. So the overall space complexity will be O(N ^ 2).


