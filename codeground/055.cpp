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

int T, N;

void move(int from, int to) {
    cout << from << " -> " << to << '\n';
}
void proc(int n, int from, int by, int to) {
    if (n == 1) {
        move(from, to);
    }
    else {
        proc(n - 1, from, to, by);
        move(from, to);
        proc(n - 1, by, from, to);
    }
}
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    FOR(tc, 1, T + 1) {
        cin >> N;
        cout << "Case #" << tc << '\n';
        proc(N,1,2,3);
    }
    return 0;
}
