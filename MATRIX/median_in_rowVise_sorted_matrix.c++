

Median in a row-wise sorted Matrix
Difficulty: HardAccuracy: 55.05%Submissions: 108K+Points: 8
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives 
us {1,2,3}. Hence, 2 is median.






1: brute force approach

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here    
        vector<int>ans;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                ans.push_back(matrix[i][j]);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        int index=ans.size()/2;
        return ans[index]; //return ans[R*C/2]; can use this also
    }
    
};

t.c:-O(n+m)+O((n+m)log(n+m)) and s.c:-O(m*n)


2:optimized solution

class Solution{   
public:
    int upper_bound(vector<int>&arr,int value){
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=n;//if value doesnot exist then end() will be returned
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>value){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>&matrix,int n,int value){
        
        int count=0;
        //it is doing binary search on every row
        for(int i=0;i<n;i++){
            count+=upper_bound(matrix[i],value);//to yha ham R*C ki jagah har ek row ko pass krke nlogm me upper_bound nikal rhe hai
        }
        return count;

      //n*logM as it is finding upper bound for everyrow
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        
        int low=INT_MAX;
        int high=INT_MIN;
        
        for(int i=0;i<R;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        
        
      
        int required=(R*C)/2;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int smallerEquals=solve(matrix,R,mid);//it will return elements <=mid
            if(smallerEquals<=required){
                low=mid+1;//as we want bigger value
            }
            else{
                high=mid-1;//bdi value mil gyi to piche jao because we have to find out just greater value
            }
        }
        
        return low;
        
        
    }

    
};

the first is for binarysearch and the second one is for counting smallervalues for every mid value
t.c:-O((log(INT_MAX)*(n*logM))


  as max value given is 10^9





  
