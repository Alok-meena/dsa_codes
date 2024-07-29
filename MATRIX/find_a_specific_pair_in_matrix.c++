




Problem statement
You have been given a 2-D matrix ‘MAT’ of size ‘N’ x ‘N’ i.e. N rows and N columns. Your task is to find the maximum value of ‘MAT[a][b]’ - ‘MAT[c][d]’ over all possible indices (0 <= ‘a’, ‘b’, ‘c’, ‘d’ < ‘N’) such that . ‘a’ > ‘c’ and ‘b’ > ‘d’.

For example:


In this example, to maximise the value of ‘MAT[a][b]’ - ‘MAT[c][d]’ fulfilling the given conditions on indices (‘a’ > ‘c’ and ‘b’ > ‘d’), we take ‘a’ = 2, ‘b’ = 2, ‘c’ = 0 and ‘d’ = 0 .  So, ‘MAT[a][b]’ = 9 and ‘MAT[c][d]’ = 1 and the value of ‘MAT[a][b]’ - ‘MAT[c][d]’ => 9 - 1 = 8 which is maximum among all possible combinations.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= ‘T’ <= 100
2 <= ‘N’ <= 100
-10^5 <= ‘MAT[i][j]’ <= 10^5

Time Limit : 1 second
Sample Input 1:
2
3
1 2 3
4 5 6
7 8 9
3
-1 -2 -3
-4 -5 -6
-7 -8 -9
Sample Output 1:
8
-4
Explanation For Sample Output 1:
For sample test case 1: 

In this sample test case, to maximise the value of ‘MAT[a][b]’ - ‘MAT[c][d]’ fulfilling the given conditions on indices (‘a’ > ‘c’ and ‘b’ > ‘d’), we take ‘a’ = 3, ‘b’ = 3, ‘c’ = 0 and ‘d’ = 0 .  So, ‘MAT[a][b]’ = 9 and ‘MAT[c][d]’ = 1 and the value of ‘MAT[a][b]’ - ‘MAT[c][d]’ => 9 - 1 = 8 which is maximum among all possible combinations.

For sample test case 2: 

In this sample test case, to maximise the value of ‘MAT[a][b]’ - ‘MAT[c][d]’ fulfilling the given conditions on indices (‘a’ > ‘c’ and ‘b’ > ‘d’), we take ‘a’ = 1, ‘b’ = 1, ‘c’ = 0 and ‘d’ = 0 .  So, ‘MAT[a][b]’ = -5 and ‘MAT[c][d]’ = -1 and the value of ‘MAT[a][b]’ - ‘MAT[c][d]’ => (-5) - (-1) = -4 which is maximum among all possible combinations.



#include <bits/stdc++.h> 

int solve(vector<int>&mat1,vector<int>&mat2,int n){
	int maxi=INT_MIN;
	for(int i=0;i<n-1;i++){
		int value=mat1[i];
		for(int j=i+1;j<n;j++){
			maxi=max(maxi,mat2[j]-value);
		}
	}
	return maxi;
}
int findMaxValue(vector<vector<int>>& mat, int n) {
	// Write your code here.
	int ans=INT_MIN;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int value=solve(mat[i],mat[j],n);
			ans=max(ans,value);
			// cout<<ans<<" ";
		}
	}
	return ans;
}

it is similar to this
  #include <bits/stdc++.h> 

int findMaxValue(vector<vector<int>>& mat, int n) {
	// Write your code here.
	int ans=INT_MIN;
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			for(int c=a+1;c<n;c++){
				for(int d=b+1;d<n;d++){
				    ans=max(ans,mat[c][d]-mat[a][b]);
				}
			}
		}
	}
	return ans;
}


t.c:-O(n^4) and s.c:-O(1)

2:optimal



int findMaxValue(vector<vector<int>>& mat, int n) {
    // Auxiliary matrix to store the maximum value found from the current cell to the bottom-right corner.
    vector<vector<int>> maxValues(n, vector<int>(n, 0));

    // Initialize the value of the bottom-right corner.
    maxValues[n-1][n-1] = mat[n-1][n-1];//we have to do this ek value hogi tabhi ham comparison kr payenge

    // Fill the last row.
    for (int j = n - 2; j >= 0; j--) {
        maxValues[n-1][j] = max(mat[n-1][j], maxValues[n-1][j+1]);
    }

    // Fill the last column.
    for (int i = n - 2; i >= 0; i--) {
        maxValues[i][n-1] = max(mat[i][n-1], maxValues[i+1][n-1]);
    }

    // Fill the rest of the matrix.
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            maxValues[i][j] = max(mat[i][j], max(maxValues[i+1][j], maxValues[i][j+1]));
        }
    }

    int maxDifference = INT_MIN;

    // Iterate over the matrix to find the maximum difference.
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            maxDifference = max(maxDifference, maxValues[i+1][j+1] - mat[i][j]);
        }
    }

    return maxDifference;
}




t.c:-O(n^2) and s.c:-O(n^2)

	

#include <bits/stdc++.h> 
int findMaxValue(vector<vector<int>>& mat, int n) {
	// Write your code here.
    vector<vector<int>>maxMatrix(n,vector<int>(n));

    maxMatrix[n-1][n-1]=mat[n-1][n-1];
    //filling last row;
    for(int i=n-2;i>=0;i--){
        maxMatrix[n-1][i]=max(mat[n-1][i],maxMatrix[n-1][i+1]);//to bat suno current index to ham given mat me hi dekhenge bas nex element maxmatrix
	    //ka dkehnge taki uski max value se bhi compare kr skte
    }

    //filling for last col
    for(int i=n-2;i>=0;i--){
        maxMatrix[i][n-1]=max(mat[i][n-1],maxMatrix[i+1][n-1]);
    }

    //now fill the remaining matrix
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            maxMatrix[i][j]=max(mat[i][j],max(maxMatrix[i][j+1],maxMatrix[i+1][j]));
        }
    }

    //now compute the values;
    int ans=INT_MIN;
    for(int a=0;a<n-1;a++){
        for(int b=0;b<n-1;b++){
            ans=max(ans,maxMatrix[a+1][b+1]-mat[a][b]);
        }
    }

    return ans;
} 

this is mine written code
