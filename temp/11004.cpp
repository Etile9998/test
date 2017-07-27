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

namespace fast {
	// fast i/o
	const int BSIZE = 524288;
	char buffer[BSIZE];
	int p = BSIZE;
	inline char readChar() {
		if (p == BSIZE) {
			fread(buffer, 1, BSIZE, stdin);
			p = 0;
		}
		return buffer[p++];
	}
	int readInt() {
		char c = readChar();
		while ((c < '0' || c > '9') && c != '-') {
			c = readChar();
		}
		int ret = 0; bool neg = c == '-';
		if (neg) c = readChar();
		while (c >= '0' && c <= '9') {
			ret = ret * 10 + c - '0';
			c = readChar();
		}
		return neg ? -ret : ret;
	}

	// radix sort
	template<class T>
	void radixSort(T* src, const size_t size) {

	}
}

int N, K;
int a[5000000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// code
	N = fast::readInt();
	K = fast::readInt();
	REP(i, N)
		a[i] = fast::readInt();
	nth_element(a, a + K - 1, a + N);
	cout << a[K - 1] << '\n';
	return 0;
}