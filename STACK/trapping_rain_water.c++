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

brute force: t.c:-O(N^2) and s.c:-O(1)


class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;

        int n=height.size();

        for(int i=1;i<n-1;i++){
            int j=i-1;
            int k=i+1;

            int max1=0;
            int max2=0;

            while(j>=0){
                max1=max(max1,height[j]);
                j--;
            }

            while(k<n){
                max2=max(max2,height[k]);
                k++;
            }

            if(max1<=height[i] or max2<=height[i]){
                continue;
            }
            else{
                int storage=min(max1,max2);
                water+=(storage-height[i]);
            }
        }

        return water;
    }
};

here we are calculating max on both sides of curr val and taking min out of them and subtracting curr value only then water can be stored alright
and we have to start from index 1 to n-1 because cant store water at 0 and n-1 because no higher building to left and right


optimized:

t.c:O(n) and s.c:-O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;

        int n=height.size();

        vector<int>premax(n,0);
        vector<int>nextmax(n,0);
        int maxi=height[0];

        for(int i=1;i<n;i++){
            if(maxi<height[i]){
                maxi=max(maxi,height[i]);
                premax[i]=maxi;
            }
            else premax[i]=maxi;
        }

        maxi=height[n-1];

        for(int i=n-2;i>=1;i--){
            if(maxi<height[i]){
                maxi=max(maxi,height[i]);
                nextmax[i]=maxi;
            }
            else nextmax[i]=maxi;
        }

        for(auto i:premax) cout<<i<<" ";
        cout<<endl;
        for(auto i:nextmax) cout<<i<<" ";
        cout<<endl;

        for(int i=1;i<n-1;i++){
            if(premax[i]<=height[i] or nextmax[i]<=height[i]){
                continue;
            }
            else{
                int storage=min(premax[i],nextmax[i]);
                water+=(storage-height[i]);
            }
        }

        return water;
    }
};

bs khuch nhi max ko store kr liya left and right dono ko curr index ke alright


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

2nd time most optimized approach


class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        int leftmax=0;
        int rightmax=0;

        int l=0;
        int r=n-1;

        int water=0;

        while(l<=r){
            if(height[l]<=height[r]){
                if(leftmax>height[l]){
                    water+=leftmax-height[l];
                }
                else leftmax=height[l];

                l++;
            }
            else{
                if(height[r]<=height[l]){
                    if(rightmax>height[r]){
                        water+=rightmax-height[r];
                    }
                    else rightmax=height[r];
                }

                r--;
            }
        }

        return water;
    }
};
