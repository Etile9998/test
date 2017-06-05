#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int T, K, L, N, M, ans;
int u, v;
int a[101]; // 차수
int m[101][101];

int proc() {
    int ret = 0;
    rep(i, 0, M) {
        cin >> u >> v;
        ++a[u]; ++a[v];
        m[u][v] = m[v][u] = 1;
    }
    int V = N;
    rep(i, 1, N + 1) {
        if (a[i] == -1)continue; // 이미 폐기
        if (a[i] < K || V - L <= a[i]) { // 조건에 부합하면 폐기
            --V;
            a[i] = -1;
            ret += i;
            rep(j, 1, N + 1) {
                if (m[i][j]) { // i와 j가 이어져 있다면
                    --a[j];
                    m[i][j] = m[j][i] = 0;
                }
            }
            i = 0;
        }
    }

    return ret;
}

int main() {
    // your code goes here
    freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    rep(tc, 1, T + 1) {
        memset(a, 0, sizeof(a));
        memset(m, 0, sizeof(m));
        cin >> K >> L >> N >> M;
        ans = proc();
        cout << "Case #" << tc << '\n';
        cout << ans << '\n';

    }
    return 0;
}