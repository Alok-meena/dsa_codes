100432. Maximum Possible Number by Binary Concatenation
User Accepted:16200
User Tried:18079
Total Accepted:17529
Total Submissions:27388
Difficulty:Medium
You are given an array of integers nums of size 3.

Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.

Note that the binary representation of any number does not contain leading zeros.

 

Example 1:

Input: nums = [1,2,3]

Output: 30

Explanation:

Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.

Example 2:

Input: nums = [2,8,16]

Output: 1296

Explanation:

Concatenate the numbers in the order [2, 8, 16] to get the result "10100010000", which is the binary representation of 1296.

 

Constraints:

nums.length == 3
1 <= nums[i] <= 127







class Solution {
public:
    string toBinaryString(int num) {
        string binary = "";
        while (num > 0) {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }
        return binary;
    }
    int maxGoodNumber(vector<int>& nums) {
        int maxno=0;
        
        sort(nums.begin(),nums.end());
        
        do{
            string currentstring="";
            for(int i:nums){
                currentstring+=toBinaryString(i);
            }
            
            int currentnumber=stoi(currentstring,0,2);
            maxno=max(maxno,currentnumber);
        }
        while(next_permutation(nums.begin(),nums.end()));
        
        return maxno;
    }
};
