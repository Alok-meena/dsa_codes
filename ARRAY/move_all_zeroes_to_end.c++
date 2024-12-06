Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]

brute force:
int main(){
    int arr[6]={1,0,4,5,0,6};

    int a[6]={0};
    int j=0;
    for(auto i:arr){
        if(i>0){
            a[j]=i;
            j++;
        }
    }
    for(auto i:a){
        cout<<i<<" ";
    }
} 

t.c:-O(n) and s.c:-O(n)



using space we can store non zero elements and then store them at the front of the array and then store remaining places with zeroes

1st:

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        
        int zero=0;
        

        while(zero<n){
            if(nums[zero]==0){
                int i=zero+1;
                while(i<n && nums[i]==0){
                    i++;
                    continue;
                }
                if(i<n){
                    swap(nums[i],nums[zero]);
                }
                zero++;
            }
            else{
                zero++;
            }
        }
    }
};

also 


int main(){
    int arr[6]={1,0,4,5,0,6};

    for(int i=0;i<6;i++){
        if(arr[i]!=0) continue;
        int non_zero=-1;
        for(int j=i+1;j<6;j++){
            if(arr[j]!=0){
                non_zero=j;
                break;
            }
        }
        if(non_zero==-1) break;
        swap(arr[i],arr[non_zero]);
    }

    for(auto i:arr){
        cout<<i<<" ";
    }
    
} 

t.c:-O(n^2) worst case O(1) space complexity

2:
  class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        
        

        int zero=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[zero]);
                zero++;
            }
        }
    }
};

also 

this is also same as above


int main(){
    int arr[6]={1,0,4,5,0,6};

    int j=6;
    for(int i=0;i<6;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<6;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    for(auto i:arr){
        cout<<i<<" ";
    }
    
} 


O(n) and O(1) are t.c and s.c



