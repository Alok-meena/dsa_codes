Problem statement
For a given input string(str), write a function to print all the possible substrings.

Substring
A substring is a contiguous sequence of characters within a string. 
Example: "cod" is a substring of "coding". Whereas "cdng" is not as the characters taken are not contiguous
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 <= N <= 10^3
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
abc
Sample Output 1:
a 
ab 
abc 
b 
bc 
c 
 Sample Input 2:
co
Sample Output 2:
c 
co 
o








#include <bits/stdc++.h> 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string s,vector<string>&ans) {
    //Write your code here
    for(int i=0;i<s.length();i++){
        string temp="";
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            ans.push_back(temp);
        }
    }
}

int main() {
    string s;
    cin>>s;
    vector<string>ans;
    solve(s,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
