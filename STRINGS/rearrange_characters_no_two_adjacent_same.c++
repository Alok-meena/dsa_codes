Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Example 1:

Input : str = "geeksforgeeks"
Output: 1
Explanation: All the repeated characters of the
given string can be rearranged so that no 
adjacent characters in the string is equal.
Any correct rearrangement will show a output
of 1.
Example 2:

Input : str = "bbbbb"
Output: 0
Explanation: Repeated characters in the string
cannot be rearranged such that there should not
be any adjacent repeated character.






1). brute force 

// Online C++ compiler to run C++ program online


CONCEPT:--- we will generate all of the possible permutations and then check each and every for the condition if staisfied then return o/w return empty string
if not possible like bbb no possible okk


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void permutation(string nums, int index, vector<string>& ans) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);
            permutation(nums, index + 1, ans);
            swap(nums[index], nums[j]);
        }
    }

    bool check(string &v) {
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] == v[i + 1]) return false;
        }
        return true;
    }

    string rearrangeString(string str) {
        vector<string> ans;
        int index = 0;
        permutation(str, index, ans);

        for (auto i : ans) {
            if (check(i)) return i;
        }
        
        // If no valid permutation is found, return an empty string
        return "";
    }

int main() {
    // Write C++ code here
    string s;
    cout<<"enter the string:";
    cin>>s;
    
    cout<<rearrangeString(s);

    return 0;
}

t.c:- O(n*n!) and s.c:-O(n*n!) as there are n! permutations and each string is of length n


2) optimized code



class Solution {
public:
    string reorganizeString(string s) {
         int n=s.length();
        vector<int>v(26,0);
        
        for(auto i:s){
            v[i-'a']++;
        }
        
        int maxFreq=0;
        int letter=0;
        for(int i=0;i<26;i++){
            if(maxFreq<v[i]){
                maxFreq=v[i];
                letter=i;//here we are just storing the index
            }
        }

        //n+1/2 is done for odd length and for even length like if n=6 then 6+1/2 =3.5=3 okk also included if true then return empty string
        if(maxFreq>(n+1)/2) return "";//check once
        
        // vector<char> s(n);
        string str(n,' ');
        int index=0;

        //we can think that why can't we skip this while loop and do our work from the for loop only but it is not the case 
        //think of a case when the place of majority element is taken by other then we forcefully have to put the the elements (majority) adjacent 
        //to avoid this case we have to first put all of the majority elements in the string first then for the remaining
        while(v[letter] >0){ //we didn't update the letter ot i+'a' as here we want it to be used as an index
            str[index]=letter+'a';
            index+=2;
            v[letter]--;
        }
        
        
        for(int i=0;i<26;i++){
            while(v[i]>0){
                //this condition is checked first as think for the 2nd case when maxcount==len/2 then we have to update the index to 1 it will handle that also
                if(index>=n) index=1;
                str[index]=i+'a';//directly do this at the index dont do += or push_back okkk
                index+=2;
                v[i]--;
            }
        }
        
        return str;
    }
};

t.c:O(n) as in the last outer loop runs only for 26 times which can be considered as constant okk and O(n) is due to traversal and etc 
and s.c:-O(n)



we can also use unordered_map here

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string rearrangeString(string str) {
        int n = str.length();
        unordered_map<char, int> m;

        // Count the frequency of each character
        for (char c : str) {
            m[c]++;
        }

        // Find the character with the maximum frequency
        int maxFreq = 0;
        char letter;
        for (auto &i : m) {
            if (maxFreq < i.second) {
                maxFreq = i.second;
                letter = i.first;
            }
        }

        // If the maximum frequency is greater than half the size of the string (rounded up), return an empty string
        if (maxFreq > (n + 1) / 2) return ""; // Impossible to rearrange

        // Create a result array of the same length as the input string
        vector<char> s(n);

        // Place the most frequent character at even indices
        int index = 0;
        while (m[letter] > 0) {
            s[index] = letter;
            index += 2;
            m[letter]--;
        }

        // Place the remaining characters in the available positions
        for (auto &i : m) {
            while (i.second > 0) {
                // If we have reached the end of the array, start filling from index 1 (odd positions)
                if (index >= n) index = 1;
                s[index] = i.first;
                index += 2;
                i.second--;
            }
        }

        // Convert the result vector to a string and return it
        return string(s.begin(), s.end());
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    string result = sol.rearrangeString(s);
    if (result.empty()) {
        cout << "Not possible to rearrange the string." << endl;
    } else {
        cout << "Rearranged string: " << result << endl;
    }
    return 0;
}
