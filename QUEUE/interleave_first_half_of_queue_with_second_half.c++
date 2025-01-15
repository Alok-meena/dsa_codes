








#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    vector<int>v;
    while(!q.empty()){
        v.push_back(q.front());
        q.pop();
    }

    int n=v.size();
    int i=0;
    int j=n/2;
    while(j<n){
        q.push(v[i]);
        q.push(v[j]);
        i++;j++;
    }
}

t.c:-O(n) and s.c:-O(n)
