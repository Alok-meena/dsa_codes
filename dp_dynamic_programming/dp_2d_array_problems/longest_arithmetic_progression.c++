


VERY VERY IMP



1:recursion



 
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
            for(int j=i+1;j<n;j++){
                ans=max(ans,2+solve(i,A[j]-A[i],A));//index me i pass kiya taki isse pahle ke sare elements check kre diff ka
                //+2 kiya to involve both A[j] and A[i]
            }
        }
        return ans;
    }
};

2:memorization but using dp array where each index stores a map


class Solution {
public:
int solve(int index,int diff,vector<int>&a,unordered_map<int,int>dp[]){//by reference by nhi kiya because [] works as it
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

        unordered_map<int,int>dp[n+1];//this means we have a array and at each  index a map is stored which stores multiple differnces and their respective lengths
        
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

best solution

This solution is just same as the first approach of recursion

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n<=2) return n;
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int count=2;
                int n1=A[i];
                int n2=A[j];
                int diff=n2-n1;
                
                for(int k=i-1;k>=0;k--){
                    if(n1-A[k]==diff){
                        count++;
                        n1=A[k];
                    }
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};

O(n^2) is t.c and s.c:- is O(1)
