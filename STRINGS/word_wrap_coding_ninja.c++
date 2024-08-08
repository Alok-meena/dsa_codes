You are given ‘N’ words of various lengths, now you have to arrange these words in such a way that each line contains at most ‘M’ characters and each word is separated by a space character. The cost of each line is equal to the cube of extra space characters required to complete ‘M’ characters in that particular line. Total cost is equal to the sum of costs of each line.

Your task is to form this arrangement with the minimum cost possible and return the minimum total cost.

Note:
The length of each word should be less than or equal to ‘M’.

You can’t break a word, i.e. the entire word should come in the same line and it must not be the case that a part of it comes in the first line and another part on the next line.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 300
1 <= |words[i]| <= 100
1 <= M <= 100

Time Limit: 1sec
Sample Input 1:
1
3 6
ab
a
b
Sample Output 1:
0
Explanation For Sample Input 1:
All the 3 words can be inserted in a single line.
ab a b Total Characters = 6
Hence extra spaces used are (6-6)^3=0


#include <bits/stdc++.h>
using namespace std;

int solve(int n,int i, int rem, vector<int>& nums, int k, vector<vector<int>>& dp) {
    // Base case: if all words are processed
    if (i == n) {
        return (rem + 1) * (rem + 1)*(rem + 1);
    }
    
    // Check if the result is already computed
    if (dp[i][rem+1] != -1) {
        return dp[i][rem+1];
    }
    
    int ans;
    // If the current word cannot fit in the remaining space on the current line
    if (nums[i] > rem) {
        return dp[i][rem+1]=(rem + 1) * (rem + 1)*(rem + 1) + solve(n,i + 1, k - nums[i] - 1, nums, k, dp);
        // Move to the next line, resetting the remaining space
    } else {
        // Option 1: Move to the next line
        int choice1 = (rem + 1) * (rem + 1)*(rem + 1) + solve(n,i + 1, k - nums[i] - 1, nums, k, dp);
        
        // Option 2: Place the word in the current line
        int choice2 = solve(n,i + 1, rem - nums[i] - 1, nums, k, dp);
        
        // Take the minimum of both options
        dp[i][rem+1]=min(choice1, choice2);
    }
    
    // Store the result in dp and return
    // dp[i][rem] = ans;
    // return dp[i][rem];
}

int wordWrap(vector<string> words, int m, int n) {
    // Handle edge cases
    if (m == 0 || n == 0 || words.empty()) return 0;

    // Convert words to their lengths
    vector<int> nums;
    for (const auto& word : words) {
        nums.push_back(word.length());
    }

    // Initialize dp array
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, -1));
    
    // Start the recursive process
    return solve(n,0, m, nums, m, dp);
}
