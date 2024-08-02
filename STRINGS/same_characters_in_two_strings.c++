
Given two strings A and B of equal length, find how many times the corresponding position in the two strings hold exactly the same character. The comparison should not be case sensitive. 

Example 1:

Input:
A = choice 
B = chancE
Output: 4
Explanation: characters at position 0, 1, 4 and 5
are same in the two strings A and B.
Example 2:

Input:
A = Geek 
B = gang
Output: 1
Explanation: charactera at position 0 is the
same in the two strings A and B.





#include <algorithm>
#include <cctype>
#include <string>

class Solution{
    public:
    int sameChar(string A, string B)
    {
        // code here 
        transform(A.begin(),A.end(),A.begin(),::tolower);
        transform(B.begin(),B.end(),B.begin(),::tolower);
        
        int count=0;
        for(int i=0;i<A.length();i++){
            if(A[i]==B[i]){
                count++;
            }
        }
        
        return count;
    }
};
