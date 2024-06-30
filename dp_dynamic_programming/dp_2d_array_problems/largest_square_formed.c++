Given a binary matrix mat of size n * m, find out the maximum length of a side of square sub-matrix with all 1s.

Example 1:

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.




1:recursion



class Solution{
public:

    int solve(vector<vector<int>>&mat,int i,int j,int &maxi){
        if(i>=mat.size() || j>=mat[0].size()){//means array ki range se hi bahar gya to return 
            return 0;
        }
        
        int right=solve(mat,i,j+1,maxi);
        int diagonal=solve(mat,i+1,j+1,maxi);
        int down=solve(mat,i+1,j,maxi);
        
        if(mat[i][j]==1){
            int ans=1+min(right,min(diagonal,down));//1 add kiya taki jo cell khudh ja rhi right diagonal down vo bhi count ho jaye
            maxi=max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code 
        int maxi=0;
        solve(mat,0,0,maxi);
        return maxi;
    }
};

t.c:-exponenetial and s.c:-O(n*m)+O(n+m)===O(n*m) n+m due to recursive calls


2:+memorization  (top-down)



class Solution{
public:

    int solve(vector<vector<int>>&mat,int i,int j,int &maxi,vector<vector<int>>&dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int right=solve(mat,i,j+1,maxi,dp);
        int diagonal=solve(mat,i+1,j+1,maxi,dp);
        int down=solve(mat,i+1,j,maxi,dp);
        
        if(mat[i][j]==1){
            dp[i][j]=1+min(right,min(diagonal,down));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code 
        vector<vector<int>>dp(n,vector<int>(m,-1));//2D array ki need thi because i and j dono change ho rhe hai 
        int maxi=0;
        solve(mat,0,0,maxi,dp);
        return maxi;
    }
};

t.c:-O(m*n) s.c:-O(m*n)


3:bottom-up 

  class Solution{
public:


    
    int solve(vector<vector<int>>&mat,int &maxi){
        int row=mat.size();
        int col=mat[0].size(); //uper ke base case me khuch store nhi kiya so yha bhi nhi karna okk
        
        vector<vector<int>>dp(row+1,vector<int>(col+1,-0));//size +1 ki if i+1 and j+1 out of range ho jaye
      
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
              int right=dp[i][j+1];
              int diagonal=dp[i+1][j+1];
              int down=dp[i+1][j];
        
              if(mat[i][j]==1){
                 dp[i][j]=1+min(right,min(diagonal,down));
                 maxi=max(maxi,dp[i][j]);
              }
              else{
                 dp[i][j]=0;
              }
            }
        }
        return dp[0][0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code 
        int maxi=0;
        solve(mat,maxi);
        return maxi;
    }
};

t.c:-O(m*n) s.c:-O(m*n)

4:space optimization


(because ham ya to current row ya next row pe depend kr rhe hai to hamne curr bnayi for present row and next for next row and after each iteration 
ham curr ko next row ke equal kr denge

class Solution{
public:


    
    int solve(vector<vector<int>>&mat,int &maxi){
        int row=mat.size();
        int col=mat[0].size();
        
        vector<int>curr(col+1,0);//i hmara current hai and i+1 next hai
        vector<int>next(col+1,0);
        
        
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
              int right=curr[j+1];
              int diagonal=next[j+1];
              int down=next[j];
        
              if(mat[i][j]==1){
                 curr[j]=1+min(right,min(diagonal,down));
                 maxi=max(maxi,curr[j]);
              }
              else{
                 curr[j]=0;
              }
            }
            next=curr;
        }
        return next[0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code 
        int maxi=0;
        solve(mat,maxi);
        return maxi;
    }
};

t.c:-O(m*n)
s.c:-O(m)

5:more optimized s.c:-O(1)


class Solution{
public:


    
     int solve(vector<vector<int> >mat,int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(i == row - 1 || j == col - 1){
                    maxi = max(maxi , mat[i][j]);
                }
                else{
                    if(mat[i][j] == 1){
                        
                    int right = mat[i][j+1];
                    int down = mat[i+1][j];
                    int diagonal = mat[i+1][j+1];
                    mat[i][j] = 1+min(right , min(down , diagonal));
                    maxi = max(maxi , mat[i][j]);
                    }
                }
            }

        }
        return maxi;
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code 
        int maxi=0;
        solve(mat,maxi);
        return maxi;
    }
};


this is also same code

class Solution{
public:


    
     int solve(int n,int m,vector<vector<int> >mat,int &maxi){
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int down = i<n-1?mat[i+1][j]:0;
                int right = j<m-1? mat[i][j+1]:0;
                int diag = i<n-1 and j<m-1? mat[i+1][j+1]:0;
                // if(dp[i][j] == 1)
                if(mat[i][j] == 1){
                    mat[i][j] = 1 + min(down,min(right, diag));
                    maxi = max(mat[i][j],maxi);
                }
            }
        }
        return maxi;
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code 
        int maxi=0;
        solve(n,m,mat,maxi);
        return maxi;
    }
};
