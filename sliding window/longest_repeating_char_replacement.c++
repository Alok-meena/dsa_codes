
Code
Test Result
Testcase
Testcase
424. Longest Repeating Character Replacement
Attempted
Medium
Topics
premium lock icon
Companies
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length


brute: t.c:-O(n^2) and s.c:-O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int len=0;

        int n=s.length();

        for(int i=0;i<n;i++){
            vector<int>hash(26,0);
            int maxi=0;
            for(int j=i;j<n;j++){
                hash[s[j]-'A']++;
                maxi=max(maxi,hash[s[j]-'A']);
                int changes=(j-i+1)-maxi;
                if(changes<=k){
                    len=max(len,j-i+1);
                }
                else break;
            }
        }

        return len;
    }
};

optimized:

t.c:-O((2n)*26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int len=0;

        int n=s.length();

        int l=0,r=0,maxi=0;
        vector<int>hash(26,0);

        while(r<n){
            hash[s[r]-'A']++;
            maxi=max(maxi,hash[s[r]-'A']);
            int changes=(r-l+1)-maxi;
            while((r-l+1)-maxi>k){
                hash[s[l]-'A']--;
                maxi=0;
                int val=*max_element(hash.begin(),hash.end());
                maxi=max(maxi,val);
                l++;
            }

            len=max(len,r-l+1);
            r++;
        }

        return len;
    }
};


more optimized

no need to update maxi as it is decreasing actually and not helping in getting more len right
so no need

class Solution {
public:
    int characterReplacement(string s, int k) {
        int len=0;

        int n=s.length();

        int l=0,r=0,maxi=0;
        vector<int>hash(26,0);

        while(r<n){
            hash[s[r]-'A']++;
            maxi=max(maxi,hash[s[r]-'A']);
            int changes=(r-l+1)-maxi;
            while((r-l+1)-maxi>k){
                hash[s[l]-'A']--;
                l++;
            }

            len=max(len,r-l+1);
            r++;
        }

        return len;
    }
};

t.c:-O(2n) 

to more optimzie use if instead of while

alright
