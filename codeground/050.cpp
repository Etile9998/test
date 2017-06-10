#include <iostream>
using namespace std;

int Answer;
int N, M, K;
int c[30], p[21];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, test_case;
    freopen("a.in", "r", stdin);
    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        cin >> N >> M >> K;
        for (int i = 0; i < N; ++i) {
            cin >> c[i];
        }
        for (int i = 1; i <= M; ++i) {
            cin >> p[i];
        }
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += p[c[i]];
        }
        Answer = (sum <= K) ? 1 : 0;
        cout << "Case #" << test_case + 1 << endl;
        cout << (Answer ? "Y\n" : "N\n");
    }

    return 0;
}