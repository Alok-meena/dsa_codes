Next Greater Element
Difficulty: MediumAccuracy: 32.95%Submissions: 415K+Points: 4
Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Examples

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.
Input: arr[] = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.
Input: arr[] = [10, 20, 30, 50]
Output: [20, 30, 50, -1]
Explanation: For a sorted array, the next element is next greater element also exxept for the last element.
Input: arr[] = [50, 40, 30, 10]
Output: [-1, -1, -1, -1]
Explanation: There is no greater element for any of the elements in the array, so all are -1.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 109



class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        vector<int>ans;
        
        int n=arr.size();
        
        for(int i=n-1;i>=0;i--){
            int next_greater=-1;
            int j=i+1;
            while(j<n){
                if(arr[j]>arr[i]){
                    next_greater=arr[j];
                    break;
                }
                j++;
            }
            
            ans.push_back(next_greater);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

t.c:-O(n^2) and s.c:-O(n)


#include <stack>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	// Write your code here
	vector<int>ans(n);
	stack<int>s;

	for(int i=n-1;i>=0;i--){
		while(s.size()!=0 && s.top()<=arr[i]){
			s.pop();
		}

		if(s.size()==0){
			ans[i]=-1;
		}
		else{
			ans[i]=s.top();
		}
		s.push(arr[i]);
	}

	return ans;
}

t.c:-O(2*N) AND S.C:-o(N)
