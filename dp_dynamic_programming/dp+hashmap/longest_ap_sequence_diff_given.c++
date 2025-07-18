Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
Example 2:

Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.
Example 3:






  HASHMAP+DP solution

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int>dp;
        int ans=0;

        for(int i=0;i<n;i++){
            int temp=arr[i]-difference;
            int count=0;

           //check if ans already present or not
            if(dp.count(temp)){//ye check krega ki i index tk koi element hai with diff d if yes to uske ans ko count me store kr liya
                count=dp[temp];
            }

            dp[arr[i]]=1+count;//aor fir yha pe count yani pichla ans and +1 for including the current answer also

            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};

t.c:-O(n) and s.c:-O(n)


can do like this also 

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int len=1;
        if(arr.size()<=1) return 1;
        
        for(int i=0;i<arr.size();i++){
             int k=i-1;
                int ele=arr[i];
                int count=0;
                while(k>=0){
                    if(ele-difference==arr[k]){
                        ele=arr[k];
                        count++;
                    }
                    k--;
                }
                
                len=max(len,count+1);
        }
        
        return len;
    }
};

means at each step checking if there is a ele backward with given diff means arr[i]-diff===arr[k] then do count ++ but gives tle alright

optimized 

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int len = 1;

        for (int i = 0; i < arr.size(); i++) {
            int ele = arr[i];
            int prev = ele - difference;

            // if there's a sequence ending at prev, extend it
            if (dp.find(prev) != dp.end()) {
                dp[ele] = dp[prev] + 1;
            } else {
                dp[ele] = 1; // start a new subsequence
            }

            len = max(len, dp[ele]);
        }

        return len;
    }
};

cant use vector here instead of map because ele can be negative also alright
