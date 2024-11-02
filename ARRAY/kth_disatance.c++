Given an unsorted array arr and a number k which is smaller than the size of the array. Return true if the array contains any duplicate within k distance throughout the array else false.

Examples:

Input: arr[] = [1, 2, 3, 4, 1, 2, 3, 4] and k = 3
Output: false
Explanation: All duplicates are more than k distance away.
Input: arr[] = [1, 2, 3, 1, 4, 5] and k = 3
Output: true
Explanation: 1 is repeated at distance 3.
Input: arr[] = [6, 8, 4, 1, 8, 5, 7] and k = 3
Output: true
Explanation: 8 is repeated at distance 3.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ k < arr.size()
1 ≤ arr[i] ≤ 105







#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_set<int> window;

        for (int i = 0; i < arr.size(); ++i) {
            // If current element is already in the set, we found a duplicate within k distance
            if (window.count(arr[i]) > 0) {
                return true;
            }

            // Add the current element to the set
            window.insert(arr[i]);

            // If the size of the set exceeds k, remove the element that's k distance behind

            //jaise hi apna set ki size 3 hui to ham last element ko htate jao bs
            if (i >= k) {
                window.erase(arr[i - k]);
            }
        }

        return false;
    }
};



this is also correct

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            // Check up to k elements ahead for duplicates
            for (int j = i + 1; j <= i + k && j < n; j++) {
                if (arr[i] == arr[j]) {
                    return true;
                }
            }
        }

        return false;

