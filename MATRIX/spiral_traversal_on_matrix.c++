
Given a rectangular matrix, traverse the matrix in spiral form.

Examples:

Input:
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:


Input: 
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.







we are also taking count so that only the no. of elements present will be traversed not extra at all;


class Solution {
  public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        
        int left=0,right=col-1;
        int top=0,bottom=row-1;
        int total=row*col;
        int count=0;
        
        while(left<=right && top<=bottom && count<total){
            //storing the elements of the first row
            for(int i=left;count<total && i<=right;i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            
            //storing elements of the last column
            for(int i=top;count<total && i<=bottom;i++){
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            
            //storing the elements of the last row
            for(int i=right;count<total && i>=left;i--){
                 ans.push_back(matrix[bottom][i]);
                 count++;
            }
            bottom--;
            
            //storing the elements of the first column
            for(int i=bottom;count<total && i>=top;i--){
                 ans.push_back(matrix[i][left]);
                 count++;
            }
            left++;
        }
        
        
        return ans;
    }
};

or if it is not a square then 
Time Complexity: O(r*c), As we are traversing over each element of the matrix once, where r is the row and c is the column of the matrix.
Space Complexity: O(r*c), To store all elements of the matrix into an output array, where r is the row and c is the column of the matrix.


Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2), for returning the answer only.
