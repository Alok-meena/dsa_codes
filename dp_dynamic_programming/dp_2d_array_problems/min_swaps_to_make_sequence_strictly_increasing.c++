You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

 

Example 1:

Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.
Example 2:

Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
Output: 1
 






GENERAL APPRAOCH I TRY BUT NOT CORRECT AS IT WILL NOT GIVE MIN ANS AND DOES TAKE IN CONSIDER SOME CASES

 class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int swapcount=0;
        for(int i=1;i<n;i++){
            if(nums1[i-1]<nums1[i]){
                
            }
            else{
                swapcount++;
                swap(nums1[i],nums2[i]);
            }
            if(nums2[i-1]<nums2[i]){
                
            }
            else{
                swapcount++;
                swap(nums1[i],nums2[i]);
            }
        }
        return swapcount;
    }
}; 

give wrong ans for this 

nums1 =
[0,4,4,5,9]
nums2 =
[0,1,6,8,10]

Use Testcase
Output
2
Expected
1


1:recursion


class Solution {
public:
    int solve(vector<int>&nums1,vector<int>&nums2,int index,int swapped){
        if(index>=nums1.size()){
            return 0;
        }

        //to apne array me -1 hai so use acces krne ke liye use kiya
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        int ans=INT_MAX;

        //catch
        if(swapped){
            swap(prev1,prev2);
        }

        //noswap case
        //when our array are strictly increasing till index
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=solve(nums1,nums2,index+1,0);
        }

        //swap condition
        //we will swap if nums1 element will no disort the order of nums2 so nums1>prev2 and same for nums2
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+solve(nums1,nums2,index+1,1));//1 add to include the swapcount to reach the condition
        }

        return ans;

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //first isert -1 at the starting
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int swapped=0;
        return solve(nums1,nums2,1,swapped);
    }
}; 

2:memorization

class Solution {
public:
    int solve(vector<int>&nums1,vector<int>&nums2,int index,int swapped,vector<vector<int>>&dp){
        if(index>=nums1.size()){
            return 0;
        }

        if(dp[index][swapped]!=-1){
            return dp[index][swapped];
        }

        //to apne array me -1 hai so use acces krne ke liye use kiya
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        int ans=INT_MAX;

        //catch
        if(swapped){
            swap(prev1,prev2);
        }

        //noswap case
        //when our array are strictly increasing till index
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=solve(nums1,nums2,index+1,0,dp);
        }

        //swap condition
        //we will swap if nums1 element will no disort the order of nums2 so nums1>prev2 and same for nums2
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+solve(nums1,nums2,index+1,1,dp));//1 add to include the swapcount to reach the condition
        }

        dp[index][swapped]=ans;
        return dp[index][swapped];

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //first isert -1 at the starting
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int swapped=0;
        vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));//to index 0 se n tk or can take n+1 and swapped either 0 or 1 so 2 column only
        return solve(nums1,nums2,1,swapped,dp);
    }
}; 


3:bottom-up

class Solution {
public:

    int solve(vector<int>&nums1,vector<int>&nums2){
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));

        for(int index=nums1.size()-1;index>=1;index--){//start with n-1 because n pe 0 ho already hai and due to index+1 do size of row n+1 so not out of range
            for(int swapped=1;swapped>=0;swapped--){
                    //to apne array me -1 hai so use acces krne ke liye use kiya
                    int prev1=nums1[index-1];
                    int prev2=nums2[index-1];
                    int ans=INT_MAX;

                    //catch
                    if(swapped){
                        swap(prev1,prev2);
                    }

                    //noswap case
                    //when our array are strictly increasing till index
                    if(nums1[index]>prev1 && nums2[index]>prev2){
                        ans=dp[index+1][0];
                    }

                    //swap condition
                    //we will swap if nums1 element will no disort the order of nums2 so nums1>prev2 and same for nums2
                    if(nums1[index]>prev2 && nums2[index]>prev1){
                        ans=min(ans,1+dp[index+1][1]);//1 add to include the swapcount to reach the condition
                    }

                    dp[index][swapped]=ans;
            }
        }
        return dp[1][0];//because pichle vale me 1 and 0 pass kiya tha to ans yhi pe hoga
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //first isert -1 at the starting
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1,nums2);
    }
}; 

t.c:-O(n) and s.c:-O(n)

4:space optimized  O(1)

class Solution {
public:

    int solve(vector<int>&nums1,vector<int>&nums2){

        int noswap=0;
        int swap=0;
        int curr_noswap=0;
        int curr_swap=0;

        for(int index=nums1.size()-1;index>=1;index--){//start with n-1 because n pe 0 ho already hai and due to index+1 do size of row n+1 so not out of range
            for(int swapped=1;swapped>=0;swapped--){
                    //to apne array me -1 hai so use acces krne ke liye use kiya
                    int prev1=nums1[index-1];
                    int prev2=nums2[index-1];
                    int ans=INT_MAX;

                    //catch
                    if(swapped){
                        int temp=prev1;
                        prev1=prev2;
                        prev2=temp;
                    }

                    //noswap case
                    //when our array are strictly increasing till index
                    if(nums1[index]>prev1 && nums2[index]>prev2){
                        ans=noswap;
                    }

                    //swap condition
                    //we will swap if nums1 element will no disort the order of nums2 so nums1>prev2 and same for nums2
                    if(nums1[index]>prev2 && nums2[index]>prev1){
                        ans=min(ans,1+swap);//1 add to include the swapcount to reach the condition
                    }

                    //now and curr me store kr liya
                    if(swapped){
                        curr_swap=ans;
                    }
                    else{
                        curr_noswap=ans;
                    }
            }
            swap=curr_swap;
            noswap=curr_noswap;
        }
        return min(swap,noswap);//we have to return the min answer
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //first isert -1 at the starting
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1,nums2);
    }
}; 


if u dont understand above solution of space optimization then this is the code for you

int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        vector<vector<int>>dp(nums1.size()+1,vector<int>(3,0));
        vector<int>curr(3,0);
        vector<int>next(3,0);

        for(int i=nums1.size()-1;i>=1;i--){
            for(int swapped=1;swapped>=0;swapped--){
                int prev1=nums1[i-1];
                int prev2=nums2[i-1];

                int ans=INT_MAX;

                if(swapped){
                    swap(prev1,prev2);
                }

                //notswap
                if(nums1[i]>prev1 and nums2[i]>prev2){
                    ans=next[0];
                }

                //swap
                if(nums1[i]>prev2 and nums2[i]>prev1){
                    ans=min(ans,1+next[1]);
                }

                curr[swapped]=ans;
            }
            next=curr;
        }

        return next[0];

    }
