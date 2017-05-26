#ifdef _CONSOLE
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define fi first
#define se second

int T, N, M, K;
pair<int, int> a[2000];
ll ans;
ll f[200003];
ll fm[100003];

ll pow(ll a, ll n) {
    if (n == 0)return 1;
    ll ret = pow(a*a %mod, n / 2);
    return (n % 2 ? a*ret : ret) % mod;
}

void prec() {
    f[0] = fm[0] = 1;
    rep(i, 1, 200003) {
        f[i] = i * f[i - 1] % mod;
    }
    rep(i, 1, 100003) {
        fm[i] = pow(f[i], mod - 2);
    }
}

ll bino(int n, int r) { // (n+r)!/(n!r!) % P == (n+r)! * (n!r!)^(P-2) % P
    // return f[n + r] * pow(f[n] * f[r] % mod, mod - 2) % mod;
    return  f[n + r] * fm[n] % mod * fm[r] % mod;
}

ll proc() {
    ll ret = bino(N - 1, M - 1);
    rep(i, 0, K) {
        if (a[i].fi < 1 || a[i].fi > N || a[i].se < 1 || a[i].se > M)continue;
        rep(j, 0, i) {
            if (a[j].fi < 1 || a[j].fi > N || a[j].se < 1 || a[j].se > M)continue;
            if (a[i].fi <= a[j].fi && a[i].se <= a[j].se) {
                ret += bino(a[i].fi - 1, a[i].se - 1) *bino(a[j].fi - a[i].fi, a[j].se - a[i].se)
                    % mod *bino(N - a[j].fi, M - a[j].se) % mod;
            }
            else if (a[i].fi >= a[j].fi && a[i].se >= a[j].se) {
                ret += bino(a[j].fi - 1, a[j].se - 1) *bino(a[i].fi - a[j].fi, a[i].se - a[j].se)
                    % mod *bino(N - a[i].fi, M - a[i].se) % mod;
            }
            ret %= mod;
        }
        ret = (ret + mod ) - bino(a[i].fi - 1, a[i].se - 1)*bino(N - a[i].fi, M - a[i].se) % mod;
        ret %= mod;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("a.in", "r", stdin);
    // your code goes here
    prec();
    cin >> T;
    rep(tc, 1, T + 1) {
        cin >> N >> M >> K;
        rep(i, 0, K) {
            cin >> a[i].fi >> a[i].se;
        }
        ans = proc();
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}