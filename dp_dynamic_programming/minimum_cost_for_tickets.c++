Problem statement
Ninja is willing to take some time off from his training and planning a year-long tour.
You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year.
Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.

2
2 
2 5
1 4 25    
7
1 3 4 5 7 8 10
2 7 20
Sample Output 1:
2
11
Explanation For sample input 1:
For the first test case, 
On Day 2, Ninja will buy a 1-day pass with 1 coin.
On Day 5, Ninja will buy a 1-day pass with 1 coin.
In total, Ninja will spend 2 coins. Hence the answer is 2.

For the second test case,
On Day 1, Ninja will buy a 1-day pass with 2 coins.
On Day 3, Ninja will buy a 7-day pass with 7 coins valid for days 3,4,5...9.
On Day 10, Ninja will buy a 1-day pass with 2 coins.
In total, Ninja will spend 11 coins. Hence the answer is 11.



YHA PE HAM HAR EK DAY KE LIYE 1 7 30 DAY KA CALL KR RHE HAI

    
int solve(int n, vector<int>&days, vector<int>&cost,int index){
    if(index>=n){
        return 0;
    }
    
    //1 day pass
    int option1=cost[0]+solve(n,days,cost,index+1);//to ager 1 day ka path liya to hamne index ko 1 aage bda diya next day pe

    //7day pass
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);//isme i<n hai so that it is in range and days[i]<days[index]+7 kiya mtlb days[i] to agle days access
    //hote rhenge aor days[index]+7 mtlb current day ex 1 3 4 5 7 8 10  cost :- 2 7 20 to isme 1 day k2 2 coin then index=1 and i=1 and then 
    //days[index]+7=3+7=10 mtlb <10 mtlb =9 tk hi jaye to 7 kdm aage bda diya same for 30  days

    int option2=cost[1]+solve(n,days,cost,i);//aor yha function me i pass krenge because i hai ki 7 day ke bad jo index aayea

    //30 day pass
    for(i=index;i<n && days[i]<days[index]+30;i++);

    int option3=cost[2]+solve(n,days,cost,i);

    return min(option1,min(option2,option3));
    
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    return solve(n,days,cost,0);
}

t.c:-exponenetial and s.c:-O(N)


2:memoization


  int solve(int n,vector<int>& days, vector<int>& costs,int index,vector<int>&dp){
    if(index>=n){
        return 0;
    }


    if(dp[index]!=-1){
        return dp[index];
    }
    
    //1 day pass
    int option1=costs[0]+solve(n,days,costs,index+1,dp);

    //7day pass
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);

    int option2=costs[1]+solve(n,days,costs,i,dp);

    //30 day pass
    for(i=index;i<n && days[i]<days[index]+30;i++);

    int option3=costs[2]+solve(n,days,costs,i,dp);

    dp[index]=min(option1,min(option2,option3));
    return dp[index];
}


int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int>dp(days.size()+1,-1);
    return solve(n,days,cost,0,dp);
}


t.c:-O(1) because 365 days are there only and s.c:-O(N) due to dp array


3:Tabulation  (hence here we have to find min so in dp will assign each element with INT_MAX


//to suno dp[n] ko base case se match krke kr liya complete aor now we have to compute from n-1 to 0 
//to vo bhi kr liya jaise piche vale me index se sabhi days ko access kiya yha use k se replace kr do

AND THIS IS BOTTOM-UP APPRAOCH SO WE DO IT FROM N-1 TO 0



int solve(int n, vector<int> &days, vector<int> &cost) {
  

  vector<int> dp(n + 1, INT_MAX);
  dp[n] = 0;
  for (int k = n - 1; k >=0; k--) {
    int option1 = cost[0] + dp[k + 1];

    int i;
    for (i = k; i < n && days[i] < days[k] + 7; i++)
      ;
    int option2 = cost[1] + dp[i];

    for (i = k; i < n && days[i] < days[k] + 30; i++)
      ;
    int option3 = cost[2] + dp[i];

    dp[k] = min(option1, min(option2, option3));
 
  }
  return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
  // Write your code here.

  return solve(n, days, cost);
}


t.c=O(N) and s.c:-O(N)


4: using queue t.c:-O(N) and s.c:-O(1)


    IT I JUST LIKE SLIDING WINDOW APPROACH


int minimumCoins(int n, vector<int> days, vector<int> cost) {
  // Write your code here.

  int ans=0;

  //we are sure ki month me 30 se jyada and week me 7 se jyada entries nhi hogi so s.c:-O(1)
  queue<pair<int,int>>month;//isme pahla int btayega day and second one that cost on that day
  queue<pair<int,int>>week;

  for(int day:days){
    //step1:remove expired days means in weekly aor monthly 7 and 30 se jyada days ko remove kr do

    while(!month.empty() && month.front().first+30<=day){
      month.pop();
    }

    while(!week.empty() && week.front().first+7<=day){
      week.pop();
    }

    //step2: add cost for current day
    week.push(make_pair(day,ans+cost[1]));//weekly means 7 days so cost 1 and montly me cost [2]
    month.push(make_pair(day,ans+cost[2]));

    //step3: ans update
    ans=min(ans+cost[0],min(week.front().second,month.front().second));//because second me cost pdi hui hai
  }

  return ans;
}
