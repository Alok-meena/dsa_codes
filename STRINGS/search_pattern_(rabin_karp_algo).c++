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
        for (int i = 0; i <= n - m; ++i) {//yha pe <=n-m tk chlana pdega because last vale pattern ko bhi to consider karna hai okkk 
            //ex:- abcabc okk to ager n-m means 3 <3 means 2nd index which is till c to last pattern abc check nhi ho payega
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

this is also known as naive algo 


t.c:-O(n*m) and s.c:-O(n)


2) using kmp algo


class Solution
{
    public:
        void createLps(string s,vector<int>&lps){
            int n=s.length();

            int prefix=0;
            int suffix=1;
    
            while(suffix<n){
                if(s[prefix]==s[suffix]){
                    lps[suffix]=prefix+1;
                    suffix++;
                    prefix++;
                }
                else{
                    if(prefix==0){
                        lps[suffix]=0;
                        suffix++;
                    }
                    else{
                        prefix=lps[prefix-1];
                    }
                }
            }
        }
        vector <int> search(string pattern, string text)
        {
            //code here.
            
            //first of all we have find out the LPS OF pattern
            
            int n=text.length();
            int m=pattern.length();
            
            vector<int>ans;
            
            vector<int>lps(m,0);
            
            createLps(pattern,lps);  O(m) for this lps code 
            
            int first=0;
            int second=0;

            //and if we just have to calculate the first occurrence index then just add condition second<m && first<n then jaise hi pura pattern match hoga to 
            //uski length of second== m ho jayegi and loop break ho jayega


            O(n) for this traveral of the text string and the prev jumps in pattern are considered to be negligible
            
            while(first<n){
                if(text[first]==pattern[second]){
                    first++;
                    second++;
                }
                else{
                    //to ager match nhi hua to same kmp jaise piche vo part dhundho jo ki match ho rha tha pattern se bs pattern ke pointer ko vhi pe le jao and 
                    //continue
                    //not matched 
                    //then first ko aage bda do ager second already 0 pe hai to
                    if(second==0){
                        
                        first++;//vha code me prefix=0 then suffix ++  same yha hai second=0 to first++ jo ki aage bdta jayega 
                    }
                    else{
                        second=lps[second-1];
                    }
                }
                if(second==m) ans.push_back(first-second+1);
            }
            
            return ans;
            
        }
     
};

t.c:-O(n+m) and s.c:-O(m)

3:- (Rabin-Karp Algorithm) using this algo this question can also be solved

Like the Naive Algorithm, the Rabin-Karp algorithm also check every substring. But unlike the Naive algorithm, the Rabin Karp algorithm matches the hash value of the pattern with the hash value of the current substring of text, and if the hash values match then only it starts matching individual characters. So Rabin Karp algorithm needs to calculate hash values for the following strings.

Pattern itself
All the substrings of the text of length m which is the size of pattern.


