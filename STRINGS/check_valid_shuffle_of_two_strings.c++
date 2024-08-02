Given two strings str1 and str2, and a third-string shuffle, determine if shuffle is a valid shuffle of str1 and str2, 
where a valid shuffle contains all characters from str1 and str2 occurring the same number of times, regardless of order. 
Print “YES” if valid, and “NO” otherwise.

Input: str1 = BA, str2 = XY, shuffle = XYAB 
Output: YES

Input: str1 = BA, str2 = XY, shuffle = XUMB 
Output: NO


The simplest approach that comes to mind is when we observe the given inputs carefully, 
we see that we only need to check if the frequency of each character in the string shuffle is exactly as it is in both the str1 and str2
and also the length should be of the length of str1 + length of str2. So, we can use a hashmap here.


#include <bits/stdc++.h>
using namespace std;

bool validShuffle(string str1, string str2, string shuffle) {
    // n1 = size of str1, n2 = size of str2
    int n1 = str1.size();
    int n2 = str2.size();

    // n = size of string shuffle
    int n = shuffle.size();

    // It's obvious if the number of characters in
    // shuffle is more or less than the combined
    // length of str1 and str2, then it
    // won't be a valid shuffle
    if (n != n1 + n2)
        return false;

    // We use an unordered map to keep
    // track of frequency of each character
    unordered_map<char, int> freq;

    // Count frequency of each char in str1
    for (int i = 0; i < n1; i++)
        freq[str1[i]]++;

    // Count frequency of each char in str2
    for (int i = 0; i < n2; i++)
        freq[str2[i]]++;

    // If any of the chars in shuffle are not found in the map or
    // their frequency exceeds that in str1 and str2 combined, then
    // it's not a valid shuffle
    for (int i = 0; i < n; i++) {
        if (freq.find(shuffle[i]) != freq.end() && freq[shuffle[i]] > 0)
            freq[shuffle[i]]--;
        else
            return false;
    }

    // Check whether all the elements' frequency in the hashmap becomes 0
    for (auto it : freq) {
        if (it.second != 0) {
            return false;
        }
    }
    return true;
}

// Driver code
int main() {
    string str1 = "BA", str2 = "XY", shuffle = "ABYX";

    (validShuffle(str1, str2, shuffle) == true)
        ? printf("YES")
        : printf("NO");
    cout << endl;

    return 0;
}


t.c:-O(n) and s.c:-O(n)
