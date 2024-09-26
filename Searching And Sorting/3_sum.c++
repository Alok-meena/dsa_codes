15. 3Sum
Attempted
Medium
Topics
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


1) brute force solution 

using 3 loops and a set to have unique values each time after sorting each values


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0 && i!=j && i!=k && j!=k){ //using this condition so that each value is at different index
                        vector<int>temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};

t.c:-o(n^3)*log(n)

s.c:-2*O(no. of triplets)

2) optimized with O(n^2)*log(n) complexity and s.c:-O(n) + 2*O(no. of elements in the hashset)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>>s;
        int n=nums.size();
        

        for(int i=0;i<n;i++){
            set<int>hashset;
            for(int j=i+1;j<n;j++){
                int third=-(nums[i]+nums[j]);
                if(hashset.find(third)!=hashset.end()){
                     vector<int>temp={nums[i],nums[j],third};
                     sort(temp.begin(),temp.end());
                     s.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }

        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};


3rd : optimized

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};

t.c:-O(n*log(n)) + O(n^2) (for n and inside loops which is approximately n)

to isme khuch nhi hai i fix rkha aor baki 2 pair ko dhundha and to avoid duplicate values and use of set do increment i/j/k if nums[i]==nums[i-1] okk






