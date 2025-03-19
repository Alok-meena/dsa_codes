You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod 
provided that each segment should be of the length 'X', 'Y', or 'Z'.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
7 5 2 2
8 3 3 3
Sample Output 1:
2
0
Explanation For Sample Input 1:

In the first test case, cut it into 2 parts of 5 and 2.

In the second case, there is no way to cut into segments of 3 length only as the length of the rod is less than the given length. 

	to ye ques me n length ki rod hai na use max kitne segment me cut kr skte hai given x , y , z length me se jaise 8 1 4 4 to 
	8 ko 4 4 se but 2 segment and 1 se 8 bar to max 8 aagya okk

1:recursion

#include <limits.h>
int solve(int n,int x,int y,int z){
	if(n==0){
		return 0;
	}

	if(n<0){
		return INT_MIN;
	}

	//bs ques me bola hai ki max segments kis case me use hogi alright that's why we returned max segments by adding the current segment 

	int a=solve(n-x,x,y,z)+1;//+1 kiya because ager is segment ko include kr rhe hai to hi
	int b=solve(n-y,x,y,z)+1;
	int c=solve(n-z,x,y,z)+1;

	return max(a,max(b,c));
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int ans=solve(n,x,y,z);
	if(ans<0){
		return 0;
	}
	return ans;
}


Time Complexity
O(3^N) where ‘N’ is the length of a given rod.

 

When ‘X’, ’Y’, ’Z’ equal to 1 then worse case will happen and we recursively call them.

Space Complexity
O(1)

 


2:recursion + memorization



#include <limits.h>
int solve(int n,int x,int y,int z,vector<int>&dp){
	if(n==0){
		return 0;
	}

	if(n<0){
		return INT_MIN;
	}

	if(dp[n]!=-1){
		return dp[n];
	}

	int a=solve(n-x,x,y,z,dp)+1;
	int b=solve(n-y,x,y,z,dp)+1;
	int c=solve(n-z,x,y,z,dp)+1;
    
	dp[n]=max(a,max(b,c));
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int>dp(n+1,-1);//to bhai ham har bar n+1 le rhe hai because n length ki rod me n index tk value acces krni hogi to array n+1 size ka hoga
	int ans=solve(n,x,y,z,dp);
	if(ans<0){
		return 0;
	}
	return ans;
}

Time Complexity
O(N), Where ‘N’ is the length of the rod.

 

Because we iterate a single loop from 1 to ‘N’. 

Space Complexity
O(N)+O(N)=O(N), Where ‘N’ is the length of the rod.

 

As we created a ‘DP’ array for storing the values.



3:tabulation (bottom-up)

  #include <limits.h>


int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int>dp(n+1,-1);//to bhai ham har bar n+1 le rhe hai because n length ki rod me n index tk value acces krni hogi to array n+1 size ka hoga
	
	dp[0]=0;
	for(int i=1;i<=n;i++){
		if(i-x>=0 && dp[i-x]!=-1){
			dp[i]=max(dp[i],dp[i-x]+1);
		}
		if(i-y>=0 && dp[i-y]!=-1){
			dp[i]=max(dp[i],dp[i-y]+1);
		}
		if(i-z>=0 && dp[i-z]!=-1){
			dp[i]=max(dp[i],dp[i-z]+1);
		}
	}

	if(dp[n]<0){
		return 0;
	}
	else{
		return dp[n];
	}
}

or 

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int>dp(n+1,INT_MIN); //n<0 ke liye int_min set kr rhe the to sbko hi kr do set alright
	dp[0]=0;

	for(int i=1;i<=n;i++){
		int a=INT_MIN,b=INT_MIN,c=INT_MIN;
		if(i-x>=0) a=dp[i-x]+1;
		if(i-y>=0) b=dp[i-y]+1;
		if(i-z>=0) c=dp[i-z]+1;

		dp[i]=max(a,max(b,c));
	}

	if(dp[n]<0) return 0;  //and here we cant check like dp[n]==INT_MIN becaue after max value is computer it will be no longer INT_MIN okk
	return dp[n];
}


Time Complexity
O(N), Where ‘N’ is the length of the rod.

 

Because we iterate a single loop from 1 to ‘N’. 

Space Complexity
O(N), Where ‘N’ is the length of the rod.

 

As we created a ‘DP’ array for storing the values.

and no space optimmiztion is possible okk
