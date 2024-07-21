






1: this one gives tle

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to check if a binary representation is a palindrome
bool isBinaryPalindrome(int num) {
    string bin = "";
    while (num > 0) {
        bin += (num % 2) + '0';
        num /= 2;
    }
    string rev_bin = bin;
    reverse(rev_bin.begin(), rev_bin.end());
    return bin == rev_bin;
}

// Function to find the minimum number of operations required
int minOperationsToPalindrome(int n) {
    int dist_up = 0, dist_down = 0;
    int temp_n = n;
    
    // Increment from n until we find a binary palindrome
    while (!isBinaryPalindrome(temp_n)) {
        temp_n++;
        dist_up++;
    }
    
    temp_n = n;
    
    // Decrement from n until we find a binary palindrome
    while (!isBinaryPalindrome(temp_n) && temp_n > 0) {
        temp_n--;
        dist_down++;
    }
    
    // Return the minimum of the two distances
    if (temp_n == 0) return dist_up;  // If n was decremented to 0, ignore the down path
    return min(dist_up, dist_down);
}

int main() {
    int t;
    cin >> t;
    vector<int> results;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        results.push_back(minOperationsToPalindrome(n));
    }
    
    for (int i = 0; i < t; i++) {
        cout << results[i] << endl;
    }
    
    return 0;
}


2: this is correct


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// Helper function to convert an integer to its binary string representation
string toBinary(int num) {
    string bin = "";
    while (num > 0) {
        bin = (num % 2 == 0 ? "0" : "1") + bin;
        num /= 2;
    }
    return bin;
}

// Helper function to convert a binary string to an integer
int toDecimal(const string &bin) {
    int num = 0;
    for (char c : bin) {
        num = num * 2 + (c - '0');
    }
    return num;
}

// Helper function to check if a string is a palindrome
bool isPalindrome(const string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

// Function to find the nearest palindromic binary
int nearestPalindrome(int n) {
    string bin = toBinary(n);
    int len = bin.size();

    // Generate the next palindrome by mirroring the first half
    string palin = bin.substr(0, (len + 1) / 2);
    string next_palin = palin + string(palin.rbegin() + (len % 2), palin.rend());
    
    // If next_palin is less than n, increment the first half and try again
    if (toDecimal(next_palin) < n) {
        int first_half = toDecimal(palin);
        first_half++;
        palin = toBinary(first_half);
        next_palin = palin + string(palin.rbegin() + (len % 2), palin.rend());
    }

    return toDecimal(next_palin);
}

// Function to find the previous palindromic binary
int previousPalindrome(int n) {
    string bin = toBinary(n);
    int len = bin.size();

    // Generate the previous palindrome by mirroring the first half
    string palin = bin.substr(0, (len + 1) / 2);
    string prev_palin = palin + string(palin.rbegin() + (len % 2), palin.rend());

    // If prev_palin is greater than n, decrement the first half and try again
    if (toDecimal(prev_palin) > n) {
        int first_half = toDecimal(palin);
        first_half--;
        palin = toBinary(first_half);
        prev_palin = palin + string(palin.rbegin() + (len % 2), palin.rend());
    }

    return toDecimal(prev_palin);
}

// Function to find the minimum number of operations required
int minOperationsToPalindrome(int n) {
    int next_palin = nearestPalindrome(n);
    int prev_palin = previousPalindrome(n);

    return min(abs(n - next_palin), abs(n - prev_palin));
}

int main() {
    int t;
    cin >> t;
    vector<int> results;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        results.push_back(minOperationsToPalindrome(n));
    }

    for (int i = 0; i < t; i++) {
        cout << results[i] << endl;
    }

    return 0;
}

