🧩 Problem Statement:
You are given a tree with n nodes (numbered from 1 to n). Each node has a number of stones assigned to it, represented by an array stones of size n, where stones[i] denotes the number of stones at node i+1.

You are allowed to only add stones (you cannot remove stones) to any node, as many times as you want.

Your goal is to modify the tree such that for every edge (u, v) in the tree:

Copy
Edit
|stones[u] - stones[v]| <= 1
In other words, the difference in the number of stones between any pair of directly connected nodes must be at most 1.

You need to find the minimum total number of stones to be added to achieve this goal.

🔢 Input Format:
The first line contains an integer n (1 ≤ n ≤ 2000) — the number of nodes in the tree.

The second line contains n space-separated integers stones[1..n] — the number of stones at each node.

The next n - 1 lines each contain two integers u and v — representing an edge between node u and node v.

📤 Output Format:
Print a single integer — the minimum number of stones to be added to make the tree balanced as per the given condition.







#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
vector<int> adj[MAXN];
int stones[MAXN];
int total_added = 0;

void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;

        dfs(v, u);  // Fix subtree rooted at v first

        int diff = abs(stones[u] - stones[v]);
        if (diff > 1) {
            int add = diff - 1;
            if (stones[u] < stones[v]) {
                stones[u] += add;
            } else {
                stones[v] += add;
            }
            total_added += add;
        }
    }
}

int main() {
    int n;
    cin >> n;

    // Input stones at each node (1-based indexing)
    for (int i = 1; i <= n; ++i) {
        cin >> stones[i];
    }

    // Input edges
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);  // Root the tree at node 1
    cout << total_added << endl;

    return 0;
}
