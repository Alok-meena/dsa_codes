





class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int>ans;
        vector<vector<int>>ans2(N,vector<int>(N));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans.push_back(Mat[i][j]);
            }
        }
        
        sort(ans.begin(),ans.end());
        int k=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans2[i][j]=ans[k++];
            }
        }
        
        return ans2;
        
    }
};

t.c:-O(n^2) and s.c:-O(n^2)+O(n)
