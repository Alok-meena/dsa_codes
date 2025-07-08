953. Verifying an Alien Dictionary
Solved
Easy
Topics
premium lock icon
Companies
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.









class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>v(26,0);
        for(int i=0;i<26;i++){
            v[order[i]-'a']=i;
        }

        int n=words.size();

        for(int i=0;i<n-1;i++){
            string a=words[i];
            string b=words[i+1];

            int len=min(a.length(),b.length());
            bool found=false;

            for(int j=0;j<len;j++){
                if(v[a[j]-'a']<v[b[j]-'a']){
                    found=true;
                    break;
                }
                else if(v[a[j]-'a']>v[b[j]-'a']){
                    return false;
                }
            }

            if(!found and a.length()>b.length()) return false;
        }

        return true;
    }
};
