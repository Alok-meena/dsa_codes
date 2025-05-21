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


class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        priority_queue<int>pq;
        int n=matrix.size();


        //we are just mantaining a k size window and just have to return kth ele right so remove all ele's greater than that kth ele alright and at the end we 
        //will got our answer 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }
};


this is will work even if the matrix is not sorted alright

t.c:-O(n*mlogk) it is much efficient when k is much smaller than n^2 alright means all elements

2: using binary search and upper_bound


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
     int low=matrix[0][0];
    int high=matrix[n-1][n-1];
      int ans=-1;
    
    while(low<high){
        int count=0;
        int mid=low+(high-low)/2;
        for(int i=0;i<n;i++){
            count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        
        if(count<k){
            low=mid+1;
        }
        else if(count>=k){
            ans=mid;
            high=mid;
        }
    }
    
    return low; //either return this or store in ans variable and return 
    }
};

//max and min are the values
s.c:-O(1) and s.c:-O(nlogn-log(max-min) log(n) for upper bound


WHAT IS ARRAY IS GIVEN INSTEAD OF VECTOR:-----------


  #include <algorithm>
int Upperbound(int matrix[],int n,int value){
    int low=0;
    int high=n;//here do this because yha ager sare array ke element <mid hue to that's why we want count of elements not their index so set it to n ans similar for ans
    int ans=n;
    while(low<high){
        int mid=low+(high-low)/2;
        if(value<matrix[mid]){
            ans=mid;
            high=mid;//taki har ek possibility check ho paye
        }
        else{
            low=mid+1;
        }
    }
    
    return ans;
}
int kthSmallest(int mat[MAX][MAX], int n, int k) {
    // Min-heap to store the smallest elements
    int low=mat[0][0];
    int high=mat[n-1][n-1];
    
    while(low<high){
        int count=0;
        int mid=low+(high-low)/2;
        for(int i=0;i<n;i++){
            count+=Upperbound(mat[i],n,mid);
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
