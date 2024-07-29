Rotate a matrix by 90 degree in clockwise direction without using any extra space







//to rotate acw
#include <bits/stdc++.h> 
vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n=matrix.size();
    vector<vector<int>>ans(n,vector<int>(n));

    int col=n-1;
    for(int i=0;i<n;i++){
        int row=0;
        for(int j=0;j<n;j++){
            ans[i][j]=matrix[row++][col];
        }
        col--;
    }

    return ans;
}

//to rotate cw
#include <bits/stdc++.h> 
vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n=matrix.size();
    vector<vector<int>>ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        int row=0;
        for(int j=0;j<n;j++){
            ans[j][n-i-1]=matrix[i][j];
        }
    }

    return ans;
}

t.c:-O(n^2) and s.c is also same



2: 
for cw
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n=matrix.size();
    //do transpose

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(i!=j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

    }
};

t.c:-[O(N*N/2) + O(N/2*N/2)] and constant space complexity



for acw just reverse the columns

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each column
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n / 2; i++) {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }

    return matrix;
}
