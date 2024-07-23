Given an array arr[] that contains n integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Note: It is guarenteed that the output fits in 64-bit integer.

Examples

Input: arr[] = {6, -3, -10, 0, 2}, n = 5
Output: 180
Explanation:  The subarray [6, -3, -10] gives max product as 180.
Input: arr[] = {2, 3, 4, 5, -1, 0}, n = 6
Output: 120
Explanation: The subarray [2, 3, 4, 5] gives max product as 120.
Input: arr[] = {2, 3, 4}, n = 3
Output: 24
Explanation: For an array with all positive elements, the result is product of all elements.


class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long ans=INT_MIN;
	    for(int i=0;i<n;i++){
	        long long product=1;
	        for(int j=i;j<n;j++){
	            product=product*arr[j];
	            ans=max(ans,product);
	        }
	    }
	    return ans;
	}
};

O(n^2) and constant space complexity



2:
//Back-end complete function template for C++

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long maxi=INT_MIN;
	    long long prefix=1;
	    long long suffix=1;
	    
	    for(int i=0;i<n;i++){
	        
	        
	        prefix=prefix*arr[i];
	        suffix=suffix*arr[n-i-1];
	        
	   
	        maxi=max(maxi,max(prefix,suffix));
	        if(prefix==0){
	            prefix=1;
	        }
	        if(suffix==0){
	            suffix=1;
	        }
	    }
	    return maxi;
	}
};


Time Complexity: O(n), where n is the size of the input array. It iterates through the array only once.
Space Complexity: O(1) since the algorithm uses a constant amount of extra space regardless of the input size. It doesn't use any additional data structures that depend on the input size.

Useful links to help you understand the concepts of this problem:
