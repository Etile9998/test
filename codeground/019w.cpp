#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)

int t, n, ans;
pair<int, int> p[100000];

int proc() {

}

int main() {
    // your code goes here
    freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    rep(tc, 1, t + 1) {
        cin >> n;
        rep(i, 0, n) {
            cin >> p[i].first >> p[i].second;
        }
        sort(p, p + n, greater<int>());
        ans = proc();
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}