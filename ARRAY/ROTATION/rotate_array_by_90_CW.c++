







1) brute force t.c:-O(n^2) AND S.C:-O(n^2)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate_clockwise(vector<vector<int>>&v){
    int n=v.size();
    int m=v[0].size();
    vector<vector<int>>ans(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][n-i-1]=v[i][j];
        }
    }
  
    return ans;
}

int main(){
    vector<vector<int>>v={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>>ans=rotate_clockwise(v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

2) t.c:-O(n^2) and s.c:-O(1) but this is possible only for a square matrix as
first we will do transpose and then reverse each row 


void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n=mat.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
    
}

but to do transpose in a rectagular matrix we need extra space always


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(int m, int n, vector<vector<int>> &mat) {
    // Initialize the transposed matrix with dimensions (n, m)
    vector<vector<int>> transposed(n, vector<int>(m));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = mat[i][j];
        }
    }
    
    return transposed;
}
we did so because then rows (n) and columns(m) will be interchanged and rows will become column and column will become row 
