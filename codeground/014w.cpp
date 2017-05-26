#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define rep(i,a,b) for(int i = a; i < b; ++i)

struct Line {
    int sx, sy, ex, ey;
};

int t, n, ans;
Line p[100];
int b;

int dist(int x1, int y1, int x2, int y2) {
    return max(abs(x1 - x2), abs(y1 - y2));
}

int prec(){
    int d, ret = 0;
    rep(i,1,n){
        rep(j,0,i){
            cout<<i<<" "<<j<<" : ";
            d = 2e9;
            d = min(d, dist(p[i].sx, p[i].sy, p[j].sx, p[j].sy));
            d = min(d, dist(p[i].sx, p[i].sy, p[j].ex, p[j].ey));
            d = min(d, dist(p[i].ex, p[i].ey, p[j].sx, p[j].sy));
            d = min(d, dist(p[i].ex, p[i].ey, p[j].ex, p[j].ey));
            cout<<d <<"\n";
            if (ret < d)
                ret = d;
        }
    }
    return ret;
}
bool check(int val) {
    int d; // max x, y
    rep(i, 1, n) {
        rep(j, 0, i) {
            d = 2e9;
            d = min(d, dist(p[i].sx, p[i].sy, p[j].sx, p[j].sy));
            d = min(d, dist(p[i].sx, p[i].sy, p[j].ex, p[j].ey));
            d = min(d, dist(p[i].ex, p[i].ey, p[j].sx, p[j].sy));
            d = min(d, dist(p[i].ex, p[i].ey, p[j].ex, p[j].ey));
            if (b < d)b = d;
            //if (d > val)return 0;
        }
    }
    //return 1;
}

int proc() {
    int s = 0, e = 1e9, m;
    int ret = e;
    while (s <= e) {
        m = s + ((e - s) >> 1);
        if (check(m)) {
            ret = m;
            e = m - 1;
        }
        else {
            s = m + 1;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("a.in", "r", stdin);
    // your code goes here
    cin >> t;
    rep(tc, 1, t + 1) {
        cin >> n;
        rep(i, 0, n) {
            cin >> p[i].sx >> p[i].sy >> p[i].ex >> p[i].ey;
            //p[i].sx <<= 1; p[i].sy <<= 1; p[i].ex <<= 1; p[i].ey <<= 1;
        }
        //ans = proc();
        ans = prec();
        cout << "Case #" << tc << '\n' << ans / 2.0 << '\n';
    }
    return 0;
}
