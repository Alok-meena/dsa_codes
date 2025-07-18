
Given an array A[] of sorted positive integers. An array having no duplicates elements, find the Length of the Longest Arithmetic Progression (LLAP) in given array A[].


Example 1:

Input:
N = 6
A[] = {1, 7, 10, 13, 14, 19}
Output: 4
Explanation: The longest arithmetic 
progression is {1, 7, 13, 19}.

VERY VERY IMP

brute force store all subsequences of length 2 and check for ap and store longest length alright

class Solution {
  public:
    void solve(vector<int>&a,vector<int>output,vector<vector<int>>&ans,int i){
        if(i>=a.size()){
            if(output.size()>=2) ans.push_back(output);
            return;
        }
        
        solve(a,output,ans,i+1);
        
        output.push_back(a[i]);
        solve(a,output,ans,i+1);
    }
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        if(arr.size()<=1) return 1;
        
        vector<vector<int>>ans;
        vector<int>output;
        solve(arr,output,ans,0);
        
        int len=0;
        
        for(int i=0;i<ans.size();i++){
            int d=ans[i][1]-ans[i][0];
            int count=0;
            for(int j=1;j<ans[i].size();j++){
                if(ans[i][j]-ans[i][j-1]==d){
                    count++;
                }
                else break;
            }
            len=max(len,count+1);
        }
        return len;
    }
};

t.c and s.c : - O(2^n * n)


another brute force in which we will apply recursion later on alright


// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int maxlen=INT_MIN;
        int n=arr.size();
        if(n==1) return 1;
        
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int cnt=2;
                int diff=arr[j]-arr[i];
                int curr=arr[i];
                
                for(int k=i-1;k>=0;k--){
                    if(curr-arr[k]==diff){
                        cnt++;
                        curr=arr[k];
                    }
                }
                
                maxlen=max(maxlen,cnt);
            }
        }
        
        return maxlen;
    }
};


O(n^3) is t.c and s.c:- is O(1)

  

1:recursion






this code is same as above brute force
 
class Solution{   
public:
    int solve(int index,int diff,int a[]){
        //backward check
        //(to ye base case hai because hm ye func piche check kr rhe ki diff ka koi element hai kya)
        if(index<0){
            return 0;
        }
        
        int ans=0;
        for(int j=index-1;j>=0;j--){
            if(a[index]-a[j]==diff){
                ans=max(ans,1+solve(j,diff,a));//yha pe 1 add kiya har ek element ke liye jo add hoga
                //for j=index-1 jo include nhi hua hai and index ki jagah j because hme piche jana hai and fir j 
              //ek kadam aor piche jayega
            }
        }
        return ans;
    }
    int lengthOfLongestAP(int A[], int n) {
        // code here
        
        if(n<=2){
            return n;
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){//to i and j ko ap ke last element mana and then inke piche dekha using solve function
                ans=max(ans,2+solve(i,A[j]-A[i],A));//index me i pass kiya taki isse pahle ke sare elements check kre diff ka
                //+2 kiya to involve both A[j] and A[i]
            }
        }
        return ans;
    }
};

t.c:-O(n^3) and s.c:-O(n)

  
2:memorization but using dp array where each index stores a map


class Solution {
public:
int solve(int index,int diff,vector<int>&a,unordered_map<int,int> dp[]){//by reference by nhi kiya because [] works as it
        //backward index (to ye base case hai because hm ye func piche check kr rhe ki diff ka koi element hai kya)
        if(index<0){
            return 0;
        }

        if(dp[index].count(diff)){//so count return 1 if diff is present as a key in the map o/w returns 0
            return dp[index][diff];
        }
        
        int ans=0;
        for(int j=index-1;j>=0;j--){
            if(a[index]-a[j]==diff){
                ans=max(ans,1+solve(j,diff,a,dp));
            }
        }
        return dp[index][diff]=ans;//means is index pe is diff ke corresponding ans dal do
       //dp[i][diff] means i index tk is diff ke sath length longest ap store hoga yha
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }

        unordered_map<int,int> dp[n+1];//this means we have a array and at each  index a map is stored which stores multiple differnces and their respective lengths
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,2+solve(i,nums[j]-nums[i],nums,dp));//index me i pass kiya taki isse pahle ke sare elements check kre diff ka
            }
        }
        return ans;
    }
};

3:bottom-up

class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }

        unordered_map<int,int>dp[n+1];

        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=A[i]-A[j];//agla vala means bda 
                int count=1;//because hm i pe hai to vo to aayega hi

                //check if answer is already present hai to count ko update kr do length se
                if(dp[j].count(diff)){
                    count=dp[j][diff];
                    //to count ke ander j se i tk ka ans aa gya
                }

                dp[i][diff]=1+count;//to bs ab i ke ans me update kr diya hai to include the ith element
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)


another mehtod




4:space optimized O(n)

class Solution{   
public:

    int lengthOfLongestAP(int A[], int n) {
        // code here
        
        if(n<=2)
        return n;
        
        int ans=1;
        unordered_set<int>dp(A,A+n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int len=2;
                int diff=A[j]-A[i];
                int curr=2*A[j]-A[i];
                while(dp.find(curr)!=dp.end())
                {
                    len++;
                    curr=curr+diff;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};

s.c:-O(n) and t.c:-O(n^2)


5:O(1) space

O(1) Space Solution 

//User function template for C++




