





int solve(int n, vector<int>&days, vector<int>&cost,int index){
    if(index>=n){
        return 0;
    }
    
    //1 day pass
    int option1=cost[0]+solve(n,days,cost,index+1);

    //7day pass
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);

    int option2=cost[1]+solve(n,days,cost,i);

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
