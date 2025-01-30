Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, 
compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.



1st:



class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long tapwater=0;
        
        int prefixMax[n];
        prefixMax[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1],arr[i]);
        }
        
        int suffixMax[n];
        suffixMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMax[i]=max(suffixMax[i+1],arr[i]);
        }
        
        for(int i=0;i<n;i++){
            int leftmax=prefixMax[i];
            int rightmax=suffixMax[i];
            if(arr[i]<leftmax && arr[i]<rightmax){
                tapwater+=min(leftmax,rightmax)-arr[i];
            }
        }
        
        return tapwater;
    }
};

t.c:-O(n) and s.c:-O(n)

2nd:
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long tapwater=0;
        
        int rightmax=0;
        int leftmax=0;
        int l=0;
        int r=n-1;
        
        while(l<r){
            //we always have to take the smaller one
            if(arr[l]<=arr[r]){
                if(leftmax>arr[l]){
                    tapwater+=leftmax-arr[l];
                }
                else{
                    leftmax=arr[l];
                }
                l++;
            }
            else{
                if(rightmax>arr[r]){
                    tapwater+=rightmax-arr[r];
                }
                else{
                    rightmax=arr[r];
                }
                r--;
            }
        }
        return tapwater;
    }
};


O(N) and O(1)

