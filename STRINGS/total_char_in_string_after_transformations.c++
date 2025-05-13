3335. Total Characters in String After Transformations I
Solved
Medium
Topics
Companies
Hint
You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: s = "abcyy", t = 2

Output: 7

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'
String after the first transformation: "bcdzz"
Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.
Example 2:

Input: s = "azbk", t = 1

Output: 5

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'
String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 105 due to this we have to do this code in O(n) complexity






#define mod 1000000007

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long>freq(26,0);
        for(auto i:s){
            freq[i-'a']++;
        }

        long long count=s.length();

        while(t--){
            long long z_count=freq[25];
            count=(count+(2*z_count))%mod;
            vector<long long>new_freq(26,0);

            for(int i=0;i<25;i++){
                new_freq[i+1]=(new_freq[i+1]+freq[i])%mod;
            }

            new_freq[0]=(new_freq[0]+z_count)%mod;
            new_freq[1]=(new_freq[1]+z_count)%mod;

            freq=new_freq;
        }

        return count;
    }
};
