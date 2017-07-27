#include <bits/stdc++.h>
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

int N,ans;
int d[1001][10];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// code
	REP(i, 10)d[1][i] = 1;
	cin >> N;
	FOR(i, 2, N + 1) {
		FOR(j, 0,10) {
			FOR(k, 0, j + 1) {
				d[i][j] += d[i - 1][k];
			}
			d[i][j] %= 10007;
		}
	}
	REP(i, 10) {
		ans += d[N][i];
	}
	cout << (ans % 10007) << '\n';
	return 0;
}