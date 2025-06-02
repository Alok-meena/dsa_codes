125. Valid Palindrome
Solved
Easy
Topics
premium lock icon
Companies
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.





class Solution {
public:

    bool isvalid(char ch){
        if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z') or (ch>='0' and ch<='9')) return true;
        return false;
    }

    char tolowercase(char &ch){
        if((ch>='a' and ch<='z') or (ch>='0' and ch<='9')) return ch;
        return ch-'A'+'a';
    }

    bool palindrome(string temp){
        int s=0;
        int e=temp.length()-1;

        while(s<=e){
            if(temp[s]!=temp[e]) return false;
            s++;e--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string temp;

        for(auto i:s){
            if(isvalid(i)){
                temp.push_back(i);
            }
        }

        for(auto &i:temp){
            i=tolowercase(i);
        }

        cout<<temp<<endl;

        if(palindrome(temp)) return true;
        return false;
    }
};
