You are given a string 'S' of 'N' lowercase English Letters numbered from '0' to 'N - 1' and integer 'K'.

Determine whether there exists a subsequence of 'S' with length 'K' which is not sorted in non-decreasing order. Return '1' in that case. Otherwise, return '0'.

Example:
N = 4
K = 2
S = 'abaa'
There exists a subsequence formed by characters 'S[1]' and 'S[3]' i.e. 'ba', which is not sorted.
So, the answer for this case is '1'.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'K' <= 'N' <= 10^5
'a' <= S[i] <= 'z'

Time limit: 1 sec
Sample input 1:
2
3 1
aaa
4 4
cdab
Sample output 1:
0
1
Explanation of sample input 1:
For test case 1:
It can be proved that there doesn't exist a subsequence of length 'K' which is not sorted.
So, the answer for this case is '0'.

For test case 2:
The string itself is a possible subsequence of length '4' which is not sorted.



1:brute force

int doesThereExist(int n, int k, string &s) {
    // Write your code here.
    if(k==1) return 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]>s[j]){
                return 1;
            }
        }
    }

    return 0;
}

t.c:-O(n^2) and constant space complexity

2:

  int doesThereExist(int n, int k, string &s) {
    // Write your code here.
    if(k==1) return 0;
    
    string t=s;//so if it is not sorted in any case then it will not be equal to the sorted one simple

    sort(s.begin(),s.end());
    if(s==t){
        return 0;
    }

    return 1;
}
So, the answer for this case is '1'.
