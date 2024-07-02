There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

 

Example 1:


Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.




THIS IS SAME AS ROBBERY QUES WHERE HOUSES ARE ALSO IN CIRUCLAR LOOP


1:recursion
class Solution {
public:

    int solve(int index,int endIndex,vector<int>&slices,int n){
        if(n==0 || index>endIndex){
            return 0;
        }

        int take=slices[index]+solve(index+2,endIndex,slices,n-1);//+2 for skip 2 and n-- nhi n-1 karna
        int nottake=0+solve(index+1,endIndex,slices,n);//1 hi aage bdao

        return max(take,nottake);
    }
    int maxSizeSlices(vector<int>& slices) {
        //to total 3n slices hai and 3 dost hai to 3no n khayenge to mai max n slice kahunaga
        //and we just have to return its max so we pass k/3 which is max we can eat 
        int k=slices.size();
        int case1=solve(0,k-2,slices,k/3);//because ye 0 se k-2 tk chlega no include last case
        int case2=solve(1,k-1,slices,k/3);//ye 1 se k-1 tk chlega 
        return max(case1,case2);
    }
};

Time Complexity
O(2^N), where ‘N’ is the number of elements in array ‘ARR’.

 

In this approach, we use recursive functions and each recursive function is making 2 more function calls. So the total number of function calls will be 2^N. Hence, the overall time complexity is O(2^N).

Space Complexity
O(N^2), where ‘N’ is the number of elements in array ‘ARR’.

 

In this approach, we are using recursive functions, so in worst case, a total space of N*M will be used for the memory stack for each state and the value of M is  N/3. Hence, the overall space complexity is O(N*N).


2:memorization

class Solution {
public:

    int solve(int index,int endIndex,vector<int>&slices,int n,vector<vector<int>>&dp){
        if(n==0 || index>endIndex){
            return 0;
        }

        if(dp[index][n]!=-1){
            return dp[index][n];
        }

        int take=slices[index]+solve(index+2,endIndex,slices,n-1,dp);//+2 for skip 2 and n-- nhi n-1 karna
        int nottake=0+solve(index+1,endIndex,slices,n,dp);//1 hi aage bdao

        dp[index][n]=max(take,nottake);
        return dp[index][n];
    }
    int maxSizeSlices(vector<int>& slices) {
        //to total 3n slices hai and 3 dost hai to 3no n khayenge to mai max n slice kahunaga
        //and we just have to return its max so we pass k/3 which is max we can eat 
        int k=slices.size();

       //2 dp array bnenge because 2 call jaa rhi hai and index and n are changing
        vector<vector<int>>dp1(k,vector<int>(k,-1));
        int case1=solve(0,k-2,slices,k/3,dp1);

        vector<vector<int>>dp2(k,vector<int>(k,-1));
        int case2=solve(1,k-1,slices,k/3,dp2);
        return max(case1,case2);
    }
};

Time Complexity
O(N^2), where ‘N’ is the number of elements in array ‘ARR’.

 

In this approach, we are computing the value of recursive state only once and there is a total of N *M states and value of M is N/3.So,total number of states is of order O(N*N) Hence, the overall time complexity is O(N^2).

Space Complexity
O(N^2), where ‘N’ is the number of elements in array ‘ARR’.

 

In this approach, we are using extra space of O(N^2) for storing ‘DP’ array and O(N*N) space will be used by memory stack in recursion for each recursive state. Hence the overall space complexity is O(N*N).

3:bottom-up



class Solution {
public:

    int solve(int index,int endIndex,vector<int>&slices,int n,vector<vector<int>>&dp){
        if(n==0 || index>endIndex){
            return 0;
        }

        if(dp[index][n]!=-1){
            return dp[index][n];
        }

        int take=slices[index]+solve(index+2,endIndex,slices,n-1,dp);//+2 for skip 2 and n-- nhi n-1 karna
        int nottake=0+solve(index+1,endIndex,slices,n,dp);//1 hi aage bdao

        dp[index][n]=max(take,nottake);
        return dp[index][n];
    }

    int solve(vector<int>&slices){
        int k=slices.size();
        vector<vector<int>>dp1(k+2,vector<int>(k+2,0));//index+2 so size bda di;
        vector<vector<int>>dp2(k+2,vector<int>(k+2,0));

        //index pahle 0 se k-2 so rreverse 
        //n pahle k/3 se 0 so reverse and 0 ka to ho jayega uper initialize so 1 se start kr diya
        for(int index=k-2;index>=0;index--){
            for(int n=1;n<=k/3;n++){
                    int take=slices[index]+dp1[index+2][n-1];//+2 for skip 2 and n-- nhi n-1 karna
                    int nottake=0+dp1[index+1][n];//1 hi aage bdao

                    dp1[index][n]=max(take,nottake);
            }
        }

        int take=dp1[0][k/3];


        for(int index=k-1;index>=1;index--){
            for(int n=1;n<=k/3;n++){
                    int take=slices[index]+dp2[index+2][n-1];//+2 for skip 2 and n-- nhi n-1 karna
                    int nottake=0+dp2[index+1][n];//1 hi aage bdao

                    dp2[index][n]=max(take,nottake);
            }
        }

        int nottake=dp2[1][k/3];
        return max(take,nottake);
    }
    int maxSizeSlices(vector<int>& slices) {
        //to total 3n slices hai and 3 dost hai to 3no n khayenge to mai max n slice kahunaga
        //and we just have to return its max so we pass k/3 which is max we can eat 
        int k=slices.size();

        vector<vector<int>>dp1(k,vector<int>(k,-1));
        int case1=solve(0,k-2,slices,k/3,dp1);

        vector<vector<int>>dp2(k,vector<int>(k,-1));
        int case2=solve(1,k-1,slices,k/3,dp2);
        return max(case1,case2);
    }
};


Time Complexity
O(N^2), where ‘N’ is the number of elements in array ‘ARR’.

 

In this approach, we are computing the value of recursive state only once and there is a total of N *M states and value of M is N/3.So,total number of states is of order O(N*N) Hence, the overall time complexity is O(N^2).

Space Complexity
O(N^2), where ‘N’ is the number of elements in array ‘ARR’.

 

In this approach, we are using extra space of O(N^2) for storing ‘DP’ array and O(N*N) space will be used by memory stack in recursion for each recursive state. Hence the overall space complexity is O(N*N).



4:space optimized

class Solution {
public:



    int solve(vector<int>&slices){
        int k=slices.size();
        //hmara kam 3 row se bhi ho jayega
        vector<int>prev1(k+1,0);
        vector<int>curr1(k+1,0);
        vector<int>next1(k+1,0);


        vector<int>prev2(k+1,0);
        vector<int>curr2(k+1,0);
        vector<int>next2(k+1,0);

        //index pahle 0 se k-2 so rreverse 
        //n pahle k/3 se 0 so reverse and 0 ka to ho jayega uper initialize so 1 se start kr diya
        for(int index=k-2;index>=0;index--){
            for(int n=1;n<=k/3;n++){
                    int take=slices[index]+next1[n-1];//+2 for skip 2 and n-- nhi n-1 karna
                    int nottake=0+curr1[n];//1 hi aage bdao

                    prev1[n]=max(take,nottake);
            }
            next1=curr1;
            curr1=prev1;
        }

        int take=curr1[k/3];


        for(int index=k-1;index>=1;index--){
            for(int n=1;n<=k/3;n++){
                    int take=slices[index]+next2[n-1];//+2 for skip 2 and n-- nhi n-1 karna
                    int nottake=0+curr2[n];//1 hi aage bdao

                    prev2[n]=max(take,nottake);
            }
            next2=curr2;
            curr2=prev2;
        }

        int nottake=curr2[k/3];
        return max(take,nottake);
    }
    int maxSizeSlices(vector<int>& slices) {
        //to total 3n slices hai and 3 dost hai to 3no n khayenge to mai max n slice kahunaga
        //and we just have to return its max so we pass k/3 which is max we can eat 
        return solve(slices);
    }
};

t.c:-O(k^2)
s.c:-O(6*k)==O(k)

