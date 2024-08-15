Find the number of occurrences of a given search word in a 2d-Array of characters where the word can go up, down, left, right, and around 90-degree bends.
Note: While making a word you can use one cell only once.


Example 1:

Input: 
R = 4, C = 5
mat = {{S,N,B,S,N},
       {B,A,K,E,A},
       {B,K,B,B,K},
       {S,E,B,S,E}}
target = SNAKES
Output:
3
Explanation: 
S N B S N
B A K E A
B K B B K
S E B S E
Total occurrence of the word is 3
and denoted by color.
Example 2:

Input:
R = 3, C = 3 
mat = {{c,a,t},
       {a,t,c},
       {c,t,a}}
target = cat
Output:
5
Explanation: Same explanation
as first example.






class Solution{
    public:
    
    int solve(int i,int j,int index,int size,string target,vector<vector<char>>&mat){
        int found=0;
        int n=mat.size();
        int m=mat[0].size();
        
        if(i>=0 && j>=0 && i<n && j<m && mat[i][j]==target[index]){ //to ager pahla char and similarly loop me sare char match hua then just store it 
          //and jaise jaise ham dhundh rhe hai jha jha mile mat[i][j] me vha 0 krte jao and index ++ as char matches if(index==size) found=1;
          //else then checck in all four directions right and jab aap fun call kroge to jab return kroge to fir se jo 0 kiya tha hamne jo char
          //match hua tha use temp ko use krke pahle jaisa kr do 
          //and ham 0 store kr rhe hai taki vo char vapas count na ho jaye / ya traverse na ho jaye
          
            char temp=target[index];
            mat[i][j]='0';
            index++;
            if(index==size){
                found=1;
            }
            else{
                found+=solve(i+1,j,index,size,target,mat);//down
                found+=solve(i-1,j,index,size,target,mat);//up
                found+=solve(i,j+1,index,size,target,mat);//right
                found+=solve(i,j-1,index,size,target,mat);//left
            }
            //backtrack
            mat[i][j]=temp;
        }

        //to ye uper hi call hota rhega and jaise hi sare condition finish to found =1 return ho jayega o/w 0
        return found;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        
        int n=mat.size();
        int m=mat[0].size();
        
        int size=target.length();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=solve(i,j,0,size,target,mat);
            }
        }
        
        return ans;
    }
};


Time Complexity : O(R*C*22*len), where len is length of target string.
Space Complexity : O(1), since no extra space is used here.
