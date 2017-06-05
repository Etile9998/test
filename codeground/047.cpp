#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

#define rer(i,a,b) for(int i = a; i >= b; --i)
#define rep(i,a,b) for(int i = a; i <= b; ++i)
#define re(i,a) rep(i,0,a-1)
#define mp make_pair
#define pb push_back
#define fi first
#define se second


int T, N, ans, x, len;
int X[101][101][2];
int d[101][101][1201]; // d[i][j][number of 3] => num of 2

void input() {
    memset(X, 0, sizeof(X));
    memset(d, -mod, sizeof(d));
    cin >> N;
    rep(i, 1, N) {
        rep(j, 1, N) {
            cin >> x;
            while (x % 2 == 0) {
                x /= 2;
                ++X[i][j][0];
            }
            while (x % 3 == 0) {
                x /= 3;
                ++X[i][j][1];
            }
        }
    }
    len = 12 * N;
}

int proc() {
    int ret = 0;
    rep(i, 0, N) {
        rep(j, 0, N) {
            d[i][j][0] = 0;
        }
    }
    rep(i, 1, N) {
        rep(j, 1, N) {
            rep(k, 0, len) {
                d[i][j][k + X[i][j][1]] = max(d[i][j][k + X[i][j][1]], max(d[i - 1][j][k], d[i][j - 1][k]) + X[i][j][0]);
            }
        }
    }
    rep(k, 1, len) {
        x = min(k, d[N][N][k]);
        if (ret < x)
            ret = x;
    }
    return ret;
}

int main() {
    // your code goes here
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    rep(tc, 1, T) {
        input();
        ans = proc();
        cout << "Case #" << tc << '\n';
        cout << ans << '\n';
    }
    return 0;
}