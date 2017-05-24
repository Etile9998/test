#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i = a; i < b; ++i)
const int MAXN = 3e+5 + 1;

ll T, N, K, ans, y, x;
char route[MAXN];

ll calc(ll a, ll b) {
    if ((a + b) % 2 == 0) // 증가 
        return (a + b)*(a + b + 1) / 2 + 1 + b;
    else // 감소
        return (a + b + 1)*(a + b + 2) / 2 - b;
}

void proc() {
    y = x = 0;
    ans = 1;
    rep(i, 0, K) {
        switch (route[i]) {
        case 'D':++y; break;
        case 'L':--x; break;
        case 'R':++x; break;
        case 'U':--y; break;
        }
        // calc ans;
        if (x + y < N)
            ans += calc(y, x);
        else
            ans += N*N - calc(N - y - 1, N - x - 1) + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // your code goes here
    cin >> T;
    rep(tc, 1, T + 1) {
        cin >> N >> K >> route;
        proc();
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}