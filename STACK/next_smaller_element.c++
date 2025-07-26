 Next Smaller Element
Moderate
80/80
Average time to solve is 25m
Contributed by
329 upvotes
Asked in companies
Problem statement
You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.

Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.

If for any array element the next smaller element does not exist, you should print -1 for that array element.

For Example:

If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10 ^ 5
0 <= ARR [i] <= 10 ^ 9

Time Limit: 1sec.
Sample Input 1:
2
4
2 1 4 3
3
1 3 2
Sample Output 1:
1 -1 3 -1
-1 2 -1
Explanation for Sample Input 1:
For the first test case : 
1) For ARR [1] = 2 ,  the next smaller element is 1. 
2) For ARR [2] = 1 ,  the next smaller element is -1 as no element in the array has value smaller than 1.
3) For ARR [3] = 4 ,  the next smaller element is 3.
4) For ARR [4] = 3 ,  the next smaller element is -1 as no element exists in the right of it.
Hence, we will return the array [ 1, -1, 3, -1] in this case.

For the second test case :
1) For ARR [1] = 1 ,  the next smaller element is -1 as no element in the array has value smaller than 1.
2) For ARR [2] = 3 ,  the next smaller element is 2.
3) For ARR [3] = 2 ,  the next smaller element is -1 as no element exists in the right of it.
Hence we will return the array [ -1, 2, -1 ] in this case.
Sample Input 2:
2
4
1 2 3 4
2
5 0
Sample Output 2:
-1 -1 -1 -1
 0 -1


  
by brute force approach we can do it by traversing the remaining part in each iteration so t.c:-O(n^2) and s.c:-O(1)




t.c:-O(n) and s.c:-O(n)




#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int>ans(n);
    stack<int>s;

    for(int i=n-1;i>=0;i--){
        while(!s.empty() and s.top()>=arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i]=-1;
        }
        else ans[i]=s.top();

        s.push(arr[i]);
    }

    return ans;
}


yes this is finding first smaller on right okk

but if we have to find min ele on right have to use priority_queue alright

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int>ans(n);

    priority_queue<int,vector<int>,greater<int>>s;

    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans[i]=-1;
        }
        else ans[i]=s.top();

        s.push(arr[i]);
    }

    for(auto i:ans) cout<<i<<" ";
}

int main(){
    vector<int>v={3,2,1};

    solve(v,v.size());
}
