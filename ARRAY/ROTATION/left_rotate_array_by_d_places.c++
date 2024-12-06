Given an unsorted array arr[] of size n. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. 

Note: Consider the array as circular.

Examples :

Input: n = 5, d = 2 arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated by 2 elements, it becomes 3 4 5 1 2.
Input: n = 10, d = 3 arr[] = {2,4,6,8,10,12,14,16,18,20}
Output: 8 10 12 14 16 18 20 2 4 6
Explanation: 2 4 6 8 10 12 14 16 18 20 when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.





1st:

  
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        for(int i=1;i<=d;i++){
            int value=arr[0];
            for(int i=0;i<n-1;i++){
                arr[i]=arr[i+1];
            }
            arr[n-1]=value;
        }
    }
};

can write like this also
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        
        int time=1;
        while(time<=d){
            int value=arr[0];
            for(int i=0;i<n-1;i++){
                arr[i]=arr[i+1];
            }
            
            arr[n-1]=value;
            time++;
        }
    }
};

t.c:-O(d*n) and s.c:-O(1)

2nd:

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        d=d%n;
        // code here
        int v[d];
        for(int i=0;i<d;i++){
            v[i]=arr[i];
        }
        
        for(int i=d;i<n;i++){
            arr[i-d]=arr[i];
        }
        
        int j=0;
        for(int i=n-d;i<n;i++){
            arr[i]=v[j++];
        }
    }
};

t.c:-O(n+d) and s.c:-O(d)

3rd:O(n) t.c and O(1) space

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        
        d=d%n;
        
        //First reversing d elements from starting index.
        reverse(arr, arr+d);
        //Then reversing the last n-d elements.
        reverse(arr+d, arr+n);
        //Finally, reversing the whole array.
        reverse(arr, arr+n);
    }
};

for right rotate 


#include <bits/stdc++.h>
#include <map>
using namespace std;

void reverse(int arr[],int low,int high){
        // code here
        while(low<=high){
            swap(arr[low],arr[high]);
            low++;high--;
        }
    }

int main(){
    int n=5;
    int arr[5]={1,2,3,4,5};
    
    int d;
    cout<<"enter no. of places to rotate:";
    cin>>d;
    //0 d-1
  // d n-1
   // 0 n-1 
  //reverse in this order

    reverse(arr,n-d,n-1);
    reverse(arr,0,n-d-1);
    reverse(arr,0,n-1);
    cout<<endl;
    for(auto i:arr){
        cout<<i<<" ";
    }
} 
