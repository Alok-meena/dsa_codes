



#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
int solve(vector<int>&v,int m){
    int n=v.size();
    priority_queue<int>pq;
    int couponsUsed=0;

    int totalPrice=0;
    for(int i=0;i<n;i++){
        pq.push(v[i]);
    }
    while(couponsUsed<m){
        int currentprice=pq.top();
        pq.pop();

        currentprice=currentprice/2;
        couponsUsed++;
        pq.push(currentprice);

    }
    while(!pq.empty()){
        int currentprice=pq.top();
        pq.pop();
        cout<<totalPrice<<" ";

        

        totalPrice+=currentprice;
    }
    cout<<endl;
    return totalPrice;
}
int main(){
    vector<int>v={2,4,10,78,97};
    int m;
    cout<<"enter the no. of coupons:";
    cin>>m;
    cout<<"min price to buy all items after applying n coupons is :"<<solve(v,m);
  
}
