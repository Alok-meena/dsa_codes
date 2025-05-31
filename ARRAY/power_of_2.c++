231. Power of Two
Solved
Easy
Topics
premium lock icon
Companies
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1







class Solution {
public:

    bool isPowerOfTwo(int n) {
        return n>0 && (n & (n-1))==0;
    }
};


✅ Best Optimized Solution (Bit Manipulation – O(1) time)
cpp
Copy
Edit
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
🔍 Why this works:
A number is a power of two if it has exactly one set bit in binary.

For example:

2 = 10

4 = 100

8 = 1000

For such numbers:
n & (n - 1) will be 0
Because:

markdown
Copy
Edit
8  = 1000
7  = 0111
---------
&    0000
