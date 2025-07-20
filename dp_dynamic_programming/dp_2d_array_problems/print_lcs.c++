#include <bits/stdc++.h>
using namespace std;

void longestCommonSubsequence(string a, string b) {
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int n = a.length();
    int m = b.length();
    int len = dp[n][m];  // max length of LCS

    cout << "LCS Length: " << len << endl;

    string ans(len, '$');  // initialize with dummy chars
    int idx = len - 1;
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans[idx] = a[i - 1];
            idx--;
            i--;
            j--;
        } else if (dp[i][j - 1] > dp[i - 1][j]) {
            j--;
        } else {
            i--;
        }
    }

    cout << "LCS: " << ans << endl;
}

int main() {
    string a = "abcde";
    string b = "bdgek";

    longestCommonSubsequence(a, b);
}




class Solution {
public:
    int solve(int i,int j,string a,string b,vector<vector<int>>&dp){
        if(i<0 or j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        if(a[i]==b[j]){
            ans=1+solve(i-1,j-1,a,b,dp);
        }
        else{
            int op1=solve(i-1,j,a,b,dp);
            int op2=solve(i,j-1,a,b,dp);
            ans+=max(op1,op2);
        }

        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));

        int n=a.length();
        int m=b.length();

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ans=0;
                if(a[i-1]==b[j-1]){
                    ans=1+dp[i-1][j-1];
                }
                else{
                    int op1=dp[i-1][j];
                    int op2=dp[i][j-1];
                    ans+=max(op1,op2);
                }

                dp[i][j]=ans;
            }
        }

        return dp[n][m];

        
    }
};



or we can also start from top also in that case no need of index alsi


#include <bits/stdc++.h>
using namespace std;


void printlcs(string a,string b){
      vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                //inc
                int inc=0;
                if(a[i]==b[j]){
                    inc=1+dp[i+1][j+1];
                }

                int exc1=0+dp[i+1][j];
                int exc2=0+dp[i][j+1];
                dp[i][j]=max(inc,max(exc1,exc2));
            }
        }

        // for(auto i:dp){
        //     for(auto j:i) cout<<j<<" ";
        //     cout<<endl;
        // }
        
        string ans;
        int n=a.length(),m=b.length();
        int i=0,j=0;

       while(i<n and j<m){
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;j++;
            }
            else if(dp[i][j+1]>dp[i+1][j]){
                j++;
            }
            else i++;
        }
        
        cout<<ans;
}
int main(){
    string a="abcd";
    string b="abde";

    printlcs(a,b);
}
