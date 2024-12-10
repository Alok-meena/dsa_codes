#include <bits/stdc++.h>
using namespace std;

brute force O(n)

int main() {
    // Define the grammar as a map of non-terminal to its productions
    vector<int>arr={4,5,1,2,3};
    int n=25;

    int low=0;
    int high=n-1;

    // while(low<=high){
    //     int mid=(low+high)/2;

        

    // }
    int ans=INT_MIN;

    for(int i=1;i<=n;i++){
        if(i*i<=n){
            ans=max(ans,i);
        }
    }
    cout<<ans;

    

    
}



using binarysearch O(logn)


#include <bits/stdc++.h>
using namespace std;



int main() {
    // Define the grammar as a map of non-terminal to its productions
    vector<int>arr={4,5,1,2,3};
    int n=37;

    int low=0;
    int high=n-1;
    int ans=INT_MIN;

    while(low<=high){
        int mid=(low+high)/2;

        if(mid*mid<=n){
            ans=max(ans,mid);
            low=mid+1;
        }
        else if(mid*mid>n){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans;
}

nth root

#include <bits/stdc++.h>
using namespace std;



int main() {
    // Define the grammar as a map of non-terminal to its productions
    vector<int>arr={4,5,1,2,3};
    int Num=65;

    int low=0;
    int high=Num-1;
    int ans=INT_MIN;
    int n;
    cout<<"which Nth square root you want ?:";
    cin>>n;

    

    while(low<=high){
        int mid=(low+high)/2;
        int val=1;
        for(int i=1;i<=n;i++){
           val*=mid;
        }

        if(val<=Num){
            ans=max(ans,mid);
            low=mid+1;
        }
        else if(mid*mid>n){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans;
}

