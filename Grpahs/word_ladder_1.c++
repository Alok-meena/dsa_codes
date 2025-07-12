
Code
Test Result
Test Result
Testcase
126. Word Ladder II
Hard
Topics
premium lock icon
Companies
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 105.




bfs ques as we have to check all possible transformations alright 

t.c:-O(n*wordlen*26) s.c:-O(n) alright




class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string>wordlist(wordList.begin(),wordList.end());
        
        queue<pair<string,int>>q; // string , steps
        q.push({startWord,1});

        //edge case should be included alright
        if(wordlist.find(endWord)==wordlist.end()) return 0;

        
        while(!q.empty()){
            string s=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(s==targetWord) return steps;
            
            for(int i=0;i<s.length();i++){
                char originalchar=s[i];
                
                for(char ch='a';ch<='z';ch++){
                    s[i]=ch;
                    
                    if(wordlist.count(s)){
                        q.push({s,steps+1});
                        wordlist.erase(s);
                    }
                }
                
                s[i]=originalchar; //resetting so that can change it's all char's alright
            }
        }
        
        return 0;
    }
};


2nd time 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int,string>>q;
        q.push({1,beginWord});

        unordered_set<string>wordlist(wordList.begin(),wordList.end());
        if(wordlist.find(endWord)==wordlist.end()) return 0;

        while(!q.empty()){
            int steps=q.front().first;
            string word=q.front().second;
            q.pop();

            if(word==endWord) return steps;

            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(wordlist.find(word)!=wordlist.end()){
                        q.push({steps+1,word});
                        wordlist.erase(word);
                    }
                }
                word[i]=original;
            }
        }

        return 0;
    }
};

just dont break after erasing the word as we can find other quick transformations also alright
