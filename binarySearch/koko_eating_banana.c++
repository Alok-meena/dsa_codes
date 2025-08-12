875. Koko Eating Bananas
Solved
Medium
Topics
premium lock icon
Companies
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109






brute force : O(n*maxval)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int sum=*max_element(piles.begin(),piles.end());
        int ans=-1;

        for(int i=1;i<=sum;i++){
            long long total=0;
            for(auto banana:piles){
                total+=ceil(1LL*(double)banana/(double)i);
            }
            if(total<=h){
                ans=i;
                break;
            }
        }

        return ans;
    }
};


optimized : O(n*log(maxval)) 

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int ans=-1;

        int i=1,j=maxi;
        while(i<=j){
            int mid=(i+j)/2;

            long long total=0;
            for(auto banana:piles){
                total+=ceil(1LL*(double)banana/(double)mid);
            }

            if(total<=h){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};
