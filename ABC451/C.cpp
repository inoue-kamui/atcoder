#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n; i++)


bool exists[11][11][26];

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int M;
    cin >> M;
    vector<string> S(M);
    for (int i = 0; i < M; ++i) {
        cin >> S[i];
        int len = S[i].length();
        for (int pos = 0; pos < len; ++pos) {
            exists[len][pos][S[i][pos] - 'a'] = true;
        }
    }

    for (int j = 0; j < M; ++j) {
        if (S[j].length() != N) {
            cout << "No" << endl;
            continue;
        }

        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (!exists[A[i]][B[i] - 1][S[j][i] - 'a']) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}