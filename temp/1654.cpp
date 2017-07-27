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

int N, K;
int a[1000000];
int mx;
ll proc() {
	ll l = 0, r = mx, mid;
	ll sum, ret = 0;
	while (l <= r) {
		sum = 0;
		mid = (l + r) / 2;
		REP(i, N) {
			sum += a[i] / mid;
		}
		if (K <= sum) {
			if (ret < mid)
				ret = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// code
	cin >> N >> K;
	REP(i, N) {
		cin >> a[i];
		if (mx < a[i])
			mx = a[i];
	}
	ll ans = proc();
	cout << ans << '\n';
	return 0;
}