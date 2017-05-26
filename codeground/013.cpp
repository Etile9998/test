#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)

int T, N, ans;
int M, rem;
int len;

int proc() {
    int ret = 0;
    if (N < 3)return N + 1;

    // 세 자리 이상
    for (int i = 2; i*i <= N; ++i) {
        M = N / i;
        rem = N%i;
        while (M) {
            if (M%i != rem)break;
            M /= i;
        }
        if (!M)return i;
    }

    // i*(rem+1) == N  => rem == N/i-1
    // 두 자리
    for (int i = 1; i*i <= N; ++i) {
        if (N%i)continue;
        rem = N / i - 1;
        if (i < rem)
            ret = rem;
    }

    return (ret ? ret : N + 1);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // freopen("a.in", "r", stdin);
    // your code goes here
    cin >> T;
    rep(tc, 1, T + 1) {
        cin >> N;
        ans = proc();
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}