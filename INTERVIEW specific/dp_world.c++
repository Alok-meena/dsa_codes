#include <bits/stdc++.h>
using namespace std;

int maxSalary(string s, int k, int salary, int bonus) {
    int n = s.size();
    vector<int> between, adjacent, isolated;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            bool left = (i > 0 && s[i - 1] == '1');
            bool right = (i + 1 < n && s[i + 1] == '1');

            if (left && right)
                between.push_back(i);
            else if (left || right)
                adjacent.push_back(i);
            else
                isolated.push_back(i);
        }
    }

    // Apply flips in priority
    for (int i : between) {
        if (k == 0) break;
        s[i] = '1';
        k--;
    }

    for (int i : adjacent) {
        if (k == 0) break;
        s[i] = '1';
        k--;
    }

    for (int i : isolated) {
        if (k == 0) break;
        s[i] = '1';
        k--;
    }

    // Now calculate salary
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') total += salary;
        if (i > 0 && s[i] == '1' && s[i - 1] == '1') {
            total += bonus;
        }
    }

    return total;
}

int main() {
    string s = "1010011";
    int k = 2;
    int salary = 100;
    int bonus = 50;

    cout << maxSalary(s, k, salary, bonus) << endl;
    return 0;
}
