#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; ++i)

int t, a, b, c, n, k;
char ans[8];
bool awin[1000001];
int asum[1000001];
bool bwin[1000001];
int bsum[1000001];

int pre, sum;
char proc() {
    // 1 ~ a => lose
    // a + 1 ~ a + b => win
    rep(i, a + 1, a + b + 1) {
        awin[i] = 1;
        asum[i] = asum[i - 1] + 1;
    }
    // 1 ~ b => b lose
    // b + 1 ~ a + b => b win
    rep(i, b + 1, a + b + 1) {
        bwin[i] = 1;
        bsum[i] = bsum[i - 1] + 1;
    }

    rep(i, a + b + 1, n + 1) {
        pre = max(i - a*k, 1); // a 가 이길 수 있는 경우
        awin[i] = 0;
        asum[i] = asum[i - 1];
        sum = bsum[i - a] - bsum[pre - 1];
        if (sum != i - a - pre + 1) {
            awin[i] = 1;
            asum[i] = asum[i - 1] + 1;
        }

        pre = max(i - b*k, 1); // b 가 이길 수 있는 경우
        bwin[i] = 0;
        bsum[i] = bsum[i - 1];
        sum = asum[i - b] - asum[pre - 1];
        if (sum != i - b - pre + 1) {
            bwin[i] = 1;
            bsum[i] = bsum[i - 1] + 1;
        }
    }

    return awin[n] ? 'a' : 'b';
}

int main() {
    // your code goes here
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    rep(tc, 1, t + 1) {
        cin >> a >> b >> c;
        rep(i, 0, c) {
            memset(awin, 0, sizeof(awin));
            memset(bwin, 0, sizeof(bwin));
            memset(asum, 0, sizeof(asum));
            memset(bsum, 0, sizeof(bsum));
            cin >> n >> k;
            ans[i] = proc();
        }
        ans[c] = '\0';
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}