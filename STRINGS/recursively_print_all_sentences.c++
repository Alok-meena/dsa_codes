Recursively print all sentences that can be formed from list of word lists
Difficulty: EasyAccuracy: 74.26%Submissions: 2K+Points: 2
Given a list of word lists of size  M * N. The task is to return all sentences possible taking one word from a list at a time via recursion. 

Example 1:
Input:

L = {{"you", "we"},
     {"have", "are"},
Output: 
{{you have}
{you are}
{we have}
{we are}}
Explanation:
Consider every every word from the list and form
sentences with every other words, taking one word from a list .

Note: You need to maintain the order of the sentences.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function sentences() which takes a matrix of strings as input and returns a matrix of string containing all possible sentences.

Expected Time Complexity: O(MN)
Expected Auxiliary Space: O(MN)








class Solution {
public:
    void generateSentences(vector<vector<string>>& list, int idx, string current, vector<string>& ans) {
        if (idx == list.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < list[idx].size(); i++) {
            string sentence = current.empty() ? list[idx][i] : current + " " + list[idx][i];
            generateSentences(list, idx + 1, sentence, ans);
        }
    }

    vector<vector<string>> sentences(vector<vector<string>>& list) {
        vector<string> temp;
        vector<vector<string>> ans;
        generateSentences(list, 0, "", temp);
        for (string& sentence : temp) {
            ans.push_back({sentence});
        }
        return ans;
    }
};
