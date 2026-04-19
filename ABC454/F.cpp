#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)

ll modm(ll nbr, ll m)
{
    ll ans = nbr % m;
    if(ans < 0) ans += m;
    return ans;
}

int main(){
    int t;
    cin >> t;
    rep(_, t){
        int n;
        ll m;
        cin >> n >> m;
        vector<ll> a(n + 1);
        rep1(i, n) cin >> a[i];

        int k = n / 2;
        vector<ll> d(k + 2, 0);
        rep1(i, k) d[i] = modm(a[i] - a[n + 1 - i], m);

        vector<ll> dd(k + 2, 0);
        ll sum = 0;
        rep1(i, k + 1){
            dd[i] = modm(d[i] - d[i - 1], m);
            sum += dd[i];
        }

        ll c = sum / m;
        vector<ll> sorted_dd;
        rep1(i, k + 1) sorted_dd.push_back(dd[i]);
        sort(sorted_dd.begin(), sorted_dd.end());
        
        ll ans = 0;
        rep(i, k + 1 - c) ans += sorted_dd[i];
        cout << ans << "\n";
    }
}