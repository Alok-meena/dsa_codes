





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



3:Tabulation  (hence here we have to find min so in dp will assign each element with INT_MAX
