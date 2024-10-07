Sort by Set Bit Count
Difficulty: EasyAccuracy: 36.7%Submissions: 51K+Points: 2
Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.

 
Example 1:
Input: 
arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
Output:
15 7 5 3 9 6 2 4 32
Explanation:
The integers in their binary
representation are:
15 - 1111
7  - 0111
5  - 0101
3  - 0011
9  - 1001
6  - 0110
2  - 0010
4  - 0100
32 - 10000
hence the non-increasing sorted order is:
{15}, {7}, {5, 3, 9, 6}, {2, 4, 32}


When two integers have an equal number of set bits, the sort() function will maintain their original relative order in the sorted array.


Using __builtin_popcount():

__builtin_popcount()  is a built-in function of GCC compiler. This function is used to count the number of set bits in an unsigned integer. In other words, it counts the number of 1’s in the binary form of a positive integer.

Syntax:

__builtin_popcount(int number);

This is a built-in function in GCC and Clang that counts the number of set bits (1s) in the binary representation of an integer.
For example, __builtin_popcount(5) returns 2 because 5 is 101 in binary, which has two set bits.


  1)

  class Solution{
    public:
    
    static bool cmp(int a,int b){
        return __builtin_popcount(a)>__builtin_popcount(b);
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        sort(arr,arr+n,cmp);
    }
};


#include <bits/stdc++.h> 
  
     bool cmp(int a,int b){
        return __builtin_popcount(a)>__builtin_popcount(b);
    }
void sortSetBitsCount(vector<int>& arr, int size)
{
	// Write your code here

	stable_sort(arr.begin(),arr.end(),cmp);
    return ;
}

use this as stable_sort will keep the relative ordering of same elements

BUT in interview etc we cant use the inbuilt functions so we have to write the code ourself



2)

 
class Solution{
    public:
    
    static int setbitcount(int n){
        int count=0;
        while(n>0){
            if(n&1){
                count++;
            }
            n=(n&(n-1));
        }
        return count;
    }
    static bool cmp(pair<int,int>a,pair<int,int>b){
        int setbit_a=setbitcount(a.first);
        int setbit_b=setbitcount(b.first);
        
        if(setbit_a==setbit_b){
            return a.second<b.second;
        }
        
        return setbit_a>setbit_b;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        for(int i=0;i<n;i++){
            arr[i]=v[i].first;
        }
        
    }
};
