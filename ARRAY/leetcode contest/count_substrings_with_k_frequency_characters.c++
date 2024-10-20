3325. Count Substrings With K-Frequency Characters I
User Accepted:13895
User Tried:16245
Total Accepted:14818
Total Submissions:29393
Difficulty:Medium
Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.

A substring is a contiguous non-empty sequence of characters within a string.

 

Example 1:

Input: s = "abacb", k = 2

Output: 4

Explanation:

The valid substrings are:

"aba" (character 'a' appears 2 times).
"abac" (character 'a' appears 2 times).
"abacb" (character 'a' appears 2 times).
"bacb" (character 'b' appears 2 times).
Example 2:

Input: s = "abcde", k = 1

Output: 15

Explanation:

All substrings are valid because every character appears at least once.

 

Constraints:

1 <= s.length <= 3000
1 <= k <= s.length
s consists only of lowercase English letters.




class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int count = 0;
        
        // Iterate through every possible starting index of a substring
        for (int i = 0; i < s.length(); i++) {
            unordered_map<char, int> freqMap;  // To store character frequencies

            // Iterate through every possible ending index for the current substring
            for (int j = i; j < s.length(); j++) {
                // Increment the frequency of the current character
                freqMap[s[j]]++;
                
                // Check if any character has appeared at least k times
                for (auto& entry : freqMap) {
                    if (entry.second >= k) {
                        count++;  // This substring satisfies the condition
                        break;    // No need to check further, move to the next substring
                    }
                }
            }
        }
        
        return count;
    }
};


t.c:-O(n^2) and s.c:-O(m) where m is no. of unique characters
