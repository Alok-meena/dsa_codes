#include <bits/stdc++.h>
using namespace std;


void lis(vector<int>&arr){
    int n=arr.size();

    vector<int>dp(n,1),hash(n);
    int maxi=1;
    int lastidx=0;

    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){ //ise hme only i tk hi chlana hai means curr ele se ek piche tk hi to check krenge na 
            if(arr[prev]<arr[i] and 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }

        if(dp[i]>maxi){
            maxi=dp[i];
            lastidx=i;
        }
    }

    vector<int>ans;
    ans.push_back(arr[lastidx]);

    while(hash[lastidx]!=lastidx){
        lastidx=hash[lastidx];
        ans.push_back(arr[lastidx]);
    }

    reverse(ans.begin(),ans.end());

    for(auto i:ans) cout<<i<<" ";
}
int main(){
    vector<int>v={5,4,3,2,1,6,7,8,9};
    lis(v);

}
