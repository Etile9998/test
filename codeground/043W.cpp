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
int A[10001];
int B[10001];
int P[10001];
int Q[10001];
void input() {
    cin >> N >> M;
    re(i, M) {
        
    }
}

int proc() {
    int ret = 0;

    return ret;
}

int main() {
    // your code goes here
    freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    rep(tc, 1, T) {
        // input
        input();
        // solve
        ans = proc();
        // output
        cout << ans << '\n';
    }
    return 0;
}