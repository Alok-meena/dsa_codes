





AND WE HAVE TO SORT THE ARRAY AT STARTING BECAUSE



1 year ago
If someone has confusion as why did we sort it's because  if the bigger element is at end then we can have greater value of the coefficient because time will be more than with that of lower index e.g if we have [4,3,2] => without sort 4x1 + 3x2 + 2x3 => 16
After sort we have [2,3,4] => 2x1 + 3x2 + 4x3 => 20 which is maximum.


1:recursion


//VERY IMP KI TIME KO MULTIPLY 1 SE HI START KIYA HAI SO 0 PASS KRKE 1 SE HI MULTIPLY KIYA HAMNE


class Solution {
public:

    int solve(vector<int>&satisfaction,int index,int time){
        //base case
        if(index==satisfaction.size()){
            return 0;
        }

        int include=satisfaction[index]*(time+1)+solve(satisfaction,index+1,time+1);
        int exclude=0+solve(satisfaction,index+1,time);

        int ans=max(include,exclude);
        return ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,0);//time 1 se karna hai pass 0 kiya aor vha +1 kr diya include me
    }
};

t.c:-exponential 
s.c:-O(n)


2:memorization


class Solution {
public:

    int solve(vector<int>&satisfaction,int index,int time,vector<vector<int>>&dp){
        //base case
        if(index==satisfaction.size()){
            return 0;
        }

        if(dp[index][time]!=-1){
            return dp[index][time];
        }

        int include=satisfaction[index]*(time+1)+solve(satisfaction,index+1,time+1,dp);
        int exclude=0+solve(satisfaction,index+1,time,dp);

        int ans=max(include,exclude);
        dp[index][time]=ans;
        return dp[index][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));//index and time both changes so 2d array
        return solve(satisfaction,0,0,dp);
    }
};

t.c:-O(n^2) 
s.c:-O(n^2)

3:tabulation/ bottom-up appraoch




class Solution {
public:


    int solve(vector<int>&satisfaction){
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));//0 rkah liya because min ans 0 hoga and we have to find max ans

        //to base case to hmne dp ko bnane me hi sbko 0 kr diya then reverse approach lgao
        for(int index=n-1;index>=0;index--){//to size n+1 deni hi pdegi because we have to access from 0 to n so n ka 0 ho gya b.c so start n-1
            for(int time=index;time>=0;time--){
                int include=satisfaction[index]*(time+1)+dp[index+1][time+1];
                int exclude=0+dp[index+1][time];

                dp[index][time]=max(include,exclude);;
            }
        }
        return dp[0][0];//then pichle me jo pass kiya tha vhi yha ans store hoga
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction);
    }
};

t.c:-O(n^2) 
s.c:-O(n^2)

4:space optimization s.c:-O(n) t.c:-O(n^2)


  class Solution {
public:


    int solve(vector<int>&satisfaction){
        int n=satisfaction.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);

        //ek current row and ek next row

        //to base case to hmne dp ko bnane me hi sbko 0 kr diya then reverse approach lgao
        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int include=satisfaction[index]*(time+1)+next[time+1];//index+1 means next row and index means curr row
                int exclude=0+next[time];

                curr[time]=max(include,exclude);;
            }
            next=curr;//after each iteration next row will convert to curr row
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction);
    }
};

t.c:-O(n^2)



  USING GREEDY APPRoach

class Solution {
public:

int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int ans=0;
        for(int i=0;i<satisfaction.size();i++){
           int sum=0;
           int count=1;
           for(int j=i;j<satisfaction.size();j++){
              sum+=satisfaction[j]*count;
              count++;
           }
        ans=max(ans,sum);
        }
        return ans;
    }
};




