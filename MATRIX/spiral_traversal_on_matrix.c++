
Given a rectangular matrix, traverse the matrix in spiral form.

Examples:

Input:
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:


Input: 
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.







we are also taking count so that only the no. of elements present will be traversed not extra at all;


class Solution {
  public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        
        int left=0,right=col-1;
        int top=0,bottom=row-1;
        int total=row*col;
        int count=0;

        to count ko har bar check karna hai alright because vo har bar change ho rha hai alright 
        
        while(left<=right && top<=bottom && count<total){
            //storing the elements of the first row
            for(int i=left;count<total && i<=right;i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            
            //storing elements of the last column
            for(int i=top;count<total && i<=bottom;i++){
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            
            //storing the elements of the last row
            for(int i=right;count<total && i>=left;i--){
                 ans.push_back(matrix[bottom][i]);
                 count++;
            }
            bottom--;
            
            //storing the elements of the first column
            for(int i=bottom;count<total && i>=top;i--){
                 ans.push_back(matrix[i][left]);
                 count++;
            }
            left++;
        }
        
        
        return ans;
    }
};

or if it is not a square then 
Time Complexity: O(r*c), As we are traversing over each element of the matrix once, where r is the row and c is the column of the matrix.
Space Complexity: O(r*c), To store all elements of the matrix into an output array, where r is the row and c is the column of the matrix.


Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2), for returning the answer only.

but instead of doing this count of total elements we can just use two condtions inside also
becaues at while loop it will take care but inside it also the variables are changing so
apply conditions inside also

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    n=4;
    m=5;
    
    int arr[n][m]={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20}};

    
    int left=0;
    int right=m-1;
    int top=0;
    int bottom=n-1;
    int total=n*m;
    
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
        top++;

        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
        }
        cout<<endl;

    }
    
    
    
} 


the below code is also correct but the thing is i choose the parameters wrong as
to go left to right and right to left use these two only and same for top and bottom alright.


#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<vector<int>>v={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20}};
    int n=v.size();
    int m=v[0].size();
    int top=0;
    int bottom=n-1;
    int left=0;
    int right=m-1;
    int count=0;

    int total=n*m;

    while(left<=right and top<=bottom and count<total){
        int i=left;
        while(i<=right){
            cout<<v[top][i]<<" ";
            i++;
            count++;
        }
        
        left++;
        i=top+1;
        while(i<=bottom){
            cout<<v[i][right]<<" ";
            i++;
            count++;
        }

        right--;
        i=right;
        while(i>=top){
            cout<<v[bottom][i]<<" ";
            i--;
            count++;
        }

        bottom--;
        i=bottom;
        while(i>top){
            cout<<v[i][top]<<" ";
            i--;
            count++;
        }

        top++;
    }
}

           this is also correct but the thing is we have to use correct thing 
means left to right top remain same and top to bottom right remain same right to left bottom
reamin same and bottom to top left remain same alright

