Dynamic programming is a algorithmic technique that solves complex problems by breaking them down into smaller subproblems and storing their solutions for future use.
It is particularly effective for problems that contains overlapping subproblems and optimal substructure.2


approach 1: using recursion 


#include<bits/stdc++.h>
#include <vector>
using namespace std;


int fib(int n,vector<int>&dp){
        if(n<=1){
                return n;
        }


        return fib(n-1,dp)+fib(n-2,dp);
}
int main()
{
        int n;
        cin>>n;
        vector<int>dp(n+1);

        
        for(int i=0;i<=n;i++){
                dp[i]=-1;
        }

        int ans=fib(n,dp);
        cout<<ans;
}

Time Complexity
O(2^N), where ‘N’ is the number for which we are finding its equivalent Fibonacci.

 this is due to this 
  fib(5)
  ├── fib(4)
  │     ├── fib(3)
  │     │     ├── fib(2)
  │     │     │     ├── fib(1) = 1
  │     │     │     └── fib(0) = 0
  │     │     └── fib(1) = 1
  │     └── fib(2)
  │           ├── fib(1) = 1
  │           └── fib(0) = 0
  └── fib(3)
        ├── fib(2)
        │     ├── fib(1) = 1
        │     └── fib(0) = 0
        └── fib(1) = 1

and in 2nd approach we don't need to do this as we are storing this in a array and finding in the array will be in O(1) okk so O(N) in below approach

 

As our function will be called exponentially.

Space Complexity
O(N),  where ‘N’ is the given number.  

As recursion uses a stack of size ‘N’






approach 2: using dp by storing the result and reducing the no. of function calls

//this is using top-down approach and then recursion and then memorization

#include<bits/stdc++.h>
#include <vector>
using namespace std;

int fib(int n,vector<int>&dp){
        if(n<=1){
                return n;
        }

        //step 3
        if(dp[n]!=-1){
                return dp[n];
        }

        
        //step 2
        dp[n]=fib(n-1,dp)+fib(n-2,dp);
        return dp[n];
}
int main()
{
        int n;
        cin>>n;
        vector<int>dp(n+1);

        //step 1
        for(int i=0;i<=n;i++){
                dp[i]=-1;
        }

        int ans=fib(n,dp);
        cout<<ans;
}


Time Complexity
O(N), where ‘N’ is the number for which we are finding its equivalent Fibonacci.

 

As our loop will run for ‘N’ times.

Space Complexity
O(N),  where ‘N’ is the number for which we are finding its equivalent Fibonacci.

 

As we are using an array (dp) of size ‘N’ for storing values.



2nd thing bottom-up approach 

here tabulation is used:--Each cell in the table represents a solution to a subproblem, and these cells are filled in order, 
which allows the solving of complex problems by breaking it down into simpler manageable sub-problems.

#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
        int n;
        cin>>n;
        vector<int>dp(n+1);

        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
        }
        cout<<dp[n];
}
t.c:- O(N) and s.c:- O(N)


3rd approach : space optimized

#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
        int n;
        cin>>n;
       
        int prev1=0;
        int prev2=1;

        if(n==0){
                cout<<"0";
        }
        
        for(int i=0;i<n;i++){
                int curr=prev1+prev2;
                prev1=prev2;
                prev2=curr;
        }

        cout<<prev;
}

t.c:-O(N) and s.c:-O(1)
