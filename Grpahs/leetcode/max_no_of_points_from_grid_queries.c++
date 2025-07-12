2503. Maximum Number of Points From Grid Queries
Attempted
Hard
Topics
Companies
Hint
You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.

 

Example 1:


Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.
Example 2:


Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
k == queries.length
1 <= k <= 104
1 <= grid[i][j], queries[i] <= 106



 brute force :

applying bfs for every query alright

but this code can given wrong ans when the min value is not present at curr cell
class Solution {
public:
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        
        int k=queries.size();
        vector<int>ans(k,0);

        for(int d=0;d<k;d++){
            vector<vector<bool>>vis(n,vector<bool>(m,false));

            int i=0,j=0;

            if(grid[i][j]>=queries[d]){
                ans[d]=0;
                continue;
            }

            queue<pair<int,int>>q;
            q.push({i,j});
            int points=1;
            vis[i][j]=1;

            while(!q.empty()){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                int dirx[4]={-1,0,0,1};
                int diry[4]={0,-1,1,0};    

                for(int f=0;f<4;f++){
                    int newi=i+dirx[f];
                    int newj=j+diry[f];

                    if(newi>=0 and newi<n and newj>=0 and newj<m and !vis[newi][newj] and grid[newi][newj]<queries[d]){
                        vis[newi][newj]=1;
                        points++;
                        q.push({newi,newj});
                    }
                }            
            }

            ans[d]=points;
        }

        return ans;
    }
};

t.c:-O(k*n*m) 


bhai ye uper vala tle isliye de rha tha because har pointke liye bfs lga rhe the


class Solution {
public:
    void solve(vector<vector<int>>&grid,int i,int j,int maxi,vector<vector<bool>>&vis,int m,int n,int &points){
        if(i<0 or j<0 or i>=m or j>=n or vis[i][j]) return;

        if(grid[i][j]>=maxi) return;

        vis[i][j]=true;
        points++;

        solve(grid,i-1,j,maxi,vis,m,n,points); //up
        solve(grid,i+1,j,maxi,vis,m,n,points);//down
        solve(grid,i,j-1,maxi,vis,m,n,points);//left
        solve(grid,i,j+1,maxi,vis,m,n,points);//right

       

    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int>ans;
        int m=grid.size();
        int n=grid[0].size();

        for(auto i:queries){
            int points=0;
            vector<vector<bool>>vis(m,vector<bool>(n,false));
            solve(grid,0,0,i,vis,m,n,points);
            ans.push_back(points);
        }
        return ans;
    }
};


this approach is giving tle using dfs approach t.c:-O(m*n*k)



bfs 

khuch nhi kiya hamne kya kiya ki query ko sort kr liya alright and smaller qury ka count aa gya jo ki uske aage ki query me bhi involve hoga that's why hamne ek
hi count bnaya hai alright


yha niche kya kiya hai ki sort kr diya queries ko alright and jitne point smallest query ko milenge vo aage add hi honge to bfs ek hi bar call ki hai hamne alrigh
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size();
        int n=grid[0].size();
        int k=queries.size();

        vector<pair<int,int>>query(k);
        for(int i=0;i<k;i++) query[i]={queries[i],i};

        sort(query.begin(),query.end());

       //pq me grid value and indices store kr liye alright

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=true;

        int count=0;
        vector<int>ans(k,0);
        int dirx[]={-1,0,0,1};
        int diry[]={0,-1,1,0};

        for(auto q:query){
            int query_val=q.first;
            int query_index=q.second;
         
            //ye index ko hamne ans me store krne ke liye liya hai alright dekho hamne sort kr liya taki ek hi count variable ko use karna pde tik hai
            //but correct index pe store ho that's why index be 2nd place pe store kiya hai tik hai 

         
            while(!pq.empty() and pq.top().first<query_val){
                int gridval=pq.top().first;
                int i=pq.top().second.first;
                int j=pq.top().second.second;
                pq.pop();

                count++;
                for(int d=0;d<4;d++){
                    int newi=i+dirx[d];
                    int newj=j+diry[d];
                    if(newi>=0 and newi<m and newj>=0 and newj<n and !vis[newi][newj]){
                        vis[newi][newj]=true;
                        pq.push({grid[newi][newj],{newi,newj}});
                    }
                }
            }
            ans[query_index]=count;
        }
        return ans;
    }
};


aor ye bat suno if u are thinking like in pq also if the min value is at the end index and if u are not able to reach there then just not it is the ques 

O(K∗Log(K)+M∗N∗Log(K))


written 2nd time


class Solution {
public:
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        
        int k=queries.size();

        vector<pair<int,int>>query;
        for(int i=0;i<k;i++){
            query.push_back({queries[i],i});
        }

        sort(query.begin(),query.end());
        vector<int>ans(k,0);

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dirx[]={-1,0,0,1};
        int diry[]={0,-1,1,0};

        int points=0;

        vis[0][0]=1;
        pq.push({grid[0][0],{0,0}});

        for(auto q:query){
            int query_val=q.first;
            int query_idx=q.second;

            while(!pq.empty() and pq.top().first<query_val){
                int gridval=pq.top().first;
                int i=pq.top().second.first;
                int j=pq.top().second.second;
                pq.pop();

                points++;


                for(int f=0;f<4;f++){
                    int newi=i+dirx[f];
                    int newj=j+diry[f];

                    if(newi>=0 and newi<n and newj>=0 and newj<m and !vis[newi][newj]){
                        vis[newi][newj]=1;
                        pq.push({grid[newi][newj],{newi,newj}});
                    }
                } 
            }
            
            ans[query_idx]=points;
        }

        return ans;
    }
};


and here pq is used to get min grid value each time alright and dont involve grid[0][0] check it will taken care of in the loop alright
