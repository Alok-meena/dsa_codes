brute force : t.c:- O(mlogn)

class Solution {
  public:
    int power(int x,int n){
        int ans=1;
        while(n>0){
            if(n&1){
                ans=ans*x;
                n=n-1;
            }
            else{
                x=x*x;
                n/=2;
            }
        }
        
        return ans;
    }
    int nthRoot(int n, int m) {
        // Code here
        for(int i=1;i<=m;i++){
            if(power(i,n)==m) return i;
            else if(power(i,n)>m) break;
        }
        return -1;
    }
};


optimized:

class Solution {
  public:
    int power(int x,int n){
        int ans=1;
        while(n>0){
            if(n&1){
                ans=ans*x;
                n=n-1;
            }
            else{
                x=x*x;
                n/=2;
            }
        }
        
        return ans;
    }
    int nthRoot(int n, int m) {
        // Code here
        int low=1;
        int high=m;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(power(mid,n)==m) return mid;
            else if(power(mid,n)<m){
                low=mid+1;
            }
            else high=mid-1;
        }
        
        return -1;
    }
};

t.c:-O(logm * logn) and both are separate complexities cannot combine alright


but in above power approach if high is 10^9 then and if n=10 then it can become 10^90 which can cause overflow so we have to optimzed
so the thing is if the curr val becomes greater than m then dont compute further just break the statement alright

class Solution {
  public:
    int power(int mid,int n,int m){
        int val=1;
        for(int i=1;i<=n;i++){
            val=val*mid;
            if(val>m) return 2;
        }
        
        if(val==m) return 1;
        return 0;
    }
    int nthRoot(int n, int m) {
        // Code here
        int low=1;
        int high=m;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(power(mid,n,m)==1) return mid;
            else if(power(mid,n,m)==0){
                low=mid+1;
            }
            else high=mid-1;
        }
        
        return -1;
    }
};

t.c:-O(logm * n)
