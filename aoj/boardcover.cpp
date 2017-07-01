#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(auto it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()

int C, H, W;
char ch;
char a[20][21];

const int coverType[4][3][2] = {
    { { 0, 0 },{ 1, 0 },{ 0, 1 } },
    { { 0, 0 },{ 0, 1 },{ 1, 1 } },
    { { 0, 0 },{ 1, 0 },{ 1, 1 } },
    { { 0, 0 },{ 1, 0 },{ 1, -1 } } };

bool check(int y, int x, int type, int delta) {
    bool ok = true;
    REP(i, 3) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W || (a[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int proc() {
    // 아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다
    int ret = 0;
    int y = -1, x = -1;
    REP(i, H) {
        REP(j, W) {
            if (!a[i][j]) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }
    // 기저 사례: 모든 칸을 채웠으면 1을 반환한다
    if (y == -1) return 1;

    REP(dir, 4) {
        // 만약 board[y][x] 을 type 형태로 덮을 수 있으면 재귀호출한다
        if (check(y, x, dir, 1))
            ret += proc();
        // 덮었던 블록을 치운다
        check(y, x, dir, -1);
    }
    return ret;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> C;
    while (C--) {
        CLEAR(a, 0);
        int white = 0;
        cin >> H >> W;
        assert(1 <= H && H <= 20);
        assert(1 <= W && W <= 20);
        REP(i, H) {
            REP(j, W) {
                cin >> ch;
                if (ch == '#')
                    a[i][j] = 1;
                else
                    ++white;
            }
        }
        assert(white <= 50);
        int ans = proc();
        cout << ans << '\n';
    }
    return 0;
}