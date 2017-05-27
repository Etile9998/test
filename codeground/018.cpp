#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)

int t, m, n, k, ans;
int a[101][101];
bool c[101][101][11];
int d[101][101][11];

int proc(int rem, int i, int j) {
    if (c[i][j][rem])return d[i][j][rem]; // prev node
    if (i == n && j == m)return rem ? mod : 0; // leaf node
    c[i][j][rem] = 1; // check node
    int &ret = d[i][j][rem];
    ret = mod;
    if (i < n) {
        int diff = abs(abs(a[i][j]) - abs(a[i + 1][j]));
        if (a[i + 1][j] < 0 && rem > 0) // water on a[i + 1][j] && need water
            ret = min(ret, proc(rem - 1, i + 1, j) + diff);
        else // dnt need water || no water on a[i][j]
            ret = min(ret, proc(rem, i + 1, j) + diff);
    }

    if (j < m) {
        int diff = abs(abs(a[i][j]) - abs(a[i][j + 1]));
        if (a[i][j + 1] < 0 && rem > 0) // water on a[i][j + 1] && need water
            ret = min(ret, proc(rem - 1, i, j + 1) + diff);
        else // dnt need water || no water on a[i][j]
            ret = min(ret, proc(rem, i, j + 1) + diff);
    }
    return ret;
}

int main() {
    // your code goes here
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    rep(tc, 1, t + 1) {
        memset(d, 0, sizeof(d));
        memset(c, 0, sizeof(c));
        cin >> m >> n >> k;
        rep(i, 0, n + 1) {
            rep(j, 0, m + 1) {
                cin >> a[i][j];
            }
        }
        ans = proc(k, 0, 0);
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}