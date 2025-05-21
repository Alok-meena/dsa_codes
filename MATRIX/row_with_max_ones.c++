





class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int maxi=INT_MIN;
        int idx=-1;
        
        for(int i=0;i<arr.size();i++){
            int count=0;
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==1) count++;
            }
            if(maxi<count){
                maxi=count;
                idx=i;
            }
        }
        return idx;
    }
};

t.c:-O(n*m) and s.c:-O(1)



class Solution {
  public:
    int solve(vector<int>&v,int n){
        int value=lower_bound(v.begin(),v.end(),1)-v.begin();
        return n-value;
    }
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int row=-1;
        int oneCount=0;
        for(int i=0;i<arr.size();i++){
            int count=solve(arr[i],arr[0].size());
            if(count==arr[0].size()){
                return i;
            }
            if(oneCount<count){
                oneCount=count;
                row=i;
            }
        }
        return row;
    }
};

t.c:-O(nlog(m)) and s.c:-O(1)


most optimized

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int maxi=INT_MIN;
        int idx=-1;
        
        for(int i=0;i<arr.size();i++){
            int count=0;
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==1) count++;
            }
            if(maxi<count){
                maxi=count;
                idx=i;
            }
        }
        return idx;
    }
};

t.c:-O(n+m)


Matrix:
0 0 1 1
0 1 1 1
0 0 0 1
Start at top-right (i = 0, j = 3):

See 1 → move left → j = 2

See 1 → move left → j = 1

See 0 → move down → i = 1

See 1 → move left → j = 0

See 0 → move down → i = 2

See 0 → move down → i = 3 (exit)

You made 3 left moves and 3 down moves → O(m + n) steps.

alright 
