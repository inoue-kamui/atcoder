/* BIT: RAQ対応BIT
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(l,r,x): [l,r) に x を加算する
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    計算量は全て O(logn)
*/
template <typename T>
struct BIT {
    int n;             // 要素数
    vector<T> bit[2];  // データの格納先
    BIT(int n_) { init(n_); }
    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }

    void add_sub(int p, int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(int l, int r, T x) {  // [l,r) に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }

    T sum_sub(int p, int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }

    // [l,r) の区間和を取得
    T query(int l, int r) { return sum(r - 1) - sum(l - 1); }
    int lower_bound(T w) { // a_1 + a_2 + ... + a_x >= w となるような最小の x を求める(ただし a_i >= 0)
        if (w <= 0) {
            return 0;
        } else {
            int x = 0, r = 1;
            while (r < n) r = r << 1;
            for (int len = r; len > 0; len = len >> 1) { // 長さlenは1段下るごとに半分に
                if (x + len < n && bit[x + len] < w) { // 採用するとき
                    w -= bit[x + len];
                    x += len;
                }
            }
            return x + 1;
        }
    }
    

};


/* BIT2D:
    初期値は全て 0
    ・add(h,w,x): (h,w) に x を加算する
    ・sum(h,w): 1≦i≦h かつ 1≦j≦w の範囲の合計値を求める
    ・query(h1,w1,h2,w2): h1≦i<h2 かつ w1≦j<w2 の範囲の合計値を求める(1-indexed)
    計算量は全て O(logW * logH)
*/
template <typename T>
struct BIT2D {
    int H, W;
    vector<vector<T>> bit;  // データの格納先
    BIT2D(int H_, int W_) { init(H_, W_); }
    void init(int H_, int W_) {
        H = H_ + 1;
        W = W_ + 1;
        bit.assign(H, vector<T>(W, 0));
    }
    void add(int h, int w, T x) {
        for (int i = h; i < H; i += (i & -i)) {
            for (int j = w; j < W; j += (j & -j)) {
                bit[i][j] += x;
            }
        }
    }
    // 1≦i≦h かつ 1≦j≦w
    T sum(int h, int w) {
        T s(0);
        for (int i = h; i > 0; i -= (i & -i)) {
            for (int j = w; j > 0; j -= (j & -j)) {
                s += bit[i][j];
            }
        }
        return s;
    }
    // h1≦i<h2 かつ w1≦j<w2
    T query(int h1, int w1, int h2, int w2) {
        return sum(h2 - 1, w2 - 1) - sum(h2 - 1, w1 - 1) - sum(h1 - 1, w2 - 1) + sum(h1 - 1, w1 - 1);
    }
};