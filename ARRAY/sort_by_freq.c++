636. Sort Array by Increasing Frequency
Solved
Easy
Topics
Companies
Hint
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]




class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        map<char,int>freq;

        for(auto i:nums){
            freq[i]++;
        }

        vector<pair<int,int>>v;

        for(auto i:freq){
            v.push_back({i.second,i.first});
        }

        sort(v.begin(),v.end(),cmp);

        for(auto i:v){
            int count=i.first;
            while(count--){
                ans.push_back(i.second);
            }
        }

        return ans;
    }
};
