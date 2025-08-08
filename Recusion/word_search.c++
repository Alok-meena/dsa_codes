



brute force:

t.c:-O(n*m*4^l) where l is len of word and s.c:-O(n*m)+O(l) due to recursive stack alright

class Solution {
public:
    bool solve(int i,int j,int idx,int n,int m,vector<vector<char>>&grid,string &word,vector<vector<int>>&vis){
        if(idx>=word.length()) return true;

        int dirx[4]={-1,0,0,1};
        int diry[4]={0,-1,1,0};

        for(int d=0;d<4;d++){
            int newi=i+dirx[d];
            int newj=j+diry[d];

            if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]==word[idx] and !vis[newi][newj]){
                vis[newi][newj]=1;
                if(solve(newi,newj,idx+1,n,m,grid,word,vis)) return true;
                vis[newi][newj]=0;
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    vector<vector<int>>vis(n,vector<int>(m,0));
                    vis[i][j]=1;
                    if(solve(i,j,1,n,m,board,word,vis)) return true;
                }
            }
        }

        return false;
    }
};


and space optimized making changes for visited in the given grid only


class Solution {
public:
    bool solve(int i,int j,int idx,int n,int m,vector<vector<char>>&grid,string &word){
        if(idx>=word.length()) return true;

        int dirx[4]={-1,0,0,1};
        int diry[4]={0,-1,1,0};

        for(int d=0;d<4;d++){
            int newi=i+dirx[d];
            int newj=j+diry[d];

            if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]==word[idx]){
                grid[newi][newj]='#';
                if(solve(newi,newj,idx+1,n,m,grid,word)) return true;
                grid[newi][newj]=word[idx];
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    char original=board[i][j];
                    board[i][j]='#';
                    if(solve(i,j,1,n,m,board,word)) return true;
                    board[i][j]=original;
                }
            }
        }

        return false;
    }
};


t.c is same and s.c is O(1)
