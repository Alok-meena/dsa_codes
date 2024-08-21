You are given two strings S and X containing random characters. Your task is to find the smallest substring in S which contains all the characters present in X.

Example:

Let S = “abdd” and X = “bd”.

The windows in S which contain all the characters in X are: 'abdd', 'abd', 'bdd', 'bd'. 
Out of these, the smallest substring in S which contains all the characters present in X is 'bd'. 
All the other substring have a length larger than 'bd'.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10 
1 <= |S|, |X| <= 10^5

Here, |S| denotes the length of string S and |X| denotes the length of string X.
Time Limit: 1 sec
Sample Input 1:
2
cn
c
kmmdnj
mj
Sample Output 1:
c
mdnj
Explanation 1:
For the first test case when S = 'cn' and X = 'c'. 
The substrings in S which contain all the characters present in X are: 'cn' and 'n'. Out of these, the smallest substring is 'c'.


  This problem is similar to like finding string x as a substring in string s with slight differences

((((((((((( The problem is indeed similar to finding the string x as a substring in s, but with a key difference: the order of characters in x does not matter, and x may contain repeated characters.

Key Differences:
Character Order: Unlike a simple substring search, the order of characters in x does not need to match the order in s.
Exact Frequencies: The smallest window in s must contain all the characters in x with their exact frequencies. )))))))))))))


#include <bits/stdc++.h> 
string smallestWindow(string s, string x)
{
    // Write your code here.
    if(s.empty() || x.empty()) return "";
    if(s==x) return s;
    int n=s.length();
    int m=x.length();

    unordered_map<char,int>mp;

    for(auto i:x){
        mp[i]++;
    }

    int sIndex=-1;
    int minlength=INT_MAX;
    int count=0;

    int l=0,r=0;
    while(r<n){
        if(mp[s[r]]>0){
            count++;
        }
        mp[s[r]]--;

        while(count==m){
            if(r-l+1<minlength){
                minlength=r-l+1;
                sIndex=l;
            }
            mp[s[l]]++;
            if(mp[s[l]]>0) count--;
            l++;
        }
        r++;
    }
    return sIndex==-1?"":s.substr(sIndex,minlength);
}

this is the code

2). but if we have to find out smallest window that contain the distinct char of the string x then code is 

#include <bits/stdc++.h> 
using namespace std;

string smallestWindow(string s, string x) {
    if(s.empty() || x.empty()) return "";
    if(s == x) return s;

    int n = s.length();
    int m = x.length();

    unordered_map<char, int> mp;
    unordered_set<char> distinctChars(x.begin(), x.end()); // Set of distinct characters in x

    for(char ch : distinctChars) {
        mp[ch] = 0; // Initialize the map with distinct characters in x
    }

    int required = distinctChars.size(); // Number of distinct characters to match
    int count = 0; // To track the number of distinct characters matched
    int sIndex = -1;
    int minLength = n + 1;

    int l = 0, r = 0;

    while(r < n) {
        if(mp.find(s[r]) != mp.end()) {
            if(mp[s[r]] == 0) {
                count++; // A distinct character in x is matched
            }
            mp[s[r]]++;
        }

        while(count == required) {
            if(r - l + 1 < minLength) {
                minLength = r - l + 1;
                sIndex = l;
            }

            if(mp.find(s[l]) != mp.end()) {
                mp[s[l]]--;
                if(mp[s[l]] == 0) {
                    count--; // A distinct character in x is no longer fully matched
                }
            }
            l++;
        }

        r++;
    }

    return sIndex == -1 ? "" : s.substr(sIndex, minLength);
}

int main() {
    string s = "abdd";
    string x = "bd";
    cout << "Smallest window: " << smallestWindow(s, x) << endl;
    return 0;
}
