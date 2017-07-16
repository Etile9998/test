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

// Ʈ���� �̿��� ��ȣ ������ ������ �����Ѵ�.
struct OptimizedDisjointSet {
	vector<int> parent, rank;

	OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	// u �� ���� Ʈ���� ��Ʈ�� ��ȣ�� ��ȯ�Ѵ�
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	// u �� ���� Ʈ���� v �� ���� Ʈ���� ��ģ��
	void merge(int u, int v) {
		u = find(u); v = find(v);
		// �̹� ���� ���� Ʈ���� ���� ���
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		// ���� �׻� rank[v] �� �� ũ�Ƿ� u �� v �� �ڽ����� �ִ´�
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