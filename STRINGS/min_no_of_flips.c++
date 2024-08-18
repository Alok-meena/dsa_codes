Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

Example 1:

Input:
S = "001"
Output: 1
Explanation: 
We can flip the 0th bit to 1 to have
101.


Example 2:

Input:
S = "0001010111" 
Output: 2
Explanation: We can flip the 1st and 8th bit 
bit to have "0101010101"


  t.c:-O(n) and s.c:-O(1)

#include <math.h>
#include <algorithm>
#include <string.h>

int minFlips (string S)
{
    // your code here
    int n=S.length();

   //these two cases are possible and if these are not then increment the count as in that case only flips are required 
  
    int case1=0;//0 at even position
    int case2=0;//0 at odd position
    
    for(int i=0;i<n;i++){

        
        if(i%2==0 && S[i]=='1') case1++;//to case 1 me 0 ad even position chahihe to even pe ager 1 hai to ++ and odd pe ager 0 hai to ++ as 0 even pe chahihe 
        //same for the case2
        else if(i&1 && S[i]=='0') case1++;
        else if(i&1 && S[i]=='1') case2++;
        else if(i%2==0 && S[i]=='0') case2++;
    }
    
    return min(case1,case2);

    
}
