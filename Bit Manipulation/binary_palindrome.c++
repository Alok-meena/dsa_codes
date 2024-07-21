








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
