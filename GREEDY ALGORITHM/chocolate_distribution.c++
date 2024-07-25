Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

Example 1:

Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following M packets :{3, 4, 9, 7, 9}.


//bss hamne ek widow chla di m size ki aor max - min krte ja rhe hai

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
     sort(a.begin(),a.end());
     long long mini=INT_MAX;
     for(int i=0,j=i+m-1;j<n;j++,i++){
         long long maxvalue=a[j];
         long long minvalue=a[i];
         mini=min(mini,maxvalue-minvalue);
     }
     return mini;
    }   
};


2:

    class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(),a.end());
        long long mindiff=INT_MAX;
        for(int i=m-1;i<n;i++){
            mindiff=min(mindiff,a[i]-a[i-(m-1)]);
        }
        return mindiff;
    }   
};
