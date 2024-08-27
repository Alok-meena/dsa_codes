Given an array arr. Find the majority element in the array. If no majority exists, return -1.

A majority element in an array of size n is an element that appears strictly more than n/2 times in the array.

Examples:

Input: arr[] = [3, 1, 3, 3, 2]
Output: 3
Explanation: Since, 3 is present more than n/2 times, so it is the majority element.
Input: arr[] = [7]
Output: 7
Explanation: Since, 7 is single element and present more than n/2 times, so it is the majority element.
Input: arr[] = [2, 13]
Output: -1
Explanation: Since, no element is present more than n/2 times, so there is no majority element.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)






1). brute force


class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int i,j,cnt = 0;
        for(i=0;i<size;i++){
            cnt = 0;
            for(j=0;j<size;j++){
                if(a[i] == a[j])
                    cnt++;
            }
            if(cnt > (size/2))
                return a[i];
        }
        return -1;
        
    }
};

t.c:-O(n^2) and s.c:-O(1)

t.c:-O(n) and s.c:-O(n)

class Solution {
  public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size) {

        // your code here
        unordered_map<int,int>m;
        for(int i=0;i<size;i++){
            m[arr[i]]++;
        }
        for(auto i:m){
            if(i.second>(size/2)) return i.first;
        }
        return -1;
    }
};

t.c:-O(n) and s.c:-O(n)

2) optimized code

class Solution {
  public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size) {

        // your code here
        int candidate;
        int count=0;

        //we know that if any element's count will be greater than n/2 than it's count will dominate the array 
        // so what we did maintain a count and candidate which we have to find out and if count==0 than set candi... and count=1 as it's count is 1
        // then if it is there count++ o/w count-- at last in candidate we will definitely have our majority element in the candidate key 
        // but we can definitely check it 
        for(int i=0;i<size;i++){
            if(count==0){
                candidate=arr[i];
                count=1;
            }
            else if(candidate==arr[i]){
                count++;
            }
            else{
                count--;
            }
        }
        
        count=0;
        for(int i=0;i<size;i++){
            if(arr[i]==candidate) count++;
        }
        
        return count>size/2?candidate:-1;
    }
};

t.c:-O(n) and s.c:-O(1)
