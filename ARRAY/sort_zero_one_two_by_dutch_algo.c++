#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
    int arr[13]={1,1,1,0,0,0,2,2,2,0,0,1,1};
    
    
    int low=0;//points to the first 1
    int mid=0;//first unsorted
    int high=13-1;//last unsorted

    while(mid<=high){
        if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            //dont do mid++ because jo last element ko swap krke laye hai 
            //use bhi uski correct position pe lagana hai if it is 0/1 
            high--;
        }
    }
    
    for(auto i:arr){
        cout<<i<<" ";
    }
    
} 
