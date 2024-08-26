Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.

 

Example 1:

Input :
N = 9
Output:
2
Explanation:
1 and 4 are the only Perfect Squares
less than 9. So, the Output is 2.
Example 2:

Input :
N = 3
Output:
1
Explanation:
1 is the only Perfect Square
less than 3. So, the Output is 1.



class Solution {
  public:
    int countSquares(int N) {
        // code here
        int count=0;
        int i=1;
        int j=1;
        while(j<N){
            count++;
            i++;
            j=i*i;
        }
        return count;
    }
    
};



class Solution {
  public:
    int countSquares(int N) {
        // code here
        return sqrt(N-1);
    }
    
};

as it will return square root the the n-1 



O(logn)

class Solution {
  public:
    int solve(int N){
        int low=1;
        int high=N;
        int ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid*mid==N) return mid-1;
            else if(mid<=N/mid){//done to prevent the overflow okk
                ans=mid;//we are storing result here as we want sqrt of n-1 okk
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
        
    }
    int countSquares(int N) {
        // code here
        return solve(N);
        
        
    }
    
};
