You have n books, each with arr[i] a number of pages. m students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of the maximum number of pages in a book allotted to a student should be the minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: n = 4, arr[] = [12, 34, 67, 90], m = 2
Output: 113
Explanation: Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113, which is selected as the output.
Input: n = 3, arr[] = [15, 17, 20], m = 5
Output: -1
Explanation: Allocation can not be done.
Expected Time Complexity: O(n logn)
Expected Auxilliary Space: O(1)







bool isPossible(vector<int>& arr, int n, int m,int mid){
    int studentCount = 1;
    int pageSum = 0;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
                return false;
        }
            pageSum = arr[i];
        }
        
       
    }
    return true;
}


int findPages(vector<int>& arr, int n, int m) {
    if(m>n){
        return -1;
    }
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            //then go to the left subarray if answer exists at mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    
    return ans;
}
