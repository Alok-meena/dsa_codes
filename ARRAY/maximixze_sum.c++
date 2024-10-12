You have an integer ‘N’ and an array ‘X’ of ‘N’ integers. You need to maximize the value of the array, which is equal to ⅀ '(X[i] - i)^2' from ‘i’ in the range ‘[0, N-1]’. To do this, you can rearrange the elements of the given array.

Determine the maximum value of the array you can get after rearranging the array ‘X’ elements.

Example:
'N' = 3, ‘X' = [1,2,1] 
If we rearrange our array 'X' to '[2, 1, 1]' .
Then our answer will be (0-2)^2 + (1-1)^2 + (1-2)^2 = 4 + 0 + 1 = 5.
For array ‘[1, 1, 2]’ value will be equal to ‘1 + 0 + 0 = 1’.
For array ‘[1, 2, 1]’ value will be equal to ‘1 + 1 + 1 = 3’.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 10^4
1<= X[i] <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
2
1 2  
3
1 1 1 
Sample Output 1 :
4
2
Explanation Of S






static bool cmp(int a,int b){
  return a>b;
}
long long int maximize(int n, vector<int> x)
{
  // Write your code here.
  sort(x.begin(),x.end(),cmp);
  long long int ans=0;

  for(int i=0;i<n;i++){
    ans+=(long long)((x[i]-i)*(x[i]-i));
  }
  return ans;

}




long long int maximize(int n, vector<int> x)
{
  // Write your code here.
  sort(x.begin(),x.end(),greater<int>());
  long long int ans=0;

  for(int i=0;i<n;i++){
    ans+=(long long)((x[i]-i)*(x[i]-i));
  }
  return ans;

}
