










class Solution {
  public:
  
    bool possible(int idx,vector<int> &gas, vector<int> &cost,int n){
        int totalgas=0;
        int currgas=gas[idx]-cost[idx];
        
        int start=idx+1;
        if(start==n) start=0;
        while(start!=idx){
            totalgas=currgas+gas[start]-cost[start];
            currgas=totalgas;
            if(totalgas<0) return false;
            start++;
            if(start==n) start=0;
        }
        return true;
    }
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n=gas.size();
        
        for(int i=0;i<n;i++){
            if(gas[i]>=cost[i]){
                if(n==1) return i;
                if(possible(i,gas,cost,n)){
                    return i;
                }
            }
        }
        
        return -1;
    }
};

t.c:-O(n^2) and s.c:-O(1)


class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int start=0;
        int balance=0;
        int deficit=0;
        //yha hamne deficit introduce kiya for only one traversal means dekho
      // ye to clear hai hi ki ager ham abhi tk nhi kr paye to usse pahle kisi se bhi nhi aa payenge because uski gas+ balance jo piche se aa rhi hai unhe milake
      //hi nhi hua to ese kaise hoga right 
      //and now balance last me jo hoga usme deficit add kro start se pahle ki ager >=0 aaya to ham travel kr skte hai okk 
        
        for(int i=0;i<gas.size();i++){
            balance=balance+gas[i]-cost[i];
            if(balance<0){
                deficit+=balance;
                start=i+1;
                balance=0;
            }
        }
        
        if(balance+deficit>=0) return start;
        return -1;
    }
};

t.c:-O(n) and s.c:-O(1)
