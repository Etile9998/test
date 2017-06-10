#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i = a;i<=b;++i)
#define max(a,b) (a>b?a:b)
int Answer;
int N;
int a[101][101];
int d[101][101];

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, test_case;
    freopen("a.in", "r", stdin);
    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        Answer = -987654321;
        cin >> N;
        rep(i, 1, N) {
            rep(j, 1, N) {
                cin >> a[i][j];
                d[i][j] = a[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            }
        }

        rep(i, 1, N) {
            rep(j, 1, N) {
                rep(k, i, N) {
                    rep(l, j, N) {
                        int ret = d[k][l] - d[i - 1][l] - d[k][j - 1] + d[i - 1][j - 1];
                        if (Answer < ret)
                            Answer = ret;
                    }
                }
            }
        }

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}