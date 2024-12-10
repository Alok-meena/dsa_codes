#include <bits/stdc++.h>
using namespace std;


bool binarysearch(vector<int>&v,int low,int high,int k){
    if(low>high){
        return false;
    }

    int mid=(low+high)/2;
    if(v[mid]==k) return true;
    
    if(v[mid]<k) return binarysearch(v,mid+1,high,k);
    return binarysearch(v,low,mid-1,k);
}
int main() {
    // Define the grammar as a map of non-terminal to its productions
    vector<int>v={1,3,5,6,7,9,10,11,23};
    int n=v.size();

    int low=0;
    int high=n;
    int val=60;

    cout<<binarysearch(v,low,high,n);
}
