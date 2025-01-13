

The Celebrity Problem
Difficulty: MediumAccuracy: 38.33%Submissions: 295K+Points: 4
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[0 1 0], [0 0 0], [0 1 0]]
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
Input: mat[][] = [[0 1], [1 0]]
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.
Input: mat[][] = [[0]]
Output: 0
Constraints:
1 <= mat.size()<= 3000
0 <= mat[i][j]<= 1








class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int ans=-1;
        int n=mat.size();
        int index=-1;
        for(int i=0;i<n;i++){
            bool possible_c=true;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    possible_c=false;
                    break;
                }
            }
            if(possible_c){
                index=i;
                break;
            }
        }
        
        bool celebrity=true;
        
        for(int i=0;i<n;i++){
            if(index!=i and mat[i][index]==0){
                celebrity=false;
                break;
            }
        }
        
        if(celebrity){
            ans=index;
        }
        
        return ans;
    }
};

t.c:-O(n^2) and s.c:-O(1)

optimized


class Solution {
  public:
    bool knows(vector<vector<int>>&mat,int a,int b){
        if(mat[a][b]==1){
            return true;
        }
        return false;
    }
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int>s;
        int n=mat.size();


        //push all possible candidates into the stack and then check two elements at a time
        for(int i=0;i<n;i++){
            s.push(i);
        }

        //s.size()!=1 this is wrong condition conditon should be >1 because for 4x4 matrix with all 1's 
        // stack will contain  3 2 1 0 in the 2 loops it will become empty and size is 0 not 1 so it will result into tle okk
        while(s.size()>1){
            int a=s.top();
            s.pop();
            
            int b=s.top();
            s.pop();
            
            if(knows(mat,a,b)){
                s.push(b);
            }
            else if(knows(mat,b,a)){
                s.push(a);
            }
        }
        
        int candidate=s.top();
        
        //row check and col check
        bool rowcheck=true;
        bool colcheck=true;
        for(int i=0;i<n;i++){
            //here i!=candidate condition is necessary because vo khud ko janta hoga na celebrity jo hai that's why it's i,i can be 1 which can give wrong answer
            if(i!=candidate and mat[candidate][i]==1){
                rowcheck=false;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(i!=candidate and mat[i][candidate]==0){
                colcheck=false;
                break;
            }
        }
        
        if(rowcheck and colcheck){
            return candidate;
        }
        else{
            return -1;
        }
    }
};

t.c:-O(n) and s.c:-O(n)
  
