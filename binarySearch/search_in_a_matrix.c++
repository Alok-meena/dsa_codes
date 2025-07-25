
below how to flatten the 2d array into a 1d array method is used but we can also use the following method for the below ques also in O(n+m) t.c O(1) s.c

bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
    int m=mat[0].size();
    
    //so here we are starting from the last col of first row or we can also start from the last row of first col
    
    int r=0,c=m-1;

    while(r<n && c>=0){
        if(mat[r][c]==target){
            return true;
        }
        else if(mat[r][c]>=target){
            c--;
        }
        else{
            r++;
        }
    }
    return false;
}

t.c:-O(n+m) and s.c:-O(1)

we can apply this method only in row and col wise both type sorted matrix alright









74. Search a 2D Matrix
Solved
Medium
Topics
Companies
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false




brute force

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};

O(row*col ) t.c ans constant space complexity



optimal soln

//in this sol we we have just traversed all of the rows in O(n) and then applying binarysearch on every row 
//means t.c:-O(nlogm)

class Solution {
public:
    bool binarysearch(vector<int>&matrix,int target){
       int s=0;
       int end=matrix.size()-1;
       while(s<=end){
          int mid=s+(end-s)/2;
          if(matrix[mid]==target){
            return true;
          }
          else if(matrix[mid]<target){
            s=mid+1;
          }
          else{
            end=mid-1;
          }
        }
        return false;               
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int row=matrix.size();
        int col=matrix[0].size();

        for(int i=0;i<row;i++){
            if(target>=matrix[i][0] && target<=matrix[i][col-1]){
                return binarysearch(matrix[i],target);//ex matrix[1] means the 1st row 
            }
            else{
                continue;
            }
            
        }
        return false;
    }
};

t.c:-O(n*log(m)) constant space complexity


most optimal

class Solution {
public:
   
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int row=matrix.size();
        int col=matrix[0].size();

        int start=0;
        int end=(row*col)-1;
        
        while(start<=end){
            int mid=(end+start)/2;
            /////we should have to do it with col only because logically it should be col not row
            int element=matrix[mid/col][mid%col];
            if(element==target){
                return true;
            }
            else if(element<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};

t.c:-O(log(n*m))

most optimal
