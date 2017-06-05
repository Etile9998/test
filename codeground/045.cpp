#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rer(i,a,b) for(int i = a; i >= b; --i)
#define rep(i,a,b) for(int i = a; i <= b; ++i)
#define re(i,a) rep(i,0,a-1)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int T, N, M, ans;
int a[5000];
bool b[10001];

void input() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin >> N >> M;
    b[0] = 1;
    re(i, N) {
        cin >> a[i];
    }
}

int proc() {
    re(i, N) {
        rer(j, M, a[i]) {
            if (b[j - a[i]])
                b[j] = 1;
        }
    }
    rer(i, M, 0) {
        if (b[i])return i;
    }
}

int main() {
    // your code goes here
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    rep(tc, 1, T) {
        // input
        input();
        // solve
        ans = proc();
        // output
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}