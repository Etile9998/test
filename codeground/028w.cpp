#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define repr(i,a,b) for(int i = a; i >= b; --i)
#define rep(i,a,b) for(int i = a; i <= b; ++i)
#define rp(i,a) rep(i,0,a-1)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int T, N, M, K, ans;
int u, v, cost;
class Node {
public:
    int to, cost;
    Node(int t, int c) :to(t), cost(c) {};
};

Node a[100000];

int main() {
    // your code goes here
    freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    rep(tc, 1, T) {
        cin >> N >> M >> K;
        rp(i, M) {
            cin >> u >> v >> cost;
            a[u] = Node(v, cost);
            a[v] = Node(u, cost);
        }
    }

    return 0;
}