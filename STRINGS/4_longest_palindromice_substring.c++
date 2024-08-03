Given a string str, find the longest palindromic substring in str. Substring of string str: str[ i . . . . j ] where 0 ≤ i ≤ j < len(str). Return the longest palindromic substring of str.

Palindrome string: A string that reads the same backward. More formally, str is a palindrome if reverse(str) = str. In case of conflict, return the substring which occurs first ( with the least starting index).

Examples :

Input: str = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic substring is "aabbaa".
Input: str = "abc"
Output: a
Explanation: "a", "b" and "c" are the longest palindromes with same length. The result is the one with the least starting index.




  class Solution {
public:
    string longestPalin(string S) {
        int n = S.length();
        if (n == 0) return "";

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < n; ++i) {
            // Check for odd-length palindromes
            int len1 = expandAroundCenter(S, i, i);
            // Check for even-length palindromes
            int len2 = expandAroundCenter(S, i, i + 1);

            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (maxLength - 1) / 2;
            }
        }

        return S.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // Length of the current palindromic substring
        return right - left - 1;
    }
};


Efficiency: This approach runs in O(n^2) time complexity and O(1) space complexity, making it efficient and straightforward for this problem.
