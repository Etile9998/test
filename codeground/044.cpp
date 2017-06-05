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

int T, N, L, ans;
int u, v;
int a[201][201];
int color[201];
bool flag;
void input() {
    flag = 0;
    memset(a, 0, sizeof(a));
    memset(color, -1, sizeof(color));
    cin >> N >> L;
    re(i, L) {
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
}

void proc(int j) {
    rep(i, 1, N) {
        if (j == i)continue;
        if (a[i][j]) {
            a[i][j] = a[j][i] = 0;
            if (color[i] == color[j]) {
                flag = 1;
                return;
            }
            color[i] = !color[j];
            proc(i);
        }
    }
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
        rep(i, 1, N) {
            if (color[i] == -1){
                color[i] = 1;
                proc(i);
            }
        }
        // output
        cout << "Case #" << tc<<'\n';
        if (flag)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}