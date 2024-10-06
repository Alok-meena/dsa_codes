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



dekho suno what we have to do in this ques? 
to pahle to har no. ko binary me convert karna hai and then max value by concatenating so means we have to find all of the permutations which is n!
to bs sbhi permutations ko binary me convert kro concatenate kro and then find max


to convert to binary

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
     
    int n;
    
    cout<<"enter the number which you want to convert to binary :";
    cin>>n;
    
    string s="";
    while(n>0){
        s+=(n%2==0?"0":"1");
        n=n/2;
    }
    reverse(s.begin(),s.end());
    cout<<"binary conversion:"<<s;
    
    return 0;
}



code:

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
            
            int currentnumber=stoi(currentstring,0,2);//as the number in string is binary so do include 2 here to convert to base 10 (decimal)
            maxno=max(maxno,currentnumber);
        }
        while(next_permutation(nums.begin(),nums.end()));
        
        return maxno;
    }
};
