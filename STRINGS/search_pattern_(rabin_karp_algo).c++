Given two strings, one is a text string and the other is a pattern string. The task is to print the starting indexes of all the occurrences of the pattern string in the text string. For printing, the Starting Index of a string should be taken as 1. The strings will only contain lowercase English alphabets ('a' to 'z').

Example 1:

Input: 
text = "birthdayboy"
pattern = "birth"
Output: 
[1]
Explanation: 
The string "birth" occurs at index 1 in text.
Example 2:

Input:
text = "geeksforgeeks"
pattern = "geek"
Output: 
[1, 9]
Explanation: 
The string "geek" occurs twice in text, one starts are index 1 and the other at index 9.


class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int>ans;
            
            // for(int i=1;i<=text.length();i++){
            //     for(int j=1;j<=pattern.length();j++){
            //         if(pattern[j]==text[i])
            //     }
            // }
            
            int i=1;
            int j=1;
            while(i<=text.length()){
                if(pattern[j]==text[i]){
                    i++;j++;
                    continue;
                }
                else{
                    if(j==pattern.length()) ans.push_back(i-j+1);
                    j=1;
                    i++;
                }
            }
            return ans;
        }
     
};
