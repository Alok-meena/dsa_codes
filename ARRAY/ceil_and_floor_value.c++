
#include <algorithm>
int solve(vector<int>&v,int value,int n){
    
    int low=0;
    int high=n-1;
    int ans=-1;//if value doesnot exist then end() will be returned
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]<=value){
            ans=v[mid];//as lower_bound always return the index
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}


int lower_bound(vector<int>&v,int value,int n){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]>=value){
            ans=v[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	sort(a.begin(),a.end());
	int floorvalue=solve(a,x,n);//here gretest and equal to 
	int ceilvalue=lower_bound(a,x,n);//as ceil means smallest or equal to value which is same to lowerbound
	return {floorvalue,ceilvalue};

}
