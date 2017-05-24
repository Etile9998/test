#ifdef _CONSOLE
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)

int T, N, M;
ll f[2000003];

void prec() {
    f[0] = 1;
    rep(i, 1, 2000003) {
        f[i] = i * f[i - 1] % mod;
    }
}

ll pow(ll a, ll n) {
    if (n == 0)
        return 1;
    ll ret = pow(a*a%mod, n / 2);
    if (n % 2)
        return ret * a % mod;
    else
        return ret % mod;
}

ll proc() {
    ll ret = f[N + M + 2];
    ret = (ret * pow(f[N + 1] * f[M + 1] % mod, mod - 2)) % mod - 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // your code goes here
    prec();
    cin >> T;
    rep(tc, 1, T + 1) {
        cin >> N >> M;
        cout << "Case #" << tc << '\n' << proc() << '\n';
    }

    return 0;
}