Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.

If the characters in str1 can be changed to get str2, then two strings, str1 and str2, are isomorphic. A character must be completely swapped out for another character while maintaining the order of the characters. A character may map to itself, but no two characters may map to the same character.

Example 1:

Input:
str1 = aab
str2 = xxy
Output: 
1
Explanation: 
There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.
Example 2:

Input:
str1 = aab
str2 = xyz
Output: 
0
Explanation: 
There are two different characters in aab but there are three different charactersin xyz. So there won't be one to one mapping between str1 and str2.







class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1.length()!=str2.length()) return false;
        
        unordered_map<char,char>m1,m2;
        
        for(int i=0;i<str1.length();i++){
            char c1=str1[i];
            char c2=str2[i];
            
            if(m1.find(c1)!=m1.end()){
              //means ki c1 apna ager map me hai to uski mapping c2 ke sath hi hogi lekin nhi hai to return false not mapped correctly
                if(m1[c1]!=c2){
                    return false;
                }
            }
            else{
                m1[c1]=c2;
            }


            //ese hi string1 bhi string 2 se map honi chahihe
            if(m2.find(c2)!=m2.end()){
                if(m2[c2]!=c1){
                    return false;
                }
               
            }
            else{
                m2[c2]=c1;
            }
        }
        
        return true;
    }
};


t.c:-O(n) and s.c:-O(n)
