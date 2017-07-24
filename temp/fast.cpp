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
	// fast IO
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

	// 16 heap sort
	int child = 16;
	template <typename T>
	void heapify(T* src, const int n, int i) {
		int largest = i;
		int idx;

		for (int j = 1; j <= child; ++j) {
			idx = child * i + j;
			if (idx < n && src[idx] > src[largest])
				largest = idx;
		}

		if (largest != i)
		{
			std::swap(src[i], src[largest]);
			heapify(src, n, largest);
		}
	}

	template<typename T>
	void your_sort(T* src, const int size) { // T src[size] = {...};
											 // your code goes here
		for (int i = size / child - 1; i >= 0; i--)
			heapify(src, size, i);

		// One by one extract an element from heap
		for (int i = size - 1; i >= 0; i--)
		{
			// Move current root to end
			std::swap(src[0], src[i]);

			// call max heapify on the reduced heap
			heapify(src, i, 0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// code

	return 0;
}