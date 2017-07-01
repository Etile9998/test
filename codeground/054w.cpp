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

int T, N, checksum;
ll ans;

// <pos, bridge>
pair<int, int> a[4001];
bool check[4001];
int parent[4001];

int find(int x) {
    return (x == parent[x]) ? x : parent[x] = find(parent[x]);
}

void link(int x, int y) {
    parent[find(y)] = find(x);
}

ll proc() {
    // init
    FOR(i, 1, N + 1)parent[i] = i;
    CLEAR(check, 0);
    ll ret = 0;
    int l, r, target;
    bool flag;

    // proc 1 단말노드(차수가 1남은 노드)를 연결하는 과정
    while (1) {
        flag = 1;
        FOR(i, 1, N + 1) {
            if (!check[i] && a[i].second == 1) {
                l = i - 1, r = i + 1;
                while (1 <= l && a[l].second < 2)--l;
                if (1 > l)l = -1;
                while (r <= N && a[r].second < 2)++r;
                if (r > N)r = -1;
                if (l == -1 && r == -1)continue;// 둘만 남았네?
                flag = 0;
                if (l == -1 || r == -1) {
                    target = (l != -1) ? l : r;
                }
                else {
                    // 으아아아아아 이 부분을 모르겠다. 알고리즘을 잘못 짠 것 같다 ㅠ
                    if (a[i].first - a[l].first == a[r].first - a[i].first) {
                        target = (l - 1 < N - r) ? l : r;
                    }
                    else if (a[i].first - a[l].first < a[r].first - a[i].first) // 타겟의 위치설정
                        target = l;
                    else
                        target = r;
                }

                link(i, target); // disjoint
                --a[i].second;
                --a[target].second;
                if (a[target].second == 0)++check[target];
                if (a[i].second == 0)++check[i];
                ret += abs(a[i].first - a[target].first);

            }
        }
        if (flag) break;// 이제 다리의 개수가 0 || 2 이상의 수들만 남았다.
    }

    // proc 2 - 이제 합병
    int x = 1;
    while (!a[x].second)++x;
    FOR(y, x + 1, N + 1) {
        if (a[y].second && find(x) != find(y)) {
            link(x, y);
            ret += a[y].first - a[x].first;
            x = y;
        }
    }
    // return
    return ret;
}

int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    FOR(tc, 1, T + 1) {
        checksum = 0;
        cin >> N;

        // input
        FOR(i, 1, N + 1) {
            cin >> a[i].first >> a[i].second;
            checksum += a[i].second;
        }

        sort(a + 1, a + N + 1);
        // checksum1 - 안 되는 경우
        if (checksum < 2 * N - 2) {
            cout << "Case #" << tc << "\n-1\n";
            continue;
        }

        // checksum2 - 일렬로 연결이 가능한 경우
        bool flag = 1;
        FOR(i, 2, N) { 
            if (a[i].second == 1)flag = 0;
        }
        if (flag) {
            cout << "Case #" << tc << "\n";
            cout << (a[N].first - a[1].first) << '\n';
            continue;
        }

        // solve
        ans = proc();

        // output
        cout << "Case #" << tc << '\n';
        cout << ans << '\n';
    }
    return 0;
}
