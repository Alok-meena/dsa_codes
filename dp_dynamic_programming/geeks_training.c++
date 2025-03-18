Geek's Training
Difficulty: MediumAccuracy: 49.98%Submissions: 106K+Points: 4Average Time: 20m
Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

Example:

Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
Output: 11
Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.
Input: arr[]= [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
Output: 6
Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.
Input: arr[]= [[4, 2, 6]]
Output: 6
Explanation: Geek will learn a new move to make his merit points as 6.
Constraint:
1 <=  n <= 105   
1 <=  arr[i][j] <= 100



class Solution {
  public:
    int solve(vector<vector<int>>&arr,int lastactivity,int idx){
        if(idx>=arr.size()) return 0;
        
        int point1=0,point2=0,point3=0;
        
        if(lastactivity!=0){
            point1+=arr[idx][0]+solve(arr,0,idx+1);
        }
        
        if(lastactivity!=1){
            point2+=arr[idx][1]+solve(arr,1,idx+1);
        }
        
        if(lastactivity!=2){
            point3+=arr[idx][2]+solve(arr,2,idx+1);
        }
        
        return max(point1,max(point2,point3));
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        return solve(arr,3,0); //to yha 3 bheja as 0 1 2 se alag means we can initally perform any activity out of given 3 activities alright
    }
    
};

t.c:-O(3^n) and s.c:-O(n)

memorization

class Solution {
  public:
    int solve(vector<vector<int>>&arr,int lastactivity,int idx,vector<vector<int>>&dp){
        if(idx==arr.size()) return 0;
        
        if(dp[idx][lastactivity]!=-1) return dp[idx][lastactivity];
        
        int point1=0,point2=0,point3=0;
        
        if(lastactivity!=0){
            point1+=arr[idx][0]+solve(arr,0,idx+1,dp);
        }
        
        if(lastactivity!=1){
            point2+=arr[idx][1]+solve(arr,1,idx+1,dp);
        }
        
        if(lastactivity!=2){
            point3+=arr[idx][2]+solve(arr,2,idx+1,dp);
        }
        
        dp[idx][lastactivity]=max(point1,max(point2,point3));
        return dp[idx][lastactivity];
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here

        //and two variables are changing so a 2D dp is required okk
        vector<vector<int>>dp(arr.size(),vector<int>(4,-1));
        return solve(arr,3,0,dp);
    }
    
};

t.c:-O(n*4) and s.c:-O(n*4)


tabulation method

int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(4,-1));
        int n=arr.size();
        
        for(int i=0;i<4;i++){
            dp[n][i]=0; //to last row puri 0 hogi alright
        }
        
        for(int idx=n-1;idx>=0;idx--){
            for(int lastactivity=0;lastactivity<4;lastactivity++){
                int point1=0,point2=0,point3=0;
        
                if(lastactivity!=0){
                    point1+=arr[idx][0]+dp[idx+1][0];
                }
                
                if(lastactivity!=1){
                    point2+=arr[idx][1]+dp[idx+1][1];
                }
                
                if(lastactivity!=2){
                    point3+=arr[idx][2]+dp[idx+1][2];
                }
                
                dp[idx][lastactivity]=max(point1,max(point2,point3));
            }
        }
        
        return dp[0][3]; //and uper top down me hamne 0 3 pe call kiya to yha vhi return krenge alright
        
        // return solve(arr,3,0,dp);
    }

here we dont need to add safe check like idx+1<n as we are starting the loop from n-1 and idx+1 will point to n but we have already set [n][i]=0 okk so no need
