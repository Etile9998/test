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
pair<int, int> pt[101];
double w[101][101];
double ans;

double ccw(int a, int b, int c) {
    double ret =
        +pt[a].first * pt[b].second - pt[a].second * pt[b].first
        + pt[b].first * pt[c].second - pt[b].second * pt[c].first
        + pt[c].first * pt[a].second - pt[c].second * pt[a].first;

    ret /= w[a][b];
    return ret;
}

double proc() {
    double ret = MOD;
    FOR(i, 1, N + 1) {
        FOR(j, i + 1, N + 1) {
            w[i][j] = w[j][i] = hypotl(pt[i].first - pt[j].first, pt[i].second - pt[j].second);
        }
    }
    FOR(i, 1, N + 1) {
        FOR(j, i + 1, N + 1) {
            double mx = 0, mn = 0; // max, min
            FOR(k, 1, N + 1) {
                double v = ccw(i, j, k);
                if (mn > v) // min > v
                    mn = v;
                if (mx < v) // max < v
                    mx = v;
            }
            if (ret > mx - mn)
                ret = mx - mn;
        }
    }
    return ret;
}
int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(2);
    cin >> T;
    FOR(tc, 1, T + 1) {
        cin >> N;
        FOR(i, 1, N + 1) {
            cin >> pt[i].first >> pt[i].second;
        }
        ans = proc();
        cout << "Case #" << tc << '\n';
        cout << (ans + 0.005) << '\n';
    }
    return 0;
}