Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countRev() which takes the string S as the input parameter and returns the minimum number of reversals required to balance the bracket sequence. If balancing is not possible, return -1. 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).










#include <math.h>

int countRev (string s)
{
    // your code here
    int n=s.length();
    if(n%2!=0) return -1; //if odd brackets then pair cant be formed
    
    int open=0,close=0,reversal;

    //yha se for loop me hamne jo valid pair the unhe hta diya hai and atlast invalid pair ke count hi bchenge open and close me
    for(auto i:s){
        if(i=='{') open++;
        else{
            if(i=='}' && open==0) close++;
            else open--;
        }
    }

    //and hame ceil value hi chahihe o/w incorrect answer aayega you can check by dry run
    reversal=(int)(ceil(open/2.0)+ceil(close/2.0)); //half open and close brackets ko reverse kiya hai bas
    
    return reversal;
    
}

O(n) t.c and s.c:-O(1)

floor(2.6)=2 and ceil(2.6)=3 are inbuilt functions in c++
