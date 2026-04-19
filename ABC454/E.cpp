#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n; i++)
int main()
{
    cin >> t;
    rep(_, t)
    {
        int n, a, b;
        cin >> n >> a >> b;
        a--;
        b--;
        if (n % 2 == 0 && (a + b) % 2 == 1)
        {
            cout << "Yes\n";
            vector<pair<int, int>> p;
            int r = a / 2 * 2;
            rep(i, r) rep(j, n) p.push_back({i, i % 2 == 0 ? j : n - 1 - j});
            int c = r;
            rep(j, n)
            {
                p.push_back({c, j});
                if (j != b)
                {
                    c = (c == r) ? r + 1 : r;
                    p.push_back({c, j});
                }
            }
            rep(k, n - r - 2) rep(j, n) p.push_back({r + 2 + k, k % 2 == 0 ? n - 1 - j : j});
            int len = p.size() - 1;
            rep(i, len)
            {
                if (p[i + 1].first > p[i].first)
                    cout << 'D';
                else if (p[i + 1].first < p[i].first)
                    cout << 'U';
                else if (p[i + 1].second > p[i].second)
                    cout << 'R';
                else
                    cout << 'L';
            }
            cout << "\n";
        }
        else
            cout << "No\n";
    }
}
