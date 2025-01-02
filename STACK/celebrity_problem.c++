








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
        
        while(s.size()!=1){
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
  
