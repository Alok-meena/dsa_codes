






#include <bits/stdc++.h>
using namespace std;

// #define minimum(a,b) (a<b?a:b)

void saydigit(int n,vector<string>&v){
    if(n==0) return ;

    int digit=n%10;
    n/=10;

    saydigit(n,v);
    cout<<v[digit]<<" ";
}

int main(){
    int n;
    cin>>n;
    vector<string>v={"zero","one","two","three","four","five","six","seven","eight","nine"};
    saydigit(n,v);
}
