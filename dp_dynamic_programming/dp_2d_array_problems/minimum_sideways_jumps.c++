There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.

 

Example 1:


Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).




1:recursion


class Solution {
public:
    
    int solve(vector<int>&obstacles,int currlane,int currpos){
        int n=obstacles.size()-1;
        if(currpos==n){
            return 0;
        }

        //to ager currlane me obstacle nhi hai to move kro aage jump bs side me hi kr skte hai

        if(obstacles[currpos+1]!=currlane){//currpos+1 kiya because next position pe check karna hai hame to
            return solve(obstacles,currlane,currpos+1);
        }
        else{//currlane me obstacle hai to kya kre
            
            //then sideways jump
            int ans=INT_MAX;
            //loop 1 se 3 because we just have 3 choices to jump
            for(int i=1;i<=3;i++){//AOR I YHA PE 3NO LANES HAI
              //loop me because 3 direcetions are possible but jump is possible only on two lanes 
                if(currlane!=i && obstacles[currpos]!=i){ 
                  //MTLB HAM JHA JUMP KARNA CHAHTE HAI VO CURRENT LANE NHI HONI CHAHIHE
                  //easy way me jha jump kiya vo currlane hai okk to vo i ke equal nhi hona chahihe and jha ham hai vha obstacle nhi hona chahie
                  //means if ith lane me obstacle hai to jump krne pe khi bhi vo uske (i) equal na ho

                  //AOR 2ND CONDTION KI JHA JUMP KARNA CHAHTE HAI HAM VHA BHI OSTACLE NHI HONA CHAHIE
                  //TO CONDITION HUI KI EK TO CURRLANE JO HAI I KE EQUAL NA HO AOR JHA OBSTACLE HAI VO I KE EQUAL NA HO

                  
                    //means jis lane pe jump kre vo current lane na ho
                    //and jha jump kr rhe hai vha pe obstacle nhi hona chahihe

                    //and ye condition bhi ho skti hai ki dono lane me jane ka chance ho to ham dono me se min vala ans lenge aor dono lane me jake
                    //apna recursion ans nikal ke leke aayega
                    ans=min(ans,1+solve(obstacles,i,currpos));
                }
            }
            return ans;

        }
    }
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles,2,0);//ques me given hai ki 2 lane me hai frog and at 0 position
    }
};


2:memorization using dp array 

AND HERE ALSO WE WILL USE A 2D ARRAY BECAUSE CURRLANE AND CURRPOS BOTH ARE CHANGING OKK!!!!!!!


class Solution {
public:
    
    int solve(vector<int>&obstacles,int currlane,int currpos,vector<vector<int>>&dp){
        int n=obstacles.size()-1;//size -1 krke hi dena hai okk
        if(currpos==n){
            return 0;
        }

        if(dp[currlane][currpos]!=-1){
            return dp[currlane][currpos];
        }

        //to ager currlane me obstacle nhi hai to move kro aage jump bs side me hi kr skte hai

        if(obstacles[currpos+1]!=currlane){
            return solve(obstacles,currlane,currpos+1,dp);
        }
        else{//currlane me obstacle hai to kya kre
            
            //then sideways jump
            int ans=INT_MAX;
            //loop 1 se 3 because we just have 3 choices to jump
            for(int i=1;i<=3;i++){//loop me because 3 direcetions are possible but jump is possible only on two lanes 
                if(currlane!=i && obstacles[currpos]!=i){ 
                    //means jis lane pe jump kre vo current lane na ho
                    //and jha jump kr rhe hai vha pe obstacle nhi hona chahihe
                    ans=min(ans,1+solve(obstacles,i,currpos,dp));
                }
            }
            dp[currlane][currpos]=ans;//dp me pahle currlane rkhe because hamne 4 lane ki size ki rows bnayi hai
            return dp[currlane][currpos];

        }
    }
    int minSideJumps(vector<int>& obstacles) {
        //2d array require as currlane and currpos both changes
        vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));//size 4 liya for correct output as we have 3 lanes  and n columns
        return solve(obstacles,2,0,dp);
    }
};


3:bottom-up / tabulation method


class Solution {
public:
    
  
    int solve(vector<int>&obstacles){
        int n=obstacles.size()-1;
        vector<vector<int>>dp(4,vector<int>(obstacles.size(),1e9));//size 4 liya because ham 1 index ko lane 1 man ke chal rhe hai

        //uper ka base case hai ye if currpos n ho gyi to 0 and first me to now. of rows(lanes) dal di bs
        dp[0][n]=0;
        dp[1][n]=0;
        dp[2][n]=0;
        dp[3][n]=0;

        for(int currpos=n-1;currpos>=0;currpos--){
            for(int currlane=1;currlane<=3;currlane++){
                        if(obstacles[currpos+1]!=currlane){
                              dp[currlane][currpos]=dp[currlane][currpos+1];
                        }
                        else{//currlane me obstacle hai to kya kre
                    
                        //then sideways jump
                        int ans=1e9;//JAB BHI OUT OF RANGE JAYE TO USSE CHOTA MAX ELEMENT LE LO
                        //loop 1 se 3 because we just have 3 choices to jump
                        for(int i=1;i<=3;i++){//loop me because 3 direcetions are possible but jump is possible only on two lanes 
                           if(currlane!=i && obstacles[currpos]!=i){ 
                            //means jis lane pe jump kre vo current lane na ho
                            //and jha jump kr rhe hai vha pe obstacle nhi hona chahihe
                            ans=min(ans,1+dp[i][currpos+1]);
                            }
                        }
                        dp[currlane][currpos]=ans;
            }
            
        }
        }
        return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));//1 add kiya to include jump from 1 or 3 to 2 lane
    }
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles);
    }
};

s.c:-O(4*n)


4:space optimization



class Solution {
public:
    
  
    int solve(vector<int>&obstacles){
        int n=obstacles.size()-1;
        
        vector<int>curr(4,INT_MAX);
        vector<int>next(4,INT_MAX);
        //to bs hmae 4 block ke 2 column chahie and just update after each iteration

        //uper ka base case hai ye if currpos n ho gyi to 0 and first me to now. of rows(lanes) dal di bs
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;

        for(int currpos=n-1;currpos>=0;currpos--){
            for(int currlane=1;currlane<=3;currlane++){
                        if(obstacles[currpos+1]!=currlane){
                              curr[currlane]=next[currlane];
                        }
                        else{//currlane me obstacle hai to kya kre
                    
                        //then sideways jump
                        int ans=1e9;//JAB BHI OUT OF RANGE JAYE TO USSE CHOTA MAX ELEMENT LE LO
                        //loop 1 se 3 because we just have 3 choices to jump
                        for(int i=1;i<=3;i++){//loop me because 3 direcetions are possible but jump is possible only on two lanes 
                           if(currlane!=i && obstacles[currpos]!=i){ 
                            //means jis lane pe jump kre vo current lane na ho
                            //and jha jump kr rhe hai vha pe obstacle nhi hona chahihe
                            ans=min(ans,1+next[i]);
                            }
                        }
                        curr[currlane]=ans;
            }
            
        }
        next=curr;
        }
        return min(next[2],min(1+next[1],1+next[3]));//1 add kiya to include jump from 1 or 3 to 2 lane
    }
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles);
    }
};


s.c:-O(1)
