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



 
 can do like this also


are normally use robbery vala ques code na 

class Solution {
public:
   int solve(int idx,int k,vector<int>&house){
    if(k==0) return 0;

    if(idx>=house.size()) return 0;


    int exc=solve(idx+1,k,house)+0;

    int inc=solve(idx+2,k-1,house)+house[idx];

    return max(exc,inc);
}

    int maxSizeSlices(vector<int>& valueInHouse) {
        int n=valueInHouse.size();
    
    if(n==1){
        return valueInHouse[0];
    }

    vector<int>start,end;
    for(int i=0;i<n;i++){
        if(i!=n-1){
            start.push_back(valueInHouse[i]);
        }
        if(i!=0){
            end.push_back(valueInHouse[i]);
        }
    }
    int k=n/3;
    return max(solve(0,k,start),solve(0,k,end));
    }
};


memo

class Solution {
public:
   int solve(int idx,int k,vector<int>&house,vector<vector<int>>&dp){
    if(k==0) return 0;

    if(idx>=house.size()) return 0;

    if(dp[idx][k]!=-1) return dp[idx][k];


    int exc=solve(idx+1,k,house,dp)+0;

    int inc=solve(idx+2,k-1,house,dp)+house[idx];

    return dp[idx][k]=max(exc,inc);
}

    int maxSizeSlices(vector<int>& valueInHouse) {
        int n=valueInHouse.size();
    
    if(n==1){
        return valueInHouse[0];
    }

    vector<int>start,end;
    for(int i=0;i<n;i++){
        if(i!=n-1){
            start.push_back(valueInHouse[i]);
        }
        if(i!=0){
            end.push_back(valueInHouse[i]);
        }
    }
    int k=n/3;

    vector<vector<int>>dp1(n+1,vector<int>(k+1,-1));
    vector<vector<int>>dp2(n+1,vector<int>(k+1,-1));
    return max(solve(0,k,start,dp1),solve(0,k,end,dp2));
    }
};

to bhai log same to same house robbery vala ques just we have to stop if we eat n/3 slices alright as each will get n/3 only 

class Solution {
public:
    int solve(int i,int k,int count,vector<int>&slices,int endindex){
        if(i>=endindex or count==k) return 0;

        int take=slices[i]+solve(i+2,k,count+1,slices,endindex);
        int nottake=0+solve(i+1,k,count,slices,endindex);
        return max(take,nottake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size()/3;
        int case1=solve(0,k,0,slices,slices.size()-1);
        int case2=solve(1,k,0,slices,slices.size());

        return max(case1,case2);
    }
};

here instead of n-1 we used count alright

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
    int solve(int i,int k,int count,vector<int>&slices,int endindex,vector<vector<int>>&dp){
        if(i>=endindex or count==k) return 0;

        if(dp[i][count]!=-1) return dp[i][count];

        int take=slices[i]+solve(i+2,k,count+1,slices,endindex,dp);
        int nottake=0+solve(i+1,k,count,slices,endindex,dp);
        return dp[i][count]=max(take,nottake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size()/3;
        vector<vector<int>>dp1(slices.size(),vector<int>(k+1,-1));
        vector<vector<int>>dp2(slices.size(),vector<int>(k+1,-1));

        int case1=solve(0,k,0,slices,slices.size()-1,dp1);
        int case2=solve(1,k,0,slices,slices.size(),dp2);

        return max(case1,case2);
    }
};

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

int maxSizeSlices(vector<int>& slices) {
        int k=slices.size()/3;
        vector<vector<int>>dp1(slices.size()+2,vector<int>(k+2,0));
        vector<vector<int>>dp2(slices.size()+2,vector<int>(k+2,0));

        for(int i=slices.size()-2;i>=0;i--){
            for(int count=k-1;count>=0;count--){ //start from k-1 because if count==k then it is already set to 0
                int take=slices[i]+dp1[i+2][count+1];
                int nottake=0+dp1[i+1][count];
                dp1[i][count]=max(take,nottake);
            }
        }

        int case1=dp1[0][0]; //and here same as we pass 0,0 so store it only alright

        for(int i=slices.size()-1;i>=1;i--){
            for(int count=k-1;count>=0;count--){
                int take=slices[i]+(i+2<slices.size() ? dp2[i+2][count+1]:0);
                int nottake=0+dp2[i+1][count];
                dp2[i][count]=max(take,nottake);
            }
        }

        int case2=dp2[1][0];




        return max(case1,case2);
    }



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

int maxSizeSlices(vector<int>& slices) {
        int k=slices.size()/3;
        int n=slices.size();
   

        vector<int>prev1(k+2,0);
        vector<int>next1(k+2,0);
        vector<int>curr1(k+2,0);
        vector<int>prev2(k+2,0);
        vector<int>next2(k+2,0);
        vector<int>curr2(k+2,0);


        for(int i=slices.size()-2;i>=0;i--){
            for(int count=k-1;count>=0;count--){
                int take=slices[i]+next1[count+1];
                int nottake=0+curr1[count];
                prev1[count]=max(take,nottake);
            }
            next1=curr1;
            curr1=prev1;
        }

        int case1=curr1[0];

        for(int i=slices.size()-1;i>=1;i--){
            for(int count=k-1;count>=0;count--){
                int take=slices[i]+next2[count+1];
                int nottake=0+curr2[count];
                prev2[count]=max(take,nottake);
            }
            next2=curr2;
            curr2=prev2;
        }

        int case2=curr2[0];
        return max(case1,case2);
    }


alright

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

