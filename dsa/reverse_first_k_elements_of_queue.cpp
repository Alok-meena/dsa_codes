approach 1:
#include <bits/stdc++.h> 
queue<int> reverse(queue<int>q,int k){
        int s=0;
        int e=k-1;
        int n=q.size();
        int *arr=new int[n];
        int i=0;
        while(!q.empty()){
            arr[i]=q.front();
            q.pop();
            i++;
        }
        while(s<e){
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
        for(int i=0;i<n;i++){
            q.push(arr[i]);
        }
        delete arr;
        return q;
    }
queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    if(q.empty()){
            return q;
        }
        q=reverse(q,k);
        return q;
}

approach 2 : using stack 
#include <bits/stdc++.h> 

queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    stack<int>s;
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty()){
        int val=s.top();
        q.push(val);
        s.pop();
    }
    int t=q.size()-k;
    while(t--){
        int val=q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
