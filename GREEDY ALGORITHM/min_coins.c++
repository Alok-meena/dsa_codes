Minimum number of Coins
Difficulty: EasyAccuracy: 51.25%Submissions: 93K+Points: 2
Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required. 


Example 1:

Input: N = 43
Output: 20 20 2 1
Explaination: 
Minimum number of coins and notes needed 
to make 43. 

Example 2:

Input: N = 1000
Output: 500 500
Explaination: minimum possible notes
is 2 notes of 500.






// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int>v={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        
        vector<int>ans;

        int tar=N;
        
        int i=9;
        while(i>=0){
            if(v[i]<=tar){
                tar-=v[i];
                ans.push_back(v[i]);
                if(tar==0) break;
            }
            else i--;
        }
        
        return ans;
    }
};
