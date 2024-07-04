Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1



1:recursion
class Solution {
public:
    int solve(int n){
        if(n<=1){
            return 1;
        }
        int ans=0;

        //check if i is root node
        for(int i=1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }
    int numTrees(int n) {
        return solve(n);
    }
};


2:memorization

class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<=1){
            return 1;
        }

        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;

        //check if i is root node
        for(int i=1;i<=n;i++){
            ans+=solve(i-1,dp)*solve(n-i,dp);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);//size is n+1 for not tle or segmetation fault
        return solve(n,dp);
    }
};

3:bottom-up approach ye 1d vector hai so reverse ki require nhi hai

class Solution {
public:
    int solve(int n){
        vector<int>dp(n+1,0);

        dp[0]=1;
        dp[1]=1;


        //i-->no. of nodes 
        for(int i=2;i<=n;i++){
            //j--->root node
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];//TO UPER KE HISAB SE I MEANS ROOT NODE WHICH IS J AND N MEANS NO. OF NODES WHICH IS I AND UPER I IS ROOT NODE WHICH IS J SO I-J
            }
        }

        return dp[n];
    }
    int numTrees(int n) {
        return solve(n);
    }
};

t.c:-O(n^2)
s.c:-O(n)

AND IT CAN ALSO BE SOLVED USING CATALAN NUMBERS


In combinatorial mathematics, the Catalan numbers are a sequence of natural numbers that occur in various counting problems, 
often involving recursively defined objects. They are named after the French-Belgian mathematician Eugène Charles Catalan. 
1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, ...


class Solution {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return static_cast<int>(C);
    }
};
t.c:-O(n) s.c:-O(1)
  
