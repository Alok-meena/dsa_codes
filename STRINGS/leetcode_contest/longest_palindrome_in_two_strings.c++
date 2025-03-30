100602. Longest Palindrome After Substring Concatenation I
User Accepted:1964
User Tried:2549
Total Accepted:2017
Total Submissions:3347
Difficulty:Medium
You are given two strings, s and t.

You can create a new string by selecting a substring from s (possibly empty) and a substring from t (possibly empty), then concatenating them in order.

Return the length of the longest palindrome that can be formed this way.

A substring is a contiguous sequence of characters within a string.

A palindrome is a string that reads the same forward and backward.

 

Example 1:

Input: s = "a", t = "a"

Output: 2

Explanation:

Concatenating "a" from s and "a" from t results in "aa", which is a palindrome of length 2.

Example 2:

Input: s = "abc", t = "def"

Output: 1

Explanation:

Since all characters are different, the longest palindrome is any single character, so the answer is 1.

Example 3:

Input: s = "b", t = "aaaa"

Output: 4

Explanation:

Selecting "aaaa" from t is the longest palindrome, so the answer is 4.

Example 4:

Input: s = "abcde", t = "ecdba"

Output: 5

Explanation:

Concatenating "abc" from s and "ba" from t results in "abcba", which is a palindrome of length 5.

 

Constraints:

1 <= s.length, t.length <= 30
s and t consist of lowercase English letters.

  



class Solution {
public:
    bool isPalindrome(const string &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}
    int longestPalindrome(string s, string t) {
       int maxLen = 1;  // At minimum, a single character can be a palindrome
    
    // Try all substrings from s
    for (int i = 0; i <= s.size(); i++) {
        for (int j = i; j <= s.size(); j++) {
            string subS = s.substr(i, j - i);
            
            // Try all substrings from t
            for (int k = 0; k <= t.size(); k++) {
                for (int l = k; l <= t.size(); l++) {
                    string subT = t.substr(k, l - k);
                    
                    // Concatenate and check palindrome
                    string newStr = subS + subT;
                    if (isPalindrome(newStr)) {
                        maxLen = max(maxLen, (int)newStr.length());
                    }
                }
            }
        }
    }
    
    return maxLen;
    }
};

just concatenating all possible substrings of both and checking for palindrome


can also do like class Solution {
public:
    bool isPalindrome(const string &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}
    int longestPalindrome(string s, string t) {
       int maxLen = 1;  // At minimum, a single character can be a palindrome
    
    // Try all substrings from s
    for (int i = 0; i <s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            string subS = s.substr(i, j - i+1);
            if (isPalindrome(subS)) { // Check if this alone is a palindrome
                    maxLen = max(maxLen, (int)subS.length());
                }
            
            // Try all substrings from t
            for (int k = 0; k < t.size(); k++) {
                for (int l = k; l < t.size(); l++) {
                    string subT = t.substr(k, l - k+1);
                     if (isPalindrome(subT)) { // Check if t's substring alone is a palindrome
                            maxLen = max(maxLen, (int)subT.length());
                        }
                    
                    // Concatenate and check palindrome
                    string newStr = subS + subT;
                    if (isPalindrome(newStr)) {
                        maxLen = max(maxLen, (int)newStr.length());
                    }
                }
            }
        }
    }
    
    return maxLen;
    }
};
