
Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

Example 1:

Input:
m = 3, n = 4
array1[] = {1,5,9}
array2[] = {2,3,6,7}
Output: 5
Explanation: The middle element for
{1,2,3,5,6,7,9} is 5
Example 2:

Input:
m = 2, n = 4
array1[] = {4,6}
array2[] = {1,2,3,5}
Output: 3.5




1:mergin both arrays and then finding median

class Solution{
    public:
    double solve(vector<int>&v){
            int n=v.size();
		    sort(v.begin(),v.end());
		    double index;
		    double ans;
		    if(n&1){
		       ans=v[(n)/2];
		    }
		    
		    else{
		        double value1=v[n/2];
    		    double value2=v[(n/2)-1];
    		    ans=(value1+value2)/2;
		    }
		    return ans;
    }
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n=array1.size();
        int m=array2.size();
        vector<int>mergedArray(n+m);
        int i=n-1;
        int j=0;
        
        while(i>=0 && j<m){
            if(array1[i]>array2[j]){
                swap(array1[i--],array2[j++]);
            }
            else{
                break;
            }
        }
        
        for(int i=0;i<n+m;i++){
            if(i<n){
                mergedArray[i]=array1[i];
            }
            else if(i<n+m){
                mergedArray[i]=array2[i-n];
            }
        }
        
        double ans=solve(mergedArray);
        return ans;
        
        
    
    }
};

here we did many things but if we use function then

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        vector<int>c(a.begin(),a.end());
        for(auto i:b) c.push_back(i);
        
        sort(c.begin(),c.end());
        
        int n=c.size();
        
        if(n%2!=0) return c[n/2];
        
        double v1=c[n/2];
        double v2=c[(n-1)/2];
        double v3=(v1+v2)/2;
        return v3;
    }
};

same t.c and s.c

t.c:-O((n+m)log(n+m)) s.c:-O(n+m)
  
gives tle



2:optimized code



double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n1=a.size();
	int n2=b.size();

	int n=(n1+n2);
	int index2=n/2;
	int index1=index2-1;

	int i=0;
	int j=0;
	int count=0;

	int element1=-1;
	int element2=-1;

	while(i<n1 && j<n2){
		if(a[i]<b[j]){
			if(count==index1) element1=a[i];
			if(count==index2) element2=a[i];
			count++;
			i++;
		}
		else{
			if(count==index1) element1=b[j];
			if(count==index2) element2=b[j];
			count++;
			j++;
		}
	}
	while(i<n1){
		if(count==index1) element1=a[i];
		if(count==index2) element2=a[i];
		count++;
		i++;
	}

	while(j<n2){
		if(count==index1) element1=a[i];
		if(count==index2) element2=a[i];
		count++;
		j++;
	}

	if(n%2==1){
		return element2;//as it is n1+n2/2 for odd
	}

	return (double)((double)(element1+element2))/2.0;//typecast kr diya hai pahle jo value add krke aayi use then to the division
}

t.c:-O(n1+n2) and s.c:-O(1)


or can also write just like this O(n) t.c in case of same size sorted array we did 

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        int total = n + m;

        double m1 = -1, m2 = -1;

        for(int k = 0; k <= total / 2; k++) {
            m1 = m2;

            if(i == n) {
                m2 = b[j++];
            }
            else if(j == m) {
                m2 = a[i++];
            }
            else if(a[i] <= b[j]) {
                m2 = a[i++];
            }
            else {
                m2 = b[j++];
            }
        }

        if(total % 2 != 0) return m2;
        return (m1 + m2) / 2.0;
    }
};

t.c:-O(n+m) and sc:-O(1)

3rd:

#include <bits/stdc++.h>
using namespace std;

// Method to find median
double Median(vector<int>& A, vector<int>& B)
{
    int n = A.size();
    int m = B.size();
    if (n > m)
        return Median(B, A); // Swapping to make A smaller

    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;

    while (start <= end) {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA
            = (leftAsize > 0)
                  ? A[leftAsize - 1]
                  : INT_MIN; // checking overflow of indices
        int leftB
            = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA
            = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB
            = (leftBsize < m) ? B[leftBsize] : INT_MAX;

        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB)
                        + min(rightA, rightB))
                       / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB) {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
}

// Driver code
int main()
{
    vector<int> arr1 = { -5, 3, 6, 12, 15 };
    vector<int> arr2 = { -12, -10, -6, -3, 4, 10 };
    cout << "Median of the two arrays are" << endl;
    cout << Median(arr1, arr2);
    return 0;
}

Output
Median of the two arrays are
3
Time Complexity: O(min(log m, log n)): Since binary search is being applied on the smaller of the 2 arrays
Auxiliary Space: O(1)
