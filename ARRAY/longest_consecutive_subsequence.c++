Given an array of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers,
the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.






class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        sort(arr,arr+N);
      
         int ans=1;
         for(int i=0;i<N;i++){
             int length=1;
             int value=arr[i];
             for(int j=0;j<N;j++){
                 if(value+1==arr[j]){
                     value++;
                     length++;
                 }
             }
             ans=max(ans,length);
         }
         return ans;
    
    }
};

this brute force is also wrong for duplicate ele's

t.c:-O(n^2) and s.c:-O(1)

2: optimal solution


class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        sort(arr,arr+N);
      
        int longest_length=0;
        
        int count=0;
        int last_smaller=INT_MIN;
        
        for(int i=0;i<N;i++){
            if(arr[i]-1==last_smaller){
                count++;
                last_smaller=arr[i];
            }
            else if(arr[i]!=last_smaller){
                count=1;
                last_smaller=arr[i];
            }
            longest_length=max(longest_length,count);
        }
        return longest_length;
    
    }
};

or 

class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        int ans = 1;
        int n = arr.size();
        int currlen=1;

        sort(arr.begin(), arr.end());

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) continue;
            if (arr[i]==arr[i - 1]+1) {
                currlen++;
            }
            else{
                ans=max(ans,currlen);
                currlen=1;
            }
        }

        // Final update in case the longest sequence ends at the last index
        ans = max(ans,currlen); //this is necessary if at last ele are 5 5 then ans will not be updated in case of duplicate ele's alright that's why

        return ans;
    }
};

best 

t.c:-O(nlogn) nlogn for sorting is there and s.c:-O(1)


3:if we dont want to change the input array we will use unordered_set to have unique elements


class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int longest_length=1;
        
        unordered_set<int>st;
        
        for(int i=0;i<N;i++){
            st.insert(arr[i]);
        }
        
        for(auto i:st){
            
            //if just previous element does not exist then surely it should be the starting 
            //point o/w there is no point in starting with that eleemnt ex with 2 if 1 
            //already exists
            if(st.find(i-1)==st.end()){
                int count=1; //we have to start with count = 1 as we are checking further x+1 so if it is present then count should already be 1 alright
                int x=i;//store the starting point
                
                while(st.find(x+1)!=st.end()){
                    count++;
                    x++;
                }
                longest_length=max(longest_length,count);
                
            }
            
        }
        
        return longest_length;
    
    }
};

O(n) for inserting alright O(n) for traversing and we are starting from the start of each sequence alright so it is mpp O(n)+O(2n)=O(3n)

t.c:-O(3N) and s.c:-O(N) 

to main bat ye hai ki hamne only start element of sequence se hi start kra hai alright and it is linear
