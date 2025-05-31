First and Last Position of an Element In Sorted Array
Easy
40/40
Average time to solve is 15m
821 upvotes
Asked in companies
Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.



Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.



Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
2. 'arr' may contain duplicate elements.


Example:
Input: 'arr' = [0,1,1,5] , 'k' = 1

Output: 1 2

Explanation:
If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
8 2
0 0 1 1 2 2 2 2


Sample output 1:
4 7


Explanation of Sample output 1:
For this testcase the first occurrence of 2 in at index 4 and last occurrence is at index 7.


Sample Input 2:
4 2
1 3 3 5


Sample output 2:
-1 -1


Expected Time Complexity:
Try to do this in O(log(n)).


Constraints:
1 <= n <= 10^5
0 <= k <= 10^9
0 <= arr[i] <= 10^9

Time Limit : 1 second


brute force:

#include <bits/stdc++.h>


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int first_occ=-1;
    int last_occ=-1;

    bool first=true;

    for(int i=0;i<n;i++){
        if(first and arr[i]==k){
            first_occ=i;
            first=false;
        }
        if(arr[i]==k) last_occ=i;
    }

    return {first_occ,last_occ};

}

t.c:-O(n) and s.c:-O(1)


optimized approach

#include <bits/stdc++.h>


int first_occurrence(vector<int>&arr,int n,int k){
    int low=0;
    int high=n-1;
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==k){
            ans=mid;
            high=mid-1;
        }
        else if(arr[mid]>k){
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;
}

int last_occurrence(vector<int>&arr,int n,int k){
    int low=0;
    int high=n-1;
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==k){
            ans=mid;
            low=mid+1;
        }
        else if(arr[mid]>k){
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int first_occ=first_occurrence(arr,n,k);
    int last_occ=last_occurrence(arr,n,k);

    return {first_occ,last_occ};

}

in this same ques if we have to find total occurrences of k then we have to do last_occ-first_occ+1 alright yes

t.c:-O(logn) and s.c:-O(1)
