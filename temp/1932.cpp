#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

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

int d[501][501];
int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	n = fast::readInt();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			d[i][j] = fast::readInt();

	for (int i = n - 1; i >= 1; i--)
		for (int j = 1; j <= i; j++)
			d[i][j] += max(d[i + 1][j], d[i + 1][j + 1]);

	printf("%d\n", d[1][1]);
	return 0;
}