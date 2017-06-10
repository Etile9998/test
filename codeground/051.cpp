#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
int Answer;
int N, M;

class Node {
public:
    int s, t, c;
    bool operator<(Node n) { return c < n.c; }
};
Node a[10001];
int parent[1001];

int disjoint(int x) {
    return (x == parent[x]) ? x : parent[x] = disjoint(parent[x]);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, test_case;
    freopen("a.in", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        cin >> N >> M;
        rep(i, 1, N)parent[i] = i;
        rep(i, 1, M) {
            cin >> a[i].s >> a[i].t >> a[i].c;
        }
        sort(a + 1, a + M + 1);
        Answer = 0;
        rep(i, 1, M) {
            if (disjoint(a[i].s) != disjoint(a[i].t)) {
                parent[disjoint(a[i].s)] = disjoint(a[i].t);
                ++Answer;
                if (Answer == N / 2) {
                    Answer = a[i].c;
                    break;
                }
            }
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}