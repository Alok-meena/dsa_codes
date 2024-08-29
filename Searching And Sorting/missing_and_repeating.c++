Given an unsorted array arr of size n of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer (The first index contains B and second index contains A)

Examples

Input: n = 2 arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: n = 3 arr[] = {1, 3, 3} 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.





class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repeating;
        int missing;
        
        sort(arr.begin(),arr.end());
        if(arr[n-1]!=n) missing=n;
        
        unordered_map<int,int>m;
        
        for(auto i:arr){
            m[i]++;
        }
        for(auto i:m){
            if(i.second==2){
                repeating=i.first;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if((arr[i]-2)==arr[i-1]){
                missing=arr[i]-1;
                break;
            }
        }
        
        return {repeating,missing};
        
    }
};
