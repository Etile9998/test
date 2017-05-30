#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int t, n, m, ans[1001], len;
int u, v, weight; // u >- weight -> v
vector<pii > a[1001]; // a[from] (to, cost)

void Dijkstra(int start) {
    vector<int> dist(n + 1, -1);
    priority_queue<pii > pq;
    dist[start] = 0;
    pq.push(mp(0, start));
    while (!pq.empty()) {
        weight = -pq.top().fi;
        u = pq.top().se;
        pq.pop();
        int x = u;
        if (weight > dist[u])continue;
        len = a[u].size();
        rep(i, 0, len) {
            v = a[u][i].fi;
            if (dist[v] > a[u][i].se + weight || dist[v] == -1) {
                dist[v] = a[u][i].se + weight;
                pq.push(mp(-dist[v], v));
            }
        }
    }

    // 이 부분은 유심히 보자
    rep(i, 1, n + 1) {
        if (start == i)continue;
        len = a[i].size();
        rep(j, 0, len) {
            pii e = a[i][j];
            if (dist[e.fi] == dist[i] + e.se) {
                ans[i] = 0;
            }
        }
    }
}

int main() {
    // your code goes here
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> t;
    rep(tc, 1, t + 1) {
        cin >> n >> m;
        rep(i, 0, n + 1) { // init
            a[i].clear();
            ans[i] = 1;
        }
        rep(i, 0, m) { // input
            cin >> u >> v >> weight;
            a[u].pb(mp(v, weight));
            a[v].pb(mp(u, weight));
        }
        rep(i, 1, n + 1) { // proc
            Dijkstra(i);
        }
        cout << "Case #" << tc << '\n';
        int cnt = 0;
        rep(i, 1, n + 1) {
            if (ans[i])++cnt;
        }

        cout << cnt;
        rep(i, 1, n + 1) {
            if (ans[i]) {
                cout << ' ' << i;
            }
        }
        cout << '\n';
    }
    return 0;
}