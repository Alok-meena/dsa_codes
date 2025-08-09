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
            ans[j][n-i-1]=matrix[i][j];//to bas khuch nhi karna before and after rotation ke index ko compare karna
            //ans me bas matrix ka j jo hai ans ke i ke equal hai and ans ka j jo hai n-i-1 se decrease ho rha hai 
        }
    }

    return ans;
}

//for acw also just do ans[n-j-1][i]=matrix[i][j] bas compare hi karna hai hame

t.c:-O(n^2) and s.c is also same



2: 
for cw
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n=matrix.size();
    //do transpose

    for(int i=0;i<n;i++){//n-1 tk hi jayenge as jo elements swap krne hai vo diagonal ke nhi hone chahihe as those will remain same
        //and j jo hai next se start karna hai as we dont want i==j means to include the diagonal elements
        for(int j=i+1;j<n;j++){
           if(i!=j) swap(matrix[i][j],matrix[j][i]);
        }
    }
    //reversing each row
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
        //can also do it like j=0;j<i;j++
        for (int j = i + 1; j < n; j++) {
            if(i!=j) swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each column
    for (int j = 0; j < n; j++) {//outer loop is to access every column
        for (int i = 0; i < n / 2; i++) {//this is to reverse every column
            swap(matrix[i][j], matrix[n - 1 - i][j]);//now dhyan se suno matrix[i][j] means j constant so same column and i change means row change krni hai 
            //and same for next col constant rkhne ke liye bad me j rakhna hai dry run karna smj jaoge
        }
    }

    return matrix;
}
