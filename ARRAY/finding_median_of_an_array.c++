Given an array arr[] of N integers, calculate the median.

NOTE: Return the floor value of the median.
 

Example 1:

Input: N = 5
arr[] = 90 100 78 89 67
Output: 89
Explanation: After sorting the array 
middle element is the median 

Example 2:

Input: N = 4
arr[] = 56 67 30 79
Output: 61
Explanation: In case of even number of 
elements, average of two middle elements 
is the median.
The only change is here it is 0 based indexing so when n is odd so instead of n+1/2 do n/2 and 
when n is even n/2 will be th n/2+1 so to find n/2 do (n/2)-1







class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{

		    int n=v.size();
		    sort(v.begin(),v.end());
		    int index;
		    int ans;
		    if(n&1){
		       ans=v[(n)/2];
		    }
		    
		    else{
		        int value1=v[n/2];
    		    int value2=v[(n/2)-1];
    		    ans=(value1+value2)/2;
		    }
		    return ans;
		}
};



class Solution {
  public:
    double findMedian(vector<int> &arr) {
        // code here.
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n%2!=0) return arr[n/2];
        double v1=arr[n/2];
        double v2=arr[(n-1)/2];
        double v3=(v1+v2)/2;
        return v3;
    }
};

O(nlogn) is the time complexity
