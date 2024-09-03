Given an unsorted array arr of size n of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer (The first index contains B and second index contains A)

Examples

Input: n = 2 arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: n = 3 arr[] = {1, 3, 3} 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.



1) brute force approach O(n^2) t.c and O(1) s.c

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repeating=-1;
        int missing=-1;
        
        for(int i=1;i<=n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i==arr[j]){
                    count++;
                    if(count==2){
                        repeating=i;
                    }
                }
                
            }
            if(count==0) missing=i;
        }
        
        return {repeating,missing};
        
    }
};


2) optimized O(n) t.c and s.c

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repeating=-1;
        int missing=-1;
        
        vector<int>v(n+1,0);
        for(int i=0;i<n;i++){
            v[arr[i]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(v[i]==0) missing=i;
            else if(v[i]==2) repeating=i;
        }
        
        return {repeating,missing};
        
    }
};


3) using set O(n) t.c and s.c

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repeating=-1;
        int missing=-1;
        
        unordered_set<int>s;
        
        for(auto i:arr){
            if(s.find(i)!=s.end()){
                repeating=i;
            }
            s.insert(i);
        }
        
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()){
                missing=i;
            }
        }
        
        return {repeating,missing};
        
    }
};

nothing just check if the number is already present in the set if it is then it is the repeating number as set only contains unique numbers so there will be no duplicate numbers in the set
okk and

for finding the missing number check fom

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

t.c:-O(nlogn) and s.c:-O(n)



space optimized O(n) and O(1)



class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repeating=-1;
        int missing=-1;
        
        for(int i=0;i<n;i++){
            int index=abs(arr[i])-1;//it should be abs(arr[i]) because if the element is modified to negative element then this index would be wrong okk
            
            if(arr[index]<0){
                repeating=abs(arr[i]);
            }
            else{
                arr[index]=-arr[index];
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                missing=i+1;
                break;
            }
        }
        
        return {repeating,missing};
    }
};

in this we use the concept that goind to the arr[i-1] index and chec
