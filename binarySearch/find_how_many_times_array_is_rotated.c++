brute : find break point  O(n) t.c

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int len=0;
        
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>arr[i]){
                return i;
            }
        }
        return 0;
    }
};



optimized return min val index

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
       int n=arr.size();
       int idx=0;

    int low=0;
    int high=n-1;
    int ans=INT_MAX;

    while(low<=high){
        int mid=(low+high)/2;

        //left part sorted
        if(arr[low]<=arr[mid]){
            if(ans>arr[low]){
                ans=arr[low];
                idx=low;
            } //ager left sorted hai to min to low hi hoga alright
            low=mid+1;
        }
        else{
            if(ans>arr[mid]){
                ans=arr[mid];
                idx=mid;
            }  //ager right sorted hai to right me jane k ko fayda nhi for min as curr ele is possible min and update ans and go to left alright
            high=mid-1;
        }
    }
	return idx;
    }
};


O(logn)
