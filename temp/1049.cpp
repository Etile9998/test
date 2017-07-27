#include <cstdio>

int main() {
	int n, k;
	int mn1 = 9999, mn6 = 9999;
	int a, b;
	scanf("%d %d", &n, &k);
	while (k--){
		scanf("%d %d", &a, &b);
		if (mn6 > a)
			mn6 = a;
		if (mn1 > b)
			mn1 = b;
	}
	if (mn1 * 6 < mn6) {
		printf("%d\n", mn1*n);
	}
	else if(n%6*mn1 < mn6){
		printf("%d\n", n / 6 * mn6 + n % 6 * mn1);
	}
	else {
		printf("%d\n", (n + 5) / 6 * mn6);
	}
	return 0;
}