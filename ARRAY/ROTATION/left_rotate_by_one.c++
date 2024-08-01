


#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    int val=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=val;
    return arr;
}


t.c:-O(N) and s.c:-O(1) but if we consider total space then yes we  have used O(N) space
