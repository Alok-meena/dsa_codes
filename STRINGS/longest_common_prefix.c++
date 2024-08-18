14. Longest Common Prefix
Solved
Easy
Topics
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.






class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
    //this for loop is for traversing all the characters of the first string
    for(int i=0;i<strs[0].length();i++){// to ye loop ham pahli string ke characters ko traverse krne ke liye kr rhe hai that's why we have used indexing 
      //like 2D array because strings have their own index along with the indices of the vector
        char ch=strs[0][i];
        
        bool match=true;
        
        //this for loop is for comparing remaining strings with the characters of the first string
        for(int j=1;j<strs.size();j++){//aor yha 1 se start kiya because fist string is traversed

            //to basically yha se 1st index se ham strs vector ki strings ko traverse and compare kr rhe hai
            if(strs[j].size()<i || ch!=strs[j][i]){ // it is take care ki size arr[j] ka means string ka <i hi ho and arr[j][i] means 1st string ith index
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
    }
};
