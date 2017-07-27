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

int N, M;
int a[1000000];
ll sum;

int proc() {
	int l = 0, r = 1e9;
	int mid;
	while(l<r){
		mid = (l + r) / 2;
		sum = 0;
		REP(i, N) {
			if (mid >= a[i])
				continue;
			sum += a[i] - mid;
		}
		if (sum < M)
			r = mid;
		else
			l = mid+1;
	}

	return l - 1;
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	// code
	cin >> N >> M;
	REP(i, N) {
		cin >> a[i];
	}
	int ans = proc();
	cout << ans << '\n';
	return 0;
}