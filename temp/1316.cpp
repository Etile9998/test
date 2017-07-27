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

bool isGroupWord(const char* str) {
	bool alpha[26] = { };
	char c;
	while (*str) {
		if (alpha[*str - 'a'])return 0;
		c = *str;
		alpha[*str - 'a'] = 1;
		while (c == *str)
			++str;
	}
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	// code
	int N, ans = 0;
	char s[101];
	cin >> N;
	while (N--) {
		cin >> s;
		ans += isGroupWord(s);
	}
	cout << ans << '\n';
	return 0;
}