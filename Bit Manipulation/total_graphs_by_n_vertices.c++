#include <iostream>
#include <math.h>
using namespace std;

#define MOD 1000000007


//log base 2 n complexity
long long solve(long long x,long long n){
    long long ans=1;

    while(n>0){
        cout<<ans<<" ";
        if(n%2==1){
            ans=ans*x;
            n=n-1;//reducing the no. to reach even power
        }
        else{
            x=x*x;
            n=n>>1;
        }
    }
    return ans;
}
long long power(int n){
    long long x=(long long)(n*(n-1))/2;
    cout<<x<<" "<<endl;
    return solve(2,x);
}
int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    cout<<power(n);
}
