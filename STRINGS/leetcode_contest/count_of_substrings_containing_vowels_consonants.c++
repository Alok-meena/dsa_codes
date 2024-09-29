100425. Count of Substrings Containing Every Vowel and K Consonants I
User Accepted:10089
User Tried:14083
Total Accepted:10901
Total Submissions:28308
Difficulty:Medium
You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 

Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".








1) using int to count consonants


class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    int countOfSubstrings(string word, int k) {
        int n = word.length();
        int count = 0; 
        
        for (int i = 0; i < n; ++i) {
            set<char> vowelSet;   
            int consonants = 0;   
            
            for (int j = i; j < n; ++j) {
                char currentChar = word[j];
                
                if (isVowel(currentChar)) {
                    vowelSet.insert(currentChar);
                } else {
                    consonants++; 
                }
                
                if (vowelSet.size() == 5 && consonants == k) {
                    count++; 
                }
                
                if (consonants > k) {
                    break;
                }
            }
        }
        
        return count;
    }
};


2) handling duplicate consonants also dont do count consonants using set as we also have to count the duplicate ones but not the vowels okk

#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int countOfSubstrings(string word, int k) {
        int n = word.length();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            set<char> vowelSet;         // To track all vowels
            unordered_map<char, int> consonantCount;  // To track consonants
            int consonants = 0;         // Number of consonants

            for (int j = i; j < n; ++j) {
                char currentChar = word[j];

                // Check if it's a vowel or consonant
                if (isVowel(currentChar)) {
                    vowelSet.insert(currentChar);  // Add vowel to the set
                } else {
                    // If it's a consonant, track its occurrence
                    consonantCount[currentChar]++;
                    if (consonantCount[currentChar] == 1) {
                        consonants++;  // New consonant added
                    }
                }

                // Check if the substring is valid
                if (vowelSet.size() == 5 && consonants == k) {
                    count++;  // Valid substring found
                }

                // If the consonants exceed k, break out of this window
                if (consonants > k) {
                    break;
                }
            }
        }

        return count;
    }
};


Time Complexity:
The time complexity is still O(n^2), where n is the length of the string. Each starting index i results in an inner loop that checks for valid substrings up to the end of the string.
Space Complexity:
O(1) for the vowelSet since the maximum size is always 5.
O(26) for the unordered_map (or consonant count array) since there are a fixed number of possible characters.
