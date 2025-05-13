Problem statement
You are given an integer ‘N’. We can reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two. Else, return false.

For Example :

Given :-
‘N’ = 218
Then the answer will be true because it can be rearranged to 128, which is 2 raised to the power of 7.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
2
100
218
Sample Output 1 :
0
1
Explanation of Sample Input 1 :
For the first test case :  
All the possible combinations of 100 start with 0, which is not allowed, and the only permutation where it starts with 1 is 100, which is not a power of 2. Therefore, the answer is false.

For the second test case :
Then the answer will be true because it can be rearranged to 128, which is 2 raised to the power of 7.
Sample Input 2 :
2
46
1
Sample Output 2 :
1
1

t.c:-O(nlogn)




#include <bits/stdc++.h> 
bool reorderedPowerOf2(int n)
{
	// Write your code here.
    string s=to_string(n);

    sort(s.begin(),s.end());

    for(int i=0;i<31;i++){
        int power=1<<i;
        string t=to_string(power);
        sort(t.begin(),t.end());
        if(s==t) return true;
    }
    return false;
}
