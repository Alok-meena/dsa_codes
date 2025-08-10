Missing And Repeating
Difficulty: EasyAccuracy: 24.83%Submissions: 624K+Points: 2Average Time: 30m
Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

Examples:

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and the missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: [3, 2]
Explanation: Repeating number is 3 and the missing number is 2.
Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: Repeating number is 1 and the missing number is 5.
Constraints:
2 ≤ n ≤ 106
1 ≤ arr[i] ≤ n




class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        unordered_map<int,int>freq;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        int repeating=-1;
        int missing=-1;
        
        for(auto i:arr){
            freq[i]++;
            if(freq[i]>1){
                repeating=i;
                break;
            }
        }
        
        
        
        for(int i=1;i<=n;i++){
            //have to do this because o/w ager 1 1 2 hua to ham 2 ko missing bta denge but vo to hai 
            if(find(arr.begin(),arr.end(),i)==arr.end()){
                missing=i;
                break;
            }
        }
        
        return {repeating,missing};
    }
};

t.c:-O(n^2) and s.c:-O(n)


optimized : t.c:-O(n)  and sc:-O(n)  

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        unordered_map<int,int>freq;
        int n=arr.size();
        
        int repeating=-1;
        int missing=-1;
        
        for(auto i:arr){
            freq[i]++;
        }
        
        for(auto i:freq){
            if(i.second>1){
                repeating=i.first;
                break;
            }
        }
        
        
        
        for(int i=1;i<=n;i++){
            if(freq.find(i)==freq.end()){
                missing=i;
                break;
            }
        }
        
        return {repeating,missing};
    }
};
