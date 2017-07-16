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

// 트리를 이용해 상호 배제적 집합을 구현한다.
struct OptimizedDisjointSet {
	vector<int> parent, rank;

	OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	// u 가 속한 트리의 루트의 번호를 반환한다
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	// u 가 속한 트리와 v 가 속한 트리를 합친다
	void merge(int u, int v) {
		u = find(u); v = find(v);
		// 이미 둘이 같은 트리에 속한 경우
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		// 이제 항상 rank[v] 가 더 크므로 u 를 v 의 자식으로 넣는다
		if (rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	// code

	fprintf(stderr, "%.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}