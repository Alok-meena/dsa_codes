#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
    int arr[13]={1,1,1,0,0,0,1,1,1,1,1,1,1};
    
    int maxicount=INT_MIN;
    int count=0;
    for(int i=0;i<13;i++){
        if(arr[i]==1){
            count++;
        }
        else{
            count=0;
        }
        maxicount=max(maxicount,count);
    }

    cout<<maxicount;
    
    
} 
