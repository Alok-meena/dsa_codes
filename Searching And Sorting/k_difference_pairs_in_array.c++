Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).







class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(i>0 && nums[i]==nums[i-1]) break;
                int value=nums[j]-nums[i];
                if(value==k){
                    // cout<<nums[j]<<"-"<<nums[i]<<endl;
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

t.c:-O(n^2) and s.c:-O(1)



2) optimized code t.c:-O(nlogn) and s.c:-O(n) 


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;

       //what we have done here is sort first and then store the pairs in set so that there will be only unique pairs
        sort(nums.begin(),nums.end());
        set<pair<int,int>>s;

        int i=0,j=1;
        while(j<nums.size()){
            int diff=nums[j]-nums[i];

            //if diff==k then what to do i++ j++ means dono pe se pointer ko aage bda do okk so that to exclude the similar pattern
            if(diff==k){
                s.insert({nums[i],nums[j]});
                i++;
                j++;
            }

            //in this case if diff>k then do increment i no j as j is alredy greater 
            else if(diff>k){
                i++;
            }
            //if smaller then do increment j as we want greater difference
            else{
                j++;
            }

            //if this happens then do increment both of them okk 
            if(i==j){
                j++;
            }
        }
        
        return s.size();
    }
};
