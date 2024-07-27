





class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int>ans;
        vector<vector<int>>ans2(N,vector<int>(N));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans.push_back(Mat[i][j]);
            }
        }
        
        sort(ans.begin(),ans.end());
        int k=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans2[i][j]=ans[k++];
            }
        }
        
        return ans2;
        
    }
};

t.c:-O(n^2) and s.c:-O(n^2)+O(n)








  Summary of Differences
Empty Declaration (vector<vector<int>> arr;):

Creates an empty 2D vector.
Used when the size of the matrix is not known at compile-time or when the matrix will be dynamically populated.
Initialized Declaration (vector<vector<int>> arr(n, vector<int>(n));):

Creates and initializes a 2D vector with dimensions n x n.
Used when you know the size of the matrix in advance and want to initialize all elements to a default value.
When to Use Each
Use an empty declaration when the size or contents of the 2D vector are not known ahead of time or when you plan to construct the matrix dynamically.
Use an initialized declaration when the size of the matrix is known, and you want to allocate memory and initialize the matrix with a specific size from the start.
