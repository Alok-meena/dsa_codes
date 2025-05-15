class Solution {
public:
    void merge(vector<int>&nums,int low,int high){
        vector<int>temp;
        int mid=low+(high-low)/2;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }

        while(left<=mid){
            temp.push_back(nums[left++]);
        }

        while(right<=high){
            temp.push_back(nums[right++]);
        }

       //here we are utilizing the given array itself to put these values 
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        
    }
    void mergesort(vector<int>&nums,int low,int high){
        if(low>=high){
            return ;
        }
        int mid=low+(high-low)/2;
      
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,high);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};

t.c:-O(nlog2(n)) and s.c:-O(n)




void merge(vector<int>&v,int low,int high,int mid){
    int left=low;
    int right=mid+1;

    vector<int>temp(high-low+1); //this is because if we have low to 4 and high to 5 then also it will create 5 size temp which we dont want just 
    //create size of high-low+1 +1 due to 0 based indexing okk
    int i=0;

    while(left<=mid and right<=high){
        if(v[left]<=v[right]){
            // temp.push_back(v[left++]);
            temp[i++]=v[left++];
        }
        else{
            temp[i++]=v[right++];
            // temp.push_back(v[right++]);
        }
    }

    while(left<=mid){
        temp[i++]=v[left++];
        // temp.push_back(v[left++]);
    }

    while(right<=high){
        temp[i++]=v[right++];
        // temp.push_back(v[right++]);
    }

    for(int i=low;i<=high;i++){
        v[i]=temp[i-low];
    }

    here i-low in temp because i is the indices of the original array alright and we want index from 0 for temp of size low to high

    ex:
    arr = [4, 2, 5, 3, 1]
low = 1, high = 3
So arr[1..3] = [2, 5, 3] needs sorting.

temp = sorted [2, 3, 5] → indices 0 to 2

i = 1 → arr[1] = temp[0]

i = 2 → arr[2] = temp[1]

i = 3 → arr[3] = temp[2]


}
void mergesort(vector<int>&v,int low,int high){
    if(low>=high){
        return;
    }

    int mid=(low+high)/2;

    mergesort(v,low,mid);
    mergesort(v,mid+1,high);
    merge(v,low,high,mid);
}
void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    mergesort(arr,0,n-1);
}
