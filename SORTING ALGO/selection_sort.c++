#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 4, 3, 2, 1};
    int n = v.size();

    for (int i = 0; i < n - 1; i++) { // Iterate over each position
        int minIndex = i;

        // Find the smallest element in the unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the smallest element with the first unsorted element
        swap(v[i], v[minIndex]);
    }

    // Print the sorted array
    for (auto i : v) {
        cout << i << " ";
    }

    return 0;
}
