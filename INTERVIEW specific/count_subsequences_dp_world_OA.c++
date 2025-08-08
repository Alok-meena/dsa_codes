#include <bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int solve(int pos,int idx,string s,int x,int y,int n,string a,unordered_map<string,bool>&check){
    if(pos<0 or pos>n) return 0;
    if(idx>=s.length()){
        if(pos==y and !check[a]){
            cout<<a<<" ";
            check[a]=true;
            return 1;
        }
        return 0;
    }

    int take=0,nottake=0;

    if(s[idx]=='r'){
        take=solve(pos+1,idx+1,s,x,y,n,a+'r',check);
    }
    else{
        take=solve(pos-1,idx+1,s,x,y,n,a+'l',check);
    }

    nottake=solve(pos,idx+1,s,x,y,n,a,check);

    return (take+nottake)%mod;
}
int main(){
    string s="rrlrlr";
    int x=1;
    int y=2;
    int n=6;

    string a;
    unordered_map<string,bool>check;
    int ans=solve(x,0,s,x,y,n,a,check);
    cout<<endl;
    cout<<ans;
}
