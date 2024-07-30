Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.




1:brute force

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  vector<int>ans;
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          ans.push_back(mat[i][j]);
      }
  }
  
  sort(ans.begin(),ans.end());
  return ans[k-1];
}


 t.c:-O(n^2)+O(n^2*log(n^2))=o(n^2*log(n)) //AS THERE ARE TOTAL N^2 ELEMENTS TO SORT 
 and O(n^2) is s.c

we can also do it taking min heap like following 
int kthSmallest(int mat[MAX][MAX], int n, int k) {
    // Min-heap to store the smallest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert all elements into the min-heap
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            minHeap.push(mat[i][j]);
        }
    }

    // Extract the min element from the heap k-1 times
    for (int i = 0; i < k - 1; ++i) {
        minHeap.pop();
    }

    // The top element of the heap is the k-th smallest element
    return minHeap.top();
}

it has same t.c

2: using binary search and upper_bound


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
     int low=matrix[0][0];
    int high=matrix[n-1][n-1];
    
    while(low<high){
        int count=0;
        int mid=low+(high-low)/2;
        for(int i=0;i<n;i++){
            count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        
        if(count<k){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    
    return low;
    }
};

//max and min are the values
s.c:-O(1) and s.c:-O(nlogn-log(max-min) log(n) for upper bound
