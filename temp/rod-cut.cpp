#include <iostream>
using namespace std;

void proc() {
	int N, a[3];
	cin >> N;
	for (int i = 0; i < 3; ++i) {
		cin >> a[i];
	}
	int d[4001] = { 1 };
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i >= a[j] && d[i - a[j]] && d[i] <= d[i - a[j]])
				d[i] = d[i - a[j]] + 1;
				
		}
	}
	cout << d[N] - 1 << '\n';
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		proc();
	}
	return 0;
}