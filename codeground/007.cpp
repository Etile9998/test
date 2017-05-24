#include <iostream>
#include <cstring>
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; ++i)

int T, N;
int a[5000], ans;
bool d2[400001];

//i,j,k,l   
void proc() {
    ans = 0;
    d2[200000 + a[0] + a[0]] = 1;
    rep(i, 1, N) {
        rep(j, 0, i) {
            if (d2[200000 + a[i] - a[j]]) {
                ++ans; break;
            }
        }
        rep(j, 0, i + 1)
            d2[200000 + a[i] + a[j]] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("a.in", "r", stdin);
    cin >> T;
    rep(tc, 1, T + 1) {
        memset(d2, 0, sizeof(d2));
        cin >> N;
        rep(i, 0, N) {
            cin >> a[i];
        }
        proc();
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}