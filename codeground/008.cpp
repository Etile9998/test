#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)

int T, N, h[100002], ans;
int d[100002];

void proc() {
    ans = 0; d[N + 1] = 0;
    for (int i = N; i > 0; --i) {
        d[i] = min(h[i], d[i + 1] + 1);
    }
    rep(i, 1, N + 1) {
        d[i] = min(d[i],min(h[i], d[i - 1] + 1));
    }
    rep(i, 1, N + 1) {
        if (ans < d[i])
            ans = d[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("a.in", "r", stdin);
    // your code goes here
    cin >> T;
    rep(tc, 1, T + 1) {
        cin >> N;
        rep(i, 1, N + 1) {
            cin >> h[i];
        }
        proc();
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}