 Check If The String Is A Palindrome
Easy
40/40
Average time to solve is 10m
Contributed by
503 upvotes
Asked in companies
Problem statement
You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

Note :

String 'S' is NOT case sensitive.
Example :

Let S = “c1 O$d@eeD o1c”.
If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 100 
1 <= Length(S) <= 10^4

Where 'T' denotes the number of test cases and 'S' denotes the given string.

Time Limit : 1 sec
Sample Input 1 :
2
N2 i&nJA?a& jnI2n
A1b22Ba
Sample Output 1 :
Yes
No
Explanation 1 :
For the first test case, S = “N2 i&nJA?a& jnI2n”. If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “n2injaajni2n”, which is a palindrome. Hence, the given string is also a palindrome.

For the second test case, S = “A1b22Ba”. If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “a1b22ba”, which is not a palindrome. Hence, the given string is not a palindrome.
Sample Input 2 :
3
codingninjassajNiNgNidoc
5?36@6?35
aaBBa@
Sample Output 2 :
Yes
Yes
No









#include <bits/stdc++.h> 

char tolowercase(char ch){
    if(ch>='A' and ch<='Z') return ch-'A'+'a';
    return ch;
}
bool checkPalindrome(string st)
{
    // Write your code here.
    int s=0;
    int e=st.length()-1;

    while(s<=e){
        char c1=st[s];
        char c2=st[e];

        if(!isalnum(c1)) s++;
        else if(!isalnum(c2)) e--;
        else{
            if(tolowercase(c1)!=tolowercase(c2)) return false;
            s++;e--;
        }
        
    }

    return true;
}
