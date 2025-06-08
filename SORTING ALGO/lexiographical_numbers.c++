386. Lexicographical Numbers
Solved
Medium
Topics
premium lock icon
Companies
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 

Constraints:

1 <= n <= 5 * 104







class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=n;i++) ans.push_back(i);
        sort(ans.begin(),ans.end(),[](int a,int b){
            return to_string(a)<to_string(b);
        });

        return ans;
    }
};

t.c:-O(nlogn) and s.c:-O(n) ( space is required to return 



1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9
this is due to this
"1", "10", "11", "12", "13", "2", ...


more optimized

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int curr = 1;

        for (int i = 0; i < n; ++i) {
            ans.push_back(curr);

            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10;
                }
                curr++;
            }
        }

        return ans;
    }
};

t.c:-O(n) and s.c:-O(1) by ignoring that space used to return the answer
