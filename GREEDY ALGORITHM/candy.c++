
Code
Test Result
Testcase
Testcase
135. Candy
Solved
Hard
Topics
premium lock icon
Companies
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104




brute force 

t.c:O(3n) and s.c:O(2n)


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        int sum=0;

        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                left[i]=1+left[i-1];
            }
            else if(ratings[i]<ratings[i-1]){
                left[i]=1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=1+right[i+1];
            }
            else if(ratings[i]>ratings[i+1]){
                right[i]=1;
            }
        }

        for(int i=0;i<n;i++){
            sum+=max(left[i],right[i]);
        }

        return sum;
    }
};
