You are given a 2-D Matrix 'MAT' having 'N' rows and 'M' columns, respectively. Your task is to find all elements which are present in each row of the matrix.

Note :
1. The output array can contain the elements in any particular order.

2. Even if a particular element appears more than once in each matrix row, it should still be present only once in the output array.
For Example :
Consider the matrix MAT [ [ 2, 3, 4, 7 ] , [ 0, 0, 3, 5 ] , [ 1, 3, 8, 9 ] ] having 3 rows and 4 columns respectively.
The output array should be [ 3 ] as 3 is the only element that is present in all three rows.






#include <algorithm>
#include <set>

//here instead of this we can also use this
//bool solve(const vector<int>& row, int value) {
//    return find(row.begin(), row.end(), value) != row.end();
//}
//this also has O(n) t.c:


bool solve(vector<int>&matrix,int value){
    bool present=false;
    int n=matrix.size();
    for(int i=0;i<n;i++){
        if(value==matrix[i]){
            present=true;
            break;
        }
    }
    return present;
}


vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // Write your code here
    int n=mat.size();
    if(n==0) return {};
    int m=mat[0].size();//means size of the first row==no. of columns
    vector<int>ans;
    set<int>s1;
    
    for(int i=0;i<m;i++){
        int value=mat[0][i];
        bool present=true;//do initialize it with true o/w error and if false then change it later

        for(int j=1;j<n;j++){
            present=solve(mat[j],value);
            if(present==false){
                break;
            }
        }

        if(present){
            s1.insert(value);
            
        }
    }

    for(auto i:s1){
        ans.push_back(i);
    }

    return ans;

}


t.c:-O(n*m^2) and s.c:-O(m)


2:optimal solution

#include <algorithm>
#include <set>
#include <vector>


vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // Write your code here
    int n=mat.size();
    if(n==0) return {};
    int m=mat[0].size();
    vector<int>ans;
    set<int>s1;

    for(int i=0;i<m;i++){
        s1.insert(mat[0][i]); //logm for one way and mlogm for m elements
    }
    
    //sorting as we are using binarysearch to solve the problem
    for(int i=0;i<n;i++){
        sort(mat[i].begin(),mat[i].end());//Time Complexity: O(n * m log m) in sorting
    }

    for(int i=1;i<n;i++){
        set<int>tempSet;
        for(auto val:s1){//acessing m elements and binarysearch logm *m times and n times also
            if(binary_search(mat[i].begin(),mat[i].end(),val)){//O(n * m * log m) in the worst case.
                tempSet.insert(val);
            }
        }
        s1=tempSet;
    }

    for(auto value:s1){
        ans.push_back(value);
    }

    return ans;
    
}

t.c:-O(n*(mlogm)) s.c :- O(m)
