Given an array a[ ] of n integers, find the Length of the Longest Strictly Increasing Subsequence.

A sequence of numbers is called "strictly increasing" when each term in the sequence is smaller than the term that comes after it.

Example 1:

Input: n = 6, a[ ] = {5,8,3,7,9,1}
Output: 3
Explanation: There are more than one LIS in this array.  
One such Longest increasing subsequence is {5,7,9}.



    CAN TAKE ANY ELEMENT WITH OTHER ELEMENT BUT THERE ORDER IN THE ARRAY SHOULD BE MAINTAINED

    Expected Time Complexity : O( n*log(n) )
    Expected Auxiliary Space: O(n)




class Solution
{
    public:
    
    int solve(int n,int a[],int currindex,int previndex){
        if(currindex==n){
            return 0;
        }
        
        int include=0;
        //include case
        if(previndex==-1 || a[previndex]<a[currindex]){//2 condn ek ki pahla element hai and 2nd uske bad vala
            include=1+solve(n,a,currindex+1,currindex);//curr ko aage bda do and prev 
            //ab curr ke equal ho jayega
        }
        
        //exclude case
        int exclude=0+solve(n,a,currindex+1,previndex);//curr to aage bd gya but not prev vo vhi rhega
        
        return max(include,exclude);
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       return solve(n,a,0,-1);
    }
};

2:memorization



yha dp me previndex+1 kr diya hai because -1 pass kiya tha to invalid index ho jata so +1 se 0 to n tk chla jayega
class Solution
{
    public:
    
    int solve(int n,int a[],int currindex,int previndex,vector<vector<int>>&dp){
        if(currindex==n){
            return 0;
        }
        
        if(dp[currindex][previndex+1]!=-1){
            return dp[currindex][previndex+1];
        }
        
        
        int include=0;
        //include case
        if(previndex==-1 || a[previndex]<a[currindex]){//2 condn ek ki pahla element hai and 2nd uske bad vala
            include=1+solve(n,a,currindex+1,currindex,dp);//curr ko aage bda do and prev 
            //ab curr ke equal ho jayega
        }
        
        //exclude case
        int exclude=0+solve(n,a,currindex+1,previndex,dp);//curr to aage bd gya but not prev vo vhi rhega
        
        dp[currindex][previndex+1]=max(include,exclude);
        return dp[currindex][previndex+1];
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //size n hi li because 0 se n-1 tk curr and -1 se n-1 tk prev ja rha hai to total n element ho gye hai
       //because 0 se leke n-1 = n elemnt and -1 se n-1 tk n+1 eleemnts
       vector<vector<int>>dp(n,vector<int>(n+1,-1));//because curr and prev are changing
       return solve(n,a,0,-1,dp);
    }
};

t.c:-O(n^2)
s.c:-O(n^2)


3:bottom-up



class Solution
{
    public:
    

    int solve(int n,int a[]){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));//to code me hamne curr+1 kiya hai jbki start
        //n-1 se kiya to size n+1 krn hogi curr ki bhi
        
        for(int currindex=n-1;currindex>=0;currindex--){
            for(int previndex=currindex-1;previndex>=-1;previndex--){
                int include=0;
                //include case
                if(previndex==-1 || a[previndex]<a[currindex]){//2 condn ek ki pahla element hai and 2nd uske bad vala
                    include=1+dp[currindex+1][currindex+1];//aor vhi dp hai to previndex me curr ko +1 krna hi hoga
                    //curr ko aage bda do and prev 
                    //ab curr ke equal ho jayega
                }
                
                //exclude case
                int exclude=0+dp[currindex+1][previndex+1];//+1 kiya prev me so that -1 na ho invalid index
                //curr to aage bd gya but not prev vo vhi rhega
                
                dp[currindex][previndex+1]=max(include,exclude);
            }
        }
        return dp[0][0];// pev -1 tk jayga to -1+1=0
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //size n hi li because 0 se n-1 tk curr and -1 se n-1 tk prev ja rha hai to total n element ho gye hai
       //because 0 se leke n-1 = n elemnt and -1 se n-1 tk n+1 eleemnts
       vector<vector<int>>dp(n,vector<int>(n+1,-1));//because curr and prev are changing
       return solve(n,a);
    }
}; 


but all these give tle

4:space optimized


class Solution
{
    public:
    

    int solve(int n,int a[]){
        
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        
        //CURRINDEX+1 MEANS NEXT ROW AND CURINDEX MEANS CURR ROW
        
        //to 2 row se kam chal jayega
        
        for(int currindex=n-1;currindex>=0;currindex--){
            for(int previndex=currindex-1;previndex>=-1;previndex--){
                int include=0;
                //include case
                if(previndex==-1 || a[previndex]<a[currindex]){//2 condn ek ki pahla element hai and 2nd uske bad vala
                    include=1+next[currindex+1];//aor vhi dp hai to previndex me curr ko +1 krna hi hoga
                    //curr ko aage bda do and prev 
                    //ab curr ke equal ho jayega
                }
                
                //exclude case
                int exclude=0+next[previndex+1];//+1 kiya prev me so that -1 na ho invalid index
                //curr to aage bd gya but not prev vo vhi rhega
                
                curr[previndex+1]=max(include,exclude);
            }
            
            next=curr;//har iteration ke bad aage vali row piche ke equal ho jayegi
        }
        return next[0];// pev -1 tk jayga to -1+1=0
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //size n hi li because 0 se n-1 tk curr and -1 se n-1 tk prev ja rha hai to total n element ho gye hai
       //because 0 se leke n-1 = n elemnt and -1 se n-1 tk n+1 eleemnts
       vector<vector<int>>dp(n,vector<int>(n+1,-1));//because curr and prev are changing
       return solve(n,a);
    }
}; 





5: above all give tle as t.c should be nlogn so we will use binary search 

class Solution
{
    public:
    

    int solveOptimal(int n,int a[]){
        if(n==0){
            return 0;
        }
        
        vector<int>ans;
        ans.push_back(a[0]);
        
        for(int i=0;i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                //find index of element in ans which is just bigger than a[i]
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int a[])
    {
       return solveOptimal(n,a);
    }
}; 

syntax:lower_bound(InputIt first, InputIt last,value);


t.c of finding lower_bound is 
Time Complexity:  The number of comparisons performed is logarithmic. Therefore, the time complexity of the above approach is O(logN)

AND THIS FUNCTION PERFORMS BINARY_SEARCH TO FIND THAT PARTICULAR INDEX

Your teacher is correct in referring to std::lower_bound as performing a binary search.
Internally, std::lower_bound uses a binary search algorithm, which efficiently finds the insertion point in logarithmic time, 
O(logn).


t.c:-O(nlogn)
s.c:-O(n)




 The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last) which has a value not less than val. 
This means that the function returns an iterator pointing to the next smallest number just greater than or equal to that number.
If there are multiple values that are equal to val, lower_bound() returns the iterator of the first such value.
The elements in the range shall already be sorted or at least partitioned with respect to val. 




t.c:-O(n^2)
s.c:-O(n) (from O(2*n+1))
