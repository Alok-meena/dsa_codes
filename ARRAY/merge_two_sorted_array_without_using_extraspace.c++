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
