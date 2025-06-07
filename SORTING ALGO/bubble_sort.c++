

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={5,4,3,2,1};

    int n=5;
    
    for(int i=0;i<n;i++){
        //n-1 ek step km isliye because agle step se compare kr rhe hai alright
        for(int j=0;j<n-i-1;j++){ //ab ager last pos pe largest element aata jayega to usko compare krne ki require nhi hogi to har round me 1 step km chlega alright
            if(v[j]>v[j+1]) swap(v[j],v[j+1]);
        }
    }

    for(auto i:v) cout<<i<<" ";
}


it is stable , not adaptive , inplace
