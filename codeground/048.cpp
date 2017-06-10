#include <iostream>
using namespace std;

int Answer;
int a, b, d;

int proc() {
    int ret = (d - b) / (a - b);
    if (ret*(a - b) != (d - b))
        return ret + 1;
    else
        return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, test_case;
    freopen("a.in", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        cin >> a >> b >> d;
        Answer = proc();
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}