2145. Count the Hidden Sequences
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed array of n integers differences, which describes the differences between each pair of consecutive integers of a hidden sequence of length (n + 1). More formally, call the hidden sequence hidden, then we have that differences[i] = hidden[i + 1] - hidden[i].

You are further given two integers lower and upper that describe the inclusive range of values [lower, upper] that the hidden sequence can contain.

For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden sequence is a sequence of length 4 whose elements are in between 1 and 6 (inclusive).
[3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
[5, 6, 3, 7] is not possible since it contains an element greater than 6.
[1, 2, 3, 4] is not possible since the differences are not correct.
Return the number of possible hidden sequences there are. If there are no possible sequences, return 0.

 

Example 1:

Input: differences = [1,-3,4], lower = 1, upper = 6
Output: 2
Explanation: The possible hidden sequences are:
- [3, 4, 1, 5]
- [4, 5, 2, 6]
Thus, we return 2.
Example 2:

Input: differences = [3,-4,5,1,-2], lower = -4, upper = 5
Output: 4
Explanation: The possible hidden sequences are:
- [-3, 0, -4, 1, 2, 0]
- [-2, 1, -3, 2, 3, 1]
- [-1, 2, -2, 3, 4, 2]
- [0, 3, -1, 4, 5, 3]
Thus, we return 4.
Example 3:

Input: differences = [4,-7,2], lower = 3, upper = 6
Output: 0
Explanation: There are no possible hidden sequences. Thus, we return 0.
 

Constraints:

n == differences.length
1 <= n <= 105
-105 <= differences[i] <= 105
-105 <= lower <= upper <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
32.8K
Submissions
71.9K
Acceptance Rate
45.6%


class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> prefixsum(n + 1, 0);  
        long long sum = 0;                      

        for (int i = 0; i < differences.size(); i++) {
            sum += differences[i];
            prefixsum[i + 1] = sum;
        }

        long long mini = LLONG_MAX;
        long long maxi = LLONG_MIN;

        for (auto i : prefixsum) {
            mini = min(mini, i);
            maxi = max(maxi, i);
        }

        return max(0LL, (upper - maxi) - (lower - mini) + 1); //returning 0 as long long
    }
};

easy if we assume first element of hidden to be x then next will be x+diff[0] and so one hidden=[x,x+diff[0],x+diff[0]+diff[1]....]==(x+prefixsum[i]) alright
now we have to check the limit of hidden should be b/w lower and upper so x+min(prefixsum)>=lower and x+max(prefixsum)<=upper or we can say that
x<=lower-min(prefixsum) and upper-max(prefixsum)<=x ===>  we got the range as (lower-min(prefixsum),upper-max(prefixsum)) alright 

so this is the range which has total no. of hidden pairs , to get this (L,U)==> U-L+1 this is the answer alright
