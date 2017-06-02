#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int T, N, M, K, P, ans;
int dist[101][101];
int a, b, c, s, e;

void floyd() {
    rep(i, 1, N+1) {
        dist[i][i] = 0;
    }

    
    rep(k, 1, N+1) {
        rep(i, 1, N+1) {
            rep(j, 1, N+1) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    // your code goes here
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    rep(tc, 1, T + 1) {
        memset(dist, mod, sizeof(dist));
        cin >> N >> M >> K;
        rep(i, 1, M + 1) {
            cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }
        floyd();
        cin >> P;
        while (P--) {
            cin >> s >> e;
            if (dist[s][e] > K)++ans;
        }
        cout << "Case #" << tc << '\n' << ans << '\n';
        ans = 0;
    }
    return 0;
}