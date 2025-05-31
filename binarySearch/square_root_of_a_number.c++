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



class Solution {
public:
    int mySqrt(int x) {
        int l=1;
        int h=x;
        int ans=0;

        while(l<=h){
            int mid=l+(h-l)/2;

            if((long long)mid*mid<=x){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        
        return ans;
    }
};

nth root

#include <bits/stdc++.h>
using namespace std;


brute force check each no. from 1 to given number multiply that n times check if equal to target or not that's it O(n*m) alright


int main() {
    // Define the grammar as a map of non-terminal to its productions
    vector<int>arr={4,5,1,2,3};
    int Num=65;

    int low=0;
    int high=Num-1;
    int ans=0;
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
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans;
}

t.c:-O(nlog(m)) alright


for ans with decimal also

#include <bits/stdc++.h>
using namespace std;


int mySqrt(int x) {
        int l=1;
        int h=x;
        int ans=0;

        while(l<=h){
            int mid=l+(h-l)/2;

            if((long long)mid*mid<=x){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        
        return ans;
    }

double precise(int n,int tempsol,int precision){
    double factor=1;
    double ans=tempsol;

    for(int i=0;i<precision;i++){
        factor/=10;

        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }

    return ans;
}

so here for first precision .1 we are checking till .9 which will match then for next precision alright

we did pass till how many decimal places we want our ans alright so we did run it till it then each time added a factor of .1 and check that's all

int main() {
    // Define the grammar as a map of non-terminal to its productions
    int tempsol=mySqrt(101);
    double precise_ans=precise(101,tempsol,3);
    cout<<precise_ans;
}



