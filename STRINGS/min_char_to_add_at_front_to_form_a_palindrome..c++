Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
Note: A palindrome is a word which reads the same backward as forward. Example: "madam".

Example 1:

Input:
S = "abc"
Output: 2
Explanation: 
Add 'b' and 'c' at front of above string to make it
palindrome : "cbabc"
Example 2:

Input:
S = "aacecaaa"
Output: 1
Explanation: Add 'a' at front of above string
to make it palindrome : "aaacecaaa"







The ans for minimum no. of deletions to make a string palindrome will also be same because 
if we just remove the characters which are not a part of the lps(longest palindromic subsequence)
we'll get the ans...which is same as n-len(lps)



1st approach to find the longest prefix palindrome 

class Solution {
   
bool ispalindrome(string s){
   
   int l = s.length();
   int j;
   
   for(int i = 0, j = l - 1; i <= j; i++, j--)
   {
       if(s[i] != s[j])
           return false;
   }
   return true;
}


public:
   int minChar(string str){
       
       int cnt = 0, l=str.size();
       
       while(l>0){
           
           if(ispalindrome(str.substr(0,l-cnt))){
               break;
           }
           else{
               cnt++;
           }
       }
       
       return cnt;
   }
};


t.c:-O(n^2) s.c:-O(N)






2) using lps of kmp longest prefix suffix 

we did have the string add a separater then add the same string in reverse order 



class Solution {
public:
  	int lps(string s) {
	    // Your code goes here
	    int n=s.length();
	    
	    vector<int>lps(n,0);
	    
	    int prefix=0,suffix=1;
	    
	    while(suffix<n){
	        if(s[prefix]==s[suffix]){
	            lps[suffix]=prefix+1;
	            prefix++;suffix++;
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
	    
	    return lps[n-1];
	}
	
    int minChar(string str) {
       int n=str.length();
       
       string rev=str;
       reverse(rev.begin(),rev.end());
       str+='$';
       str+=rev;
       
       int LPS=lps(str);
       return n-LPS;
       
    }
    
};


t.c:-O(n) and s.c:-O(n)
