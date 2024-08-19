Ninja and his friend are playing a game in which his friend picks N opening brackets ‘(‘ and N closing brackets ‘)’. He then mixes all of them randomly and generates a string 'BRACKETS'. He asks Ninja to balance ‘BRACKETS’.

Example:
Here are some examples of balanced BRACKETS "(())", "()()", "(())()".
Ninja can perform the following operation to balance BRACKETS. In one operation, Ninja can pick two adjacent brackets and swap them. His friend challenges him to accomplish the task in minimum possible operations. Ninja needs your help to do this.

Can you help Ninja to make the string ‘BRACKETS’ balanced in minimum possible swaps?

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= ‘T’ <= 100
1 <= ‘N’ <= 5000 
‘BRACKETS’[i]’ = ‘(‘ or ‘)’

Time Limit: 1 second
Sample Input 1:
2
2
()
2
)(
Sample Output 1:
0
1
Explanation For Sample Output 1:
For sample test case 1: 
In this sample test case, the given input string is already balanced. So the minimum number of swaps required to balance ‘BRACKETS’ is 0.

For sample test case 2: 
In this sample test case, if we swap position 0 with 1, then the string ‘BRACKETS’ becomes "()" which is balanced. So, the minimum number of swaps needed to balance ‘BRACKETS’ is 1. 
Sample Input 2:
2
3
())()(
2
))((
Sample Output 2:
 2
 3  

so yha bas hame adjacent ko swap karna hai to close mila to pahla open dhundhege tab tak unbalancedclose count karna hoga aapko okkk explanation in copy

#include <bits/stdc++.h> 
int miniNumSwaps(string brackets, int n) {
	// Write your code here.
	int open=0,close=0,swaps=0,unbalanced_closed=0;
        
        for(auto i:brackets){
            if(i=='('){
                open++;
                if(unbalanced_closed>0){//means still some unbalanced so do this
                    swaps+=unbalanced_closed;
                    unbalanced_closed--;//kiya because ek open ne ek close ko satisfy kr diya hai okk
                }
            }
            else{
                close++;
                unbalanced_closed=close-open;//to cound unbalanced 
            }
        }
        
        return swaps;
}

t.c:-O(n) and s.c:-O(1)
