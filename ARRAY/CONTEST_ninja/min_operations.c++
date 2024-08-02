

You are given two arrays 'A' and 'B' of the length 'N'. You can do any one of the following operations in one move:



Reverse the array 'A'.
Choose an integer 'i' in the range '[1, N]', then add or subtract any value from the 'A[i]'.

Your task is to find the minimum number of moves to make array 'A' equal to array 'B'.



Example:
'N' = 3
'A' = [1, 2, 5]
'B'' = [4, 2, 1]

The best possible moves are as follows:
- Reverse the array 'A' in the first move, and the new array 'A = [5, 2, 1]'.
- Subtract '1' from the position '1' in the second move, and the new array 'A = [4, 2, 1]'.
So, the answer is '2'.



O(n) and constant space complexity


look if elements are not equal then we have to perform operations on them then just count it o/w at the starting plz check if after reversing the array a
if it can be equal to the array b then return 1



int findMinimumMoves(int n, vector<int> a, vector<int>b){
    
    // Write your code here.
    if(a[0]==b[n-1]){
        reverse(a.begin(),a.end());
        int flag=1;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) flag=0;
        }
        return flag;
    }
    int operations=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            operations++;
        }
    }

    return operations;
}
