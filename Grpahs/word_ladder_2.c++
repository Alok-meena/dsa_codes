Word Ladder II
Difficulty: HardAccuracy: 50.0%Submissions: 38K+Points: 8Average Time: 60m
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
The first part of this problem can be found here.


Example 1:

Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
der dfr dfs
der des dfs
Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".
Example 2:

Input:
startWord = "gedk", targetWord = "geek", 
wordList = {"geek", "gefk"}
Output:
"gedk" -> "geek"

Your Task:
You don't need to read or print anything, Your task is to complete the function findSequences() which takes startWord, targetWord and wordList as input parameter and returns a list of list of strings of the shortest transformation sequence from startWord to targetWord.
Note: You don't have to return -1 in case of no possible sequence. Just return the Empty List.


Expected Time Compelxity: O(N*(logN * M * 26))
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|


Constraints:
1 ≤ N ≤ 100
1 ≤ M ≤ 10





t.c can't be predicted alright

nothing bs ek change hai ki if we have to maintain the sequence then dont remove the words that get found at that level becaue they may appear in other levels
alright 

// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
        unordered_set<string>wordlist(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        
        vector<string>usedonlevel;
        usedonlevel.push_back(beginWord);
        int level=0;
        
        vector<vector<string>>ans;
        
        while(!q.empty()){
            vector<string>v=q.front();
            q.pop();
            
            if(v.size()>level){
                level++;
                for(auto it:usedonlevel){
                    wordlist.erase(it);
                }
            }
            
            string word=v.back();
            
            if(word==endWord){
                ans.push_back(v);
            }
            
            for(int i=0;i<word.length();i++){
                char original=word[i];
                
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    
                    if(wordlist.find(word)!=wordlist.end()){
                        v.push_back(word);
                        q.push(v);
                        usedonlevel.push_back(word);
                        v.pop_back();
                    }
                }
                
                
                word[i]=original;
            }
        }
        
        return ans;
    }
};
