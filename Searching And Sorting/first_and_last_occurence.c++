Given a sorted array arr containing n elements with possibly some duplicate, the task is to find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.


Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  
2 5
Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  
6 6
Explanation: 
First and last occurrence of 7 is at index 6.




1) O(n) t.c

class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first=-1;
        int last=-1;
        
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                first=i;
            }
            else if
        }
        
        return {first,last};
    }
};


class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first=-1;
        int last=-1;
        
        for(int i=0;i<n;i++){
            if(arr[i]!=x){
                continue;
            }
            if(first==-1) first=i;
            last=i;
        }
        
        return {first,last};
    }
};


2) optimized O(logn) constant space complexity


class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first=-1;
        int last=-1;
        
        int start=0;
        int end=n-1;
        
        while(start<=end){
            int mid=(end+start)/2;
            if(arr[mid]==x){
                first=mid;
                end=mid-1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        
        start=0;
        end=n-1;
        
        while(start<=end){
            int mid=(end+start)/2;
            if(arr[mid]==x){
                last=mid;
                start=mid+1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        return {first,last};
    }
};

we can also use the concept of lower and upper bound here as lower bound will return the first occurence and use upper bound to found the next element corresponding to the last occurence then return index -1 


class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first;
        int second;
        
        first=lower_bound(arr,arr+n,x)-arr;
        second=upper_bound(arr,arr+n,x)-arr-1;
        
        if((first==n || arr[first]!=x) || second==n){
            return {-1,-1};
        }
        
        return {first,second};
    }
};

O(logn)
