Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one. 

You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

Example 1:

Input: nums = {3,2,2,5}, k = 6
Output: 10
Explanation: Given a line can have 6
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4
So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10.
As in the first line word length = 3 thus
extra spaces = 6 - 3 = 3 and in the second line
there are two word of length 2 and there already
1 space between two word thus extra spaces
= 6 - 2 -2 -1 = 1. As mentioned in the problem
description there will be no extra spaces in
the last line. Placing first and second word
in first line and third word on second line
would take a cost of 02 + 42 = 16 (zero spaces
on first line and 6-2 = 4 spaces on second),
which isn't the minimum possible cost.
Example 2:

Input: nums = {3,2,2}, k = 4
Output: 5
Explanation: Given a line can have 4 
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 2
Line number 3: From word no. 3 to 3
Same explaination as above total cost
= (4 - 3)2 + (4 - 2)2 = 5.







1:recursion


class Solution {
public:
    int solve(int i,int rem,vector<int>&nums,int &k){
        if(i==nums.size()){
            return 0;//we dont have to count the last line spaces;
        }
        
        // if(dp[i][rem]!=-1){
        //     return dp[i][rem];
        // }

         TO NICHE IF ME AND CHOICE 1 ME HAM HAR BAR NEW LINE ME LIKH RHE THE THAT'S WHY WE ARE DOING K-ARR[I]-1 NO UPDATING REM AS WE ARE NOT WRITING IN THE SAME LINE
        int ans;
        if(nums[i]>rem){//rem ke corresponding hi check karna hai
            ans=(rem+1)*(rem+1)+solve(i+1,k-nums[i]-1,nums,k);
            //means current line me word nhi likh skte hai to 
            //next me likhenge to rem ko k-nums[i]-1 se update kiya hai for next line 
            //only
        }
        else{
            //to uper vale case me to ham likh hi nhi skte the 
            //aor yha choice1 me likh to skte hai but ham curent line me likh nhi rhe hai
            //as we have to take all possible possibilites
            
            //in this we dont write in the current line 
            //ex k=6 and line contain cp and coder is to write so unable to write 
            //to ise next line me likhna hi hoga that's why we considered rem+1*rem+1
            //as bche hue sare space ko consider karna hai
            int choice1=(rem+1)*(rem+1)+solve(i+1,k-nums[i]-1,nums,k);
            
            //aor yha pe ham same line me likh rhe hi ex coder ki jagah go hota 
            //to jitna rem hai usme se 1 to cp_go ke bich ka diff and cp ki length
            //so update rem as rem-arr[i]-1 okk and yha pe ham cost caluclate nhi 
            //krenge cost only tabhi calulate hogi jab ham next line me jaye aor
            //current line me spaces bach jayenge
            int choice2=solve(i+1,rem-nums[i]-1,nums,k);
            ans=min(choice1,choice2);
        }
        
        // dp[i][rem]=ans;
        return ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        // vector<vector<int>>dp(nums.size(),vector<int>(k+1,-1));
        return solve(0,k,nums,k);
    } 
};

t.c:-O(2^n) and s.c:-O(n)


dont know but why only this code is working and no else is working 

class Solution {
public:
    int dp[505][2005]; //the size is given in the constrainnts
    int solve(int i,int rem,vector<int>&nums,int &k){
        if(i==nums.size()){
            return 0;//we dont have to count the last line spaces;
        }
        
        if(dp[i][rem]!=-1){
            return dp[i][rem];
        }
        
        int ans;
        if(nums[i]>rem){//rem ke corresponding hi check karna hai
            ans=(rem+1)*(rem+1)+solve(i+1,k-nums[i]-1,nums,k);
            //means current line me word nhi likh skte hai to 
            //next me likhenge to rem ko k-nums[i]-1 se update kiya hai for next line 
            //only
        }
        else{
            //to uper vale case me to ham likh hi nhi skte the 
            //aor yha choice1 me likh to skte hai but ham curent line me likh nhi rhe hai
            //as we have to take all possible possibilites
            
            //in this we dont write in the current line 
            //ex k=6 and line contain cp and coder is to write so unable to write 
            //to ise next line me likhna hi hoga that's why we considered rem+1*rem+1
            //as bche hue sare space ko consider karna hai
            int choice1=(rem+1)*(rem+1)+solve(i+1,k-nums[i]-1,nums,k);
            
            //aor yha pe ham same line me likh rhe hi ex coder ki jagah go hota 
            //to jitna rem hai usme se 1 to cp_go ke bich ka diff and cp ki length
            //so update rem as rem-arr[i]-1 okk and yha pe ham cost caluclate nhi 
            //krenge cost only tabhi calulate hogi jab ham next line me jaye aor
            //current line me spaces bach jayenge
            int choice2=solve(i+1,rem-nums[i]-1,nums,k);
            ans=min(choice1,choice2);
        }
        
        dp[i][rem]=ans;
        return dp[i][rem];
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        // vector<vector<int>>dp(nums.size(),vector<int>(k+1,-1));
        memset(dp,-1,sizeof(dp));
        //memset is used to set all of the values of a data structure to a value ex here -1 is set and sizeof(dp) is donee to access whole size of dp declared
        return solve(0,k,nums,k);
    } 
};


MEMSET IS NOT USED WITH VECTOR AS VECTOR HAS IT'S OWN M/M MANAGEMENT 

  
Global Array Declaration: Ensures that dp is available to all parts of the program and can be used to 
store and retrieve intermediate results across recursive calls.


memset is most suitable for use with raw arrays or POD (Plain Old Data) types, such as int, char, or float. Here’s when and how you can use memset effectively:



t.c:-O(n*k) and s.c:-O(n*m)



example how to use memset()

int main()
{
    char str[] = "geeksforgeeks";
    // setting each byte of memory of str to 't' using
    // memset
    memset(str, 't', sizeof(str));
  
    cout << str;
  
    return 0;
}

Output
tttttttttttttt
