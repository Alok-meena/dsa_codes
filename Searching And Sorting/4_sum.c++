18. 4Sum
Attempted
Medium
Topics
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]



1) t.c:-O(n^4) and s.c:-O(no. of quads)*2 because one is the set and other is the ans in which u are returning the answer


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        set<vector<int>>s;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        long long sum=nums[i]+nums[j];
                        sum+=nums[k]+nums[l];
                        if(sum==target && i!=j && j!=k && k!=l){
                            vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};

2) t.c:-O(n^3)*log(m) where m is the no. of elementss in the hashset and s.c:-O(no. of quads)*2


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        set<vector<int>>s; //s.c O(no. of quads)
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long>hashset;// approximately it will store O(n)
                for(int k=j+1;k<n;k++){
                    long long value=nums[i]+nums[j]; //we did like this and also in hashset long long type so that there will not be any integer overflow 
                    //in a single line okk
                    value+=nums[k];
                    long long fourth=target-value;
                    if(hashset.find(fourth)!=hashset.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end()); //no. of quads
        return ans;
    }
};

3) now i want rid of the extra hashset used okk so will apply same logic of logn as done in 3 sum

  t.c:-O(n^3)*log(n) and s.c:-O(no. of quads) as we are using to return the answer and not using in any other case okk


  most optimized


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>>ans;
        int n=nums.size();

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            //yha ham continue hi krenge i++ nhi because vo to pahle hi outer loop me ho jayega niche k++ l-- kiya because unka separate loop nhi hai okk
           // aor yha niche dekho i>0 means if i is not the first element then only do this as we can only compare it with the previous in that case okk
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
               //same here if j is not the 1st element after i or 2nd element then only do this o/w not
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int k=j+1;
                int l=n-1;

                while(k<l){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k]+nums[l];
                    if(sum<target){//and yha compare target se karna 0 se nhi okk
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};

