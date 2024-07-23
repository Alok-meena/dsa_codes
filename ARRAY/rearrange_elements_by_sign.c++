You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions. 




class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int n=nums.size()/2;
       int negative[n];
       int positive[n];
       int d=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            negative[d++]=nums[i];
        }
       }
       int f=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            positive[f++]=nums[i];
        }
       }

       int k=0;

       for(int i=0;i<nums.size()/2;i++){
        nums.push_back(positive[i]);
        nums.push_back(negative[i]);
       }
       return nums;

       
    }
};


2nd

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        
        int i=0;
        int j=0;
        for(int k=0;k<n;k++){
            if(nums[k]>0){
                ans[2*i]=nums[k];
                i++;
            }
            else if(nums[k]<0){
               ans[2*j+1]=nums[k];
               j++;
            }
        }
        
        

        return ans;
    }


/*  C++ program to rearrange
   positive and negative integers
   in alternate fashion while keeping
   the order of positive and negative numbers. */
#include <bits/stdc++.h>
using namespace std;

// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
    int tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}

void rearrange(int arr[], int n)
{
    int outofplace = -1;

    for (int index = 0; index < n; index++) {
        if (outofplace >= 0) {
            // find the item which must be moved into the
            // out-of-place entry if out-of-place entry is
            // positive and current entry is negative OR if
            // out-of-place entry is negative and current
            // entry is positive then right rotate
            //
            // [...-3, -4, -5, 6...] -->   [...6, -3, -4,
            // -5...]
            //      ^                          ^
            //      |                          |
            //     outofplace      -->      outofplace
            //
            if (((arr[index] >= 0) && (arr[outofplace] < 0))
                || ((arr[index] < 0)
                    && (arr[outofplace] >= 0))) {
                rightrotate(arr, n, outofplace, index);

                // the new out-of-place entry is now 2 steps
                // ahead
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }

        // if no entry has been flagged out-of-place
        if (outofplace == -1) {
            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index & 0x01)))
                || ((arr[index] < 0) && (index & 0x01))) {
                outofplace = index;
            }
        }
    }
}

// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{

    int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, n);
    
  // Function Call
    rearrange(arr, n);

    cout << "Rearranged array is \n";
    printArray(arr, n);

    return 0;
}
O(1) space 
