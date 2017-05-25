#ifdef _CONSOLE
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)

int T, N, ans;
int ret, r, c, dir;
const int dy[] = { 0,-1,1,0 };
const int dx[] = { 1,0,0,-1 };
char a[1000][1001];
bool b[1000][1000];
int proc() {
    memset(b, 0, sizeof(b));
    dir = ret = r = c = 0;
    cin >> N;
    rep(i, 0, N) {
        cin >> a[i];
    }
    while (0 <= r && r < N && 0 <= c && c < N) {
        if (a[r][c] == '0');
        else {
            if (!b[r][c]) {
                ++ret;
                b[r][c] = 1;
            }
            if (a[r][c] == '1')
                dir ^= 1;
            else
                dir ^= 2;
        }
        c += dx[dir]; r += dy[dir];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // freopen("a.in", "r", stdin);
    // your code goes here
    cin >> T;
    rep(tc, 1, T + 1) {
        ans = proc();
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}