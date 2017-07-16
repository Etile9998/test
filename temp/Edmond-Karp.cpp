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

/////////////////////////////////////////////////
struct network_edge {
	int to, capacity, flow, residual_idx;
	network_edge() {}
	network_edge(int t, int c, int f, int r) {
		to = t;
		capacity = c;
		flow = f;
		residual_idx = r;
	}
};

int src, sink;
bool chk[101];
vector<network_edge> adj[101];

int find_path(int cur, int addible_flow) {
	if (cur == sink) return addible_flow;
	chk[cur] = true;

	for (int i = 0; i < adj[cur].size(); i++) {
		network_edge& edge = adj[cur][i];
		if (chk[edge.to] || edge.capacity - edge.flow == 0) continue;

		int added = find_path(edge.to, min(addible_flow, edge.capacity - edge.flow));
		if (added) {
			edge.flow += added;
			adj[edge.to][edge.residual_idx].flow -= added;
			return added;
		}
	}

	return 0;
}

/////////////////////////////////////////////////
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	// code
	int v, e;
	scanf("%d %d", &v, &e);
	scanf("%d %d", &src, &sink);

	for (int i = 0; i < e; i++) {
		int from, to, capacity;
		scanf("%d %d %d", &from, &to, &capacity);
		adj[from].push_back(network_edge(to, capacity, 0, adj[to].size()));
		adj[to].push_back(network_edge(from, 0, 0, adj[from].size() - 1));
	}

	int ans = 0, added_flow;
	while (added_flow = find_path(src, 101)) {
		ans += added_flow;
		for (int i = 1; i <= v; i++) {
			chk[i] = 0;
		}
	}

	printf("%d\n", ans);
	fprintf(stderr, "%.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}