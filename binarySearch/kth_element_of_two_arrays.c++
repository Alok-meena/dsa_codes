K-th element of two Arrays
Difficulty: MediumAccuracy: 37.4%Submissions: 363K+Points: 4Average Time: 15m
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
Input: a[] = [1, 4, 8, 10, 12], b[] = [5, 7, 11, 15, 17], k = 6
Output: 10
Explanation: Combined sorted array is [1, 4, 5, 7, 8, 10, 11, 12, 15, 17]. The 6th element of this array is 10.
Constraints:
1 ≤ a.size(), b.size() ≤ 106
1 ≤ k ≤ a.size() + b.size()
0 ≤ a[i], b[i] ≤ 108






1) brute merge and do t.c O(n+m) and same s.c

2) merge using cnt s.c:-O(1) t.c above

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int cnt=0;
        int ele=-1;
        int n=a.size();
        int m=b.size();
        
        int i=0,j=0;
        
        while(i<n and j<m){
            if(a[i]<=b[j]){
                cnt++;
                if(cnt==k){
                    return a[i];
                }
                i++;
            }
            else{
                cnt++;
                if(cnt==k){
                    return b[j];
                }
                j++;
            }
        }
        
        while(i<n){
            cnt++;
            if(cnt==k){
                return a[i];
            }
            i++;
        }
        
        while(j<m){
            cnt++;
            if(cnt==k){
                return b[j];
            }
            j++;
        }
        
        return -1;
    }
};


3) do like median of 2 sorted arrays approach

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n=a.size();
        int m=b.size();
        
        if(n>m) return kthElement(b,a,k);
        
        int low=max(0,k-m),high=min(k,n);
        int left_elements=k;
        
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left_elements-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            
            if(mid1<n) r1=a[mid1];
            if(mid2<m) r2=b[mid2];
            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0) l2=b[mid2-1];
            
            if(l1<=r2 and l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        
        return 0;
    }
};

t.c:-O(
