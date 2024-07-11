Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i




#include <string.h>
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string newstring="";//always initialize it wiht "" 
        string s="";

        for(int i=S.length()-1;i>=0;i--){
            if(S[i]!='.'){
                s.push_back(S[i]);//pushback use hota hai character dalne ke liye
            }
            else{
                reverse(s.begin(),s.end());
                newstring=newstring+s;//aor puri string dalne ke liye concatenate
                newstring.push_back('.');// can do like this also newstring=newstring+"."; string dal skte hai not character
                s="";
            }
        }
      //at last character ke pahle dot nhi hoga to use reverse krke dal do
         reverse(s.begin(),s.end());
        newstring=newstring+s;
        return newstring;
        
    } 
};
