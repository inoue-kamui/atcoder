#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n; i++)
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    queue<int> que;
    vector<bool> visited(n + 1, false);

    que.push(1);
    visited[1] = true;
    int count = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        count++;

        for (int next_v : G[v]) {
            if (!visited[next_v]) {
                visited[next_v] = true;
                que.push(next_v);
            }
        }
    }

    cout << count << endl;
    return 0;
}
