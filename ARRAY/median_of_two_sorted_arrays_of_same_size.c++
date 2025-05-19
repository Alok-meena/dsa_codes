Median of 2 Sorted Arrays of Same Size
Difficulty: HardAccuracy: 52.17%Submissions: 2K+Points: 8Average Time: 35m
Given two sorted arrays a[] and b[] of equal size, find and return the median of the combined array after merging them into a single sorted array.

Examples:

Input: a[] = [-5, 3, 6, 12, 15], b[] = [-12, -10, -6, -3, 4]
Output: 0
Explanation: The merged array is [-12, -10, -6, -5, -3, 3, 4, 6, 12, 15]. So the median of the merged array is (-3 + 3) / 2 = 0.
Input: a[] = [2, 3, 5, 7], b[] = [10, 12, 14, 16]
Output: 8.5
Explanation: The merged array is [2, 3, 5, 7, 10, 12, 14, 16]. So the median of the merged array is (7 + 10) / 2 = 8.5.
Input: a[] = [-5], b[] = [-6]
Output: -5.5
Explanation: The merged array is [-6, -5]. So the median of the merged array is (-6 + -5) / 2 = -5.5.
Constraints: 
1 ≤ a.size(), b.size() ≤ 106
-106 ≤ a[i], b[i] ≤ 106



class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        vector<int>c(a.begin(),a.end());
        for(auto i:b) c.push_back(i);
        sort(c.begin(),c.end());
        
        int n=c.size();
        // if(n%2!=0) return c[n/2]; no need of this as always combined size would be even alright
        double v1=c[n/2];
        double v2=c[(n-1)/2];
        double v3=(v1+v2)/2;
        return v3;
    }
};

t.c:-O((n+m)log(n+m)) and s.c:-O(n+m)


2nd optimized:

O(n) t.c and O(1) s.c

what we will do listen both having same size right so if both have even size then even+even=even and odd+odd=odd and cant be even+odd and vice versa due to 
same size so we get to know that always both will have same size so we just have to find out n-1th and nth element and return their average alright

just do it


class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int i=0,j=0;
        int n=a.size();
        
        double m1=-1;//n-1th ele
        double m2=-1;//nth ele
        
        for(int k=0;k<=n;k++){
            //these are the cases for what if all ele of a are smaller than b then nth ele will 
            //be b[0] and a[0] in vice versa alright. 
            if(i==n){
                m1=m2;
                m2=b[0];
                break;
            }
            else if(j==n){
                m1=m2;
                m2=a[0];
                break;
            }
            
            //and if not above case then remaining case
            if(a[i]<=b[j]){
                m1=m2; //because m1 me chota and next max m1 me jo m2 me tha and update m2
                m2=a[i];
                i++;
            }
            else{
                m1=m2;
                m2=b[j];
                j++;
            }
        }
        
        return (m1+m2)/2;
    }
};

ab bat esi hai na ki ya to pahla pura array 2nd se chota hoga means a[n-1]<b[0] or b[n-1]<a[0] to is case ko handle kr liya and o/w normally bhi
m1 hmara 2nd max and m2 1st max so update m1 with m2 before updating m2 alright bs yhi concept hai 


and we can use binarysearch also for O(logn) t.c and s.c:-(1) alright
