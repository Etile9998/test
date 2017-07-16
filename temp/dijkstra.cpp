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
int V,E,K;

/*
x : here
y : there
z : heredist
*/
vector<pair<int, int> > edge[100001];
vector<int> dijkstra(int start) {
	vector<int> dist(V + 1, -1);
	priority_queue<pair<int, int> > pq;
	dist[start] = 0;
	pq.push({ 0, start });
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
				pq.push({ -dist[y], y });
			}
		}
	}
	return dist;
}

// test 
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> V >> E >> K;
	REP(i, E) {
		int u, v, cost;
		cin >> u >> v >> cost;
		edge[u].pb({ v,cost });
		//edge[v].pb({ u,cost });
	}
	vector<int> ans = dijkstra(K);
	FOR(i, 1, V + 1) {
		if (ans[i] == -1)
			cout << "INF\n";
		else
			cout << ans[i] << '\n';
	}
	fprintf(stderr, "%.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}