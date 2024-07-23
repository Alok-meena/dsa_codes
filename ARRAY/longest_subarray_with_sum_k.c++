


Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 





brute force

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int longestSubarray=0;
    for(int i=0;i<a.size();i++){
        int sum=0;
        for(int j=i;j<a.size();j++){
            sum+=a[j];
            if(sum==k){
                longestSubarray=max(longestSubarray,j-i+1);
            }
        }
    }
    return longestSubarray;
}


2:prefix sum


#include <map>

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    map<long long,int>prefixSum;
    int sum=0;
    int maxlen=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        //if sum ==k then update length
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }

        //now check for remaining 

        long long rem=sum-k;
        //if present then also update the length
        if(prefixSum.find(rem)!=prefixSum.end()){
            int len=i-prefixSum[rem];//indices ka difference hi to nikalnege for the length
            maxlen=max(maxlen,len);
        }

        //so if sum if already present then it does not update
       // this is done as give problem in case of zeroes
        if(prefixSum.find(sum)==prefixSum.end()){
            prefixSum[sum]=i;
        }
    }
    return maxlen;
}

//this will word for all + , - , and zerores

t.c:-O(nlogn) for search also and can be O(n^2) for unordered map  and s.c:-O(n)


 3:more optimal is required



#include <map>

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left=0;
    int right=0;

    int maxlen=0;
    int sum=a[0];//initially we store in this the first element
    int n=a.size();

    while(right<n){

        //we are doing this as we have stored a[0] already so we have to check if it satisfies the condition
        while(left<=right && sum>k){//as we want there should be an array
            sum-=a[left];//modify the sum
            left++;//increment the left pointer
        }


        //baraber ho gya to update kr lo nhi to add krte jao
        if(sum==k){
            maxlen=max(maxlen,right-left+1);
        }
        
        right++;
        if(right<n) sum+=a[right];//do this within the bounds
    }
    return maxlen;
}

t.c:-o(2n) in worst case example left also traversed whole array along with right 

and s.c:-O(1) but this will only work for positive and zeroes for including the negative the previous one would be a better choice
