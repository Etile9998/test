#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()

int T, K, len;
char ans[100];
int getlen(int x) {
    int ret = 0;
    int sum = 0;
    while (sum <= x) {
        ++ret;
        sum += 1 << (ret);
        K -= 1 << ret;
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    FOR(tc, 1, T + 1) {
        cin >> K; --K;
        len = getlen(K);
        ans[len] = '\0';
        while (len--) {
            if (K & 1)
                ans[len] = '7';
            else
                ans[len] = '4';
            K >>= 1;
        }
        cout << "Case #" << tc << '\n';
        cout << ans << '\n';
    }
    return 0;
}
