100618. Smallest Palindromic Rearrangement I
User Accepted:9677
User Tried:10660
Total Accepted:10061
Total Submissions:15065
Difficulty:Medium
You are given a palindromic string s.

Return the lexicographically smallest palindromic permutation of s.

A string is palindromic if it reads the same forward and backward.

A permutation is a rearrangement of all the characters of a string.

A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
If the first min(a.length, b.length) characters do not differ, then the shorter string is the lexicographically smaller one.
 

Example 1:

Input: s = "z"

Output: "z"

Explanation:

A string of only one character is already the lexicographically smallest palindrome.

Example 2:

Input: s = "babab"

Output: "abbba"

Explanation:

Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:

Input: s = "daccad"

Output: "acddca"

Explanation:

Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.

 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
s is guaranteed to be palindromic.



brute force gives tle 

class Solution {
public:
    bool palindrome(string a){
        int i=0;
        int j=a.length()-1;
        while(i<j){
            if(a[i]!=a[j]) return false;
            i++;j--;
        }
        return true;
    }
    string smallestPalindrome(string s) {
        sort(s.begin(),s.end());
        if(palindrome(s)) return s;
        while(next_permutation(s.begin(),s.end())){
            if(palindrome(s)) return s;
        }
        return s;
    }
};

optimized

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string half = "", mid = "";

        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 == 1)
                mid = string(1, i + 'a');
            half += string(freq[i] / 2, i + 'a');
        }

        string res = half + mid;
        reverse(half.begin(), half.end());
        res += half;

        return res;
    }
};
