#include <iostream>
using namespace std;

#define min(a,b) (a<b?a:b)
int Answer;
char c[10001];
int a[4]; //h e l l o
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, test_case;

    freopen("a.in", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        a[0] = a[1] = a[2] = a[3] = 0;
        cin >> c;
        int i = 0;
        while (c[i]) {
            if (c[i] == 'h')++a[0];
            else if (c[i] == 'e')++a[1];
            else if (c[i] == 'l')++a[2];
            else if (c[i] == 'o')++a[3];
            ++i;
        }
        a[2] >>= 1;
        Answer = a[0];
        for (int i = 1; i < 4; ++i)Answer = min(Answer, a[i]);

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}