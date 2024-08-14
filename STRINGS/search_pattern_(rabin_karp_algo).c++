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


1: brute force

    //to yha problem hai ki hamne jist part of text string ko traverse kr liya hai us part ko hi fir se traverse kr rhe hai that's why t.c is not good
    HERE THE CHARACTERS ARE COMPARED REPEATEDLY

    #include <vector>
#include <string>
using namespace std;

//TO BAS IS CODE KE ANDER HAMNE KIYA KYA HAI HAR EK INDEX PE JAKE CHECK KR RHE HAI IF THE PATTERN IS PRESENT NHI HAI TO EK INDEX SE SHIFT KR RHE HAI (i++)
class Solution {
public:
    vector<int> search(string pattern, string text) {
        vector<int> ans;
        int n = text.length();
        int m = pattern.length();

        //and we are checking for every i as there can be overlappping patterns in text ex:- text=aaa patt=aa and ans=1 2 
        for (int i = 0; i <= n - m; ++i) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                ans.push_back(i + 1); // Store 1-based index
            }
        }
        
        return ans;
    }
};

t.c:-O(n*m) and s.c:-O(n)

2:- (Rabin-Karp Algorithm) using this algo this question can also be solved
