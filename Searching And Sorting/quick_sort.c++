class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high){
            int partition_index=partition(arr,low,high);
            quickSort(arr,low,partition_index-1);
            quickSort(arr,partition_index+1,high);
        }
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot=arr[low];
        
        int i=low;
        int j=high;
        
        while(i<j){
            
            while(arr[i]<=pivot and i<=high-1){
                i++;
            }
            
            while(arr[j]>=pivot and j>=low+1){
                j--;
            }
            
            
            if(i<j) swap(arr[i],arr[j]);
        }
        
        swap(arr[low],arr[j]);
        return j;
    }
};


this low+1 bound check is necessary in this case arr = {5, 10, 15, 20, 25}
low = 0, high = 4
pivot = arr[low] = 5

here j can go negative which will be wrong alright
