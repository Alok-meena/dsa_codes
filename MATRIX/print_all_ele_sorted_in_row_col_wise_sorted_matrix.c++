Sorted matrix
Difficulty: BasicAccuracy: 63.49%Submissions: 58K+Points: 1
Given an NxN matrix Mat. Sort all elements of the matrix.

Example 1:

Input:
N=4
Mat=[[10,20,30,40],
[15,25,35,45] 
[27,29,37,48] 
[32,33,39,50]]
Output:
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50
Explanation:
Sorting the matrix gives this result.
Example 2:

Input:
N=3
Mat=[[1,5,3],[2,8,7],[4,6,9]]
Output:
1 2 3 
4 5 6
7 8 9
Explanation:
Sorting the matrix gives this result.
Your Task:
You don't need to read input or print anything. Your task is to complete the function sortedMatrix() which takes the integer N and the matrix Mat as input parameters and returns the sorted matrix.


Expected Time Complexity:O(N2LogN)
Expected Auxillary Space:O(N2)


Constraints:
1<=N<=1000
1<=Mat[i][j]<=105








class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int>ans;
        for(auto i:Mat){
            for(auto j:i) ans.push_back(j);
        }
        
        sort(ans.begin(),ans.end());
        
        vector<vector<int>>v(Mat.size(),vector<int>(Mat[0].size()));
        
        for(int i=0;i<Mat.size();i++){
            for(int j=0;j<Mat[0].size();j++){
                v[i][j]=ans.front();
                ans.erase(ans.begin(),ans.begin()+1);
            }
        }
        
        return v;
    }
    
    
    
};

O((n*m)log(n*m)) alright is the t.c and s.c : - O(n*m)
