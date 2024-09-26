Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Example 1:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.



1:if we can use space then just make

#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &arr1, vector<long long> &arr2,int n,int m){
	// Write your code here.
  long long arr3[n+m];
  int left=0;
  int right=0;
  int index=0;
  while(left<0 && ight<m){
    if(arr1[left]<=arr2[right]){
         arr3[index]=arr1[left];
         left++;index++;
    }
    else{
         arr3[index]=arr2[right];
         right++;index++;
    }
  }

  while(left<n){
        arr3[index++]=arr1[left++];
  }

  while(right<m){
       arr3[index++]=arr2[right++];
  }
  for(nt i=0;i<n+m;i++){
       if(i<n) arr1[i]=arr3[i];
       else arr2[i-n]=arr3[i]; // as ab arr2 me index 0 pe dalna hai to i-n imp 
  }
	
}

2*O(n+m) is t.c and and O(n+m) is s.c

2: without using extra space

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i=0;
            int j=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(arr1[i]>arr2[j]){
                        swap(arr1[i],arr2[j]);
                        
                    }
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
            
            
        } 
};

but this will give tle



most optimized

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i=n-1;
            int j=0;

    //if we are able to take extra space then it will be just like merge sort
            while(i>=0 && j<m){
                if(arr1[i]>arr2[j]){
                    swap(arr1[i],arr2[j]);
                    i--;j++;
                }
                else{
                    break;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
            
            
        } 
};

t.c:-O(min(n,m))+O(nlogn)+O(mlogm)
  s.c:-O(1)
  //so first array ke max element ko second array ke min eleemnt se copare krvaay if 2nd array min element is bigger than max of first array
  //then we have to do nothing what we want is min elements in first array so move max from 1st to 2nd and min from 2nd array to first




  2nd approach using gap method



#include<vector>
#include <algorithm>

void swapvalues(vector<long long> &a, vector<long long> &b,long long index1,long long index2,bool samearray,int whicharray){
	if(samearray){
          if(whicharray==1){
			  if (a[index1] > a[index2]) {
            swap(a[index1], a[index2]);
          }
		  }
		  else{
			  if (b[index1] > b[index2]) {
            swap(b[index1], b[index2]);
          }
		  }
        } else {
          if (a[index1] > b[index2]) {
            swap(a[index1], b[index2]);
          }
        }
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	long long n=a.size();
	long long m=b.size();
	long long gap=(n+m)/2+(n+m)%2;//done to take the ceil value


	while(gap>0){
		long long left=0;
		long long right=left+gap;

		while(right<n+m){
			//both pointers in arr1
			if(right<n){
				swapvalues(a,b,left,right,true,1);
			}
			
			//one in arr1 and other in arr2
			else if(left<n && right>=n){
				swapvalues(a,b,left,right-n,false,0);//as arr2 me 0 based indexing krne ke liye
			}

			//both in arr2
			else if(left>=n){
				swapvalues(a,b,left-n,right-n,true,2);
			}
			left++;
			right++;
		}
		if(gap==1)break;
		gap=(gap/2)+(gap%2);
	}

	
}

t.c:-O(log2(n+m)+O(n+m)
  s.c:-O(1)


  ye vala part apna shi hai and ager dono me se kisi ek array me karna ho merge to dekho


88. Merge Sorted Array
Solved
Easy
Topics
Companies
Hint
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=n+m-1;

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }
        while(j>=0){
            nums1[k--]=nums2[j--];
        }
    }
};
