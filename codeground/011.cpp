#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)

int T, N, K, ans;
int a[1000001];

int proc() {
    int ret = 1;
    int rem = K;
    rep(i, 1, N + 1) {
        if (a[i - 1] + K < a[i])return -1;
        if (a[i] - a[i - 1] > rem) {
            rem = K;
            ++ret;
        }
        rem -= a[i] - a[i - 1];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // freopen("a.in", "r", stdin);
    // your code goes here
    cin >> T;
    rep(tc, 1, T + 1) {
        cin >> N;
        rep(i, 1, N + 1) {
            cin >> a[i];
        }
        cin >> K;
        ans = proc();
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}