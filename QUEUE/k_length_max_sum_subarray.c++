

1st is using kadane algo two pointer approach

t.c:-O(n) and s.c:-O(1)


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            ans=max(ans,sum);

            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
};

but the above one is only for maxsubarray sum okk no fixed length


2nd using queue

t.c:-O(n) and s.c:-O(k)


  #include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={3,-2,7,-2,3};
    int n=v.size();

    int ans;

    queue<int>q;
    int k=3;
    int sum=0;
    for(int i=0;i<n and i<k;i++){
        sum+=v[i];
        q.push(v[i]);
    }

    ans=sum;

    for(int i=k;i<n;i++){
        sum+=v[i];
        sum-=q.front();
        q.push(v[i]);
        q.pop();

        ans=max(ans,sum);
    }

    cout<<ans;
    
}

otherwise use two pointer approach t.c:-O(n) and s.c:-O(1)
  okk

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={3,-2,7,-2,3};
    int n=v.size();

    int ans;

    int k=3;
    int sum=0;
    for(int i=0;i<n and i<k;i++){
        sum+=v[i];
    }

    ans=sum;

    for(int i=k;i<n;i++){
        sum+=v[i];
        sum-=v[i-k];
        q.push(v[i]);
        q.pop();

        ans=max(ans,sum);
    }

    cout<<ans;
    
}
