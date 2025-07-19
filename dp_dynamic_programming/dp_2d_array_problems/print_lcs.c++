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
