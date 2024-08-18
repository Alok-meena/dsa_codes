Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions starting from the same coordinates, the list should contain the coordinates only once. 

Example 1:

Input: 
grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: 
{{0,0}}
Explanation: 
From (0,0) we can find "abc" in horizontally right direction.
Example 2:

Input: 
grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
word = "abe"
Output: 
{{0,0},{0,2},{1,0}}
Explanation: 
From (0,0) we can find "abe" in right-down diagonal. 
From (0,2) we can find "abe" in left-down diagonal. 
From (1,0) we can find "abe" in horizontally right direction.


yha pe main condition ye hai ki ager koi char match karta hai to hme same direction me hi sbhi ko check karna hai na ki zig zak way me
jaise a,b mil gya to agle sabhi isi direction me milne chaihe



class Solution {
public:
    bool solve(int index,int row,int col,int d1,int d2,vector<vector<char>>&grid,string &word){
        int n=grid.size();
        int m=grid[0].size();
        
        if(index==word.length()){
            return true;
        }
        
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col]!=word[index]){
            return false;
        }

        //to ager hamara char match hua ha i ex in a b c
                                                   d e f
                                                   g h i
        //to a match hua to ham yha aaye aor 0 1 dir me b match ho gya for string word="abc" right to ab
      //same direction me hi jane ke liye ham row+d1,col+d2 kr rhe hai taki same dir me hi move kre to b pe hai grid me 0 2 0+0,2+1 = 0,3 then c also matches
      //that's why we passed the direction also okkk
        return solve(index+1,row+d1,col+d2,d1,d2,grid,word);
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<int>>ans;
	    
	    vector<int>dir1={-1,-1,-1,0,1,1,1,0};//for row
	    vector<int>dir2={-1,0,1,1,1,0,-1,-1};//for col

     //to hamne pahle to sari 8 directions store kr li hai and then grid ko traverse kiya and if grid[i][j] == word[0] word ke pahle char ke to hame 8 directions me
    // traverse karna start karna hai okk and index 1 pass krnege as 0 vala to pahle hi compare kr liya hai and row col ke liye just sabhi directions ke 
    //liye i+dir1[k] and similar with j and then also pass the dir so that can be used in the function also if it comes true then push the starting index and break the loop
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
	                for(int k=0;k<8;k++){
    	                if(solve(1,i+dir1[k],j+dir2[k],dir1[k],dir2[k],grid,word)){
    	                    ans.push_back({i,j});
    	                    break;
    	                }
	                }
	            }
	        }
	    }
	    
	    return ans;
	}
};


Time Complexity: O(N*M*8^k) and s.c:-O(k) k=8



  
