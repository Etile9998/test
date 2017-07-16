#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()

/*
V : number of Vertex
E : number of Edge
K : number of Key
*/
int V, E, K;
int T;
/*
x : here
y : there
z : heredist
*/

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	FOR(tc, 1, T + 1) {
		cin >> V >> E >> K;
		vector<vector<pair<int, int> > > edge;
		edge.resize(V + 1);
		int a[100000];
		int u, v, cost;
		REP(i, E) {
			cin >> u >> v >> cost;
			edge[u].pb({ v,cost });
			edge[v].pb({ u,cost });
		}
		REP(i, K) {
			cin >> a[i];
		}
		//int start = a[0];
		vector<int> dist(V + 1, -1);
		vector<int> from(V + 1, 0);
		FOR(i, 1, V + 1)from[i] = i;
		priority_queue<pair<int, int> > pq;
		REP(i, K) {
			dist[a[i]] = 0;
			pq.push({ 0,a[i] });
		}
		while (!pq.empty()) {
			int z = -pq.top().first;
			int x = pq.top().second;
			pq.pop();
			if (z > dist[x])continue;
			int len = edge[x].sz;
			REP(i, len) {
				int y = edge[x][i].first;
				if (dist[y] == -1 || dist[y] > z + edge[x][i].second) {
					dist[y] = z + edge[x][i].second;
					from[y] = from[x];
					pq.push({ -dist[y], y });
				}
				else if (dist[y] == z + edge[x][i].second && from[y] > from[x]) {
					from[y] = from[x];
					pq.push({ -dist[y], y });
				}
			}
		}
		ll ans = 0;
		ll ans2 = 0;
		FOR(i, 1, V + 1) {
			ans += dist[i];
			ans2 += from[i];
		}
		cout << "Case #" << tc << '\n';
		cout << ans << '\n' << ans2 << '\n';
	}
	//fprintf(stderr, "%.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}