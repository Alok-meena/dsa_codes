Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. ith house has a[i] amount of money present in it.

Example 1:

Input:
n = 5
a[] = {6,5,5,7,4}
Output: 
15
Explanation: 
Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6+5+4=15.
Example 2:

Input:
n = 3
a[] = {1,5,3}
Output: 
5
Explanation: 
Loot only 2nd house and get maximum amount of 5.







the main thing which i misses and starts solving is that we have to take the alternate houses from the array but the thing is we have to select max alternate houses
means we have to maximize our answer so choose accordingly okkk

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==0) return 0;
        
        if(n==1) return arr[0];
        
        if(n==2) return max(arr[0],arr[1]);
        
        vector<int>dp(n,0);

        //then store arr[0] in dp[0] and then max of arr[0] and [1] in dp[1] then start the loop

        //hamne pahle to 0 and 1 index pe value store krva di and then arr[i] ko i-2 me add krke max count krte gye bs and at last ans return kr do
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++){

            //the thing is that we have to loot alternate houses so do add arr[i] in dp[i-2] not in dp[i-1] as i-1 and i are alternative okk
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);//dp[i-1] >dp[i-2] so do like dp[i-2]+arr[i] and dp[i-1] max out of these 
        }
        
        
        return dp[n-1];
    }
};


t.c:-O(n) and s.c:-O(1)
