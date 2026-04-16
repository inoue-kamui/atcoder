vector<int> z_algorithm(const string& S) {
    int n = S.size();
    vector<int> Z(n);
    Z[0] = n;

    int i = 1, j = 0;
    while (i < n) {
        while (i + j < n && S[j] == S[i + j]) ++j;
        Z[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < n && k + Z[k] < j) {
            Z[i + k] = Z[k];
            ++k;
        }
        i += k;
        j -= k;
    }
    return Z;
}
// Z[i] は S と S[i:] の最長共通接頭辞の長さ
// Z[0] = n であることに注意
// O(N)
// 例: S = "ababab", Z = [6, 0, 4, 0, 2, 0]
// 例: S = "aaaaa", Z = [5, 4, 3, 2, 1]
// 例: S = "abcde", Z = [5, 0, 0, 0, 0]