#include <bits/stdc++.h>
using namespace std;

int squareroot(int n){
    int low=1;
    int high=n;

    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(mid*mid<=n){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }

    return ans;
}

double precision(int n,int precision,int tempsol){
    double ans=tempsol;

    double factor=1;
    for(int i=0;i<precision;i++){
        factor/=10;
        for(double j=ans;j*j<=n;j=j+factor){
            ans=j;
        }
    }

    return ans;
}
int main(){
    int n;
    cout<<"enter the number:";
    cin>>n;

    int tempsol=squareroot(n);
    cout<<precision(n,5,tempsol);
}
