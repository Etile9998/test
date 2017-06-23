#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll mod = 1e9+7;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int C,N,L;
int a[1001];
int sum[1001];
ld ans;

ld proc(){
    ld ret = 0;
    int cost = 100;
    int day = 1;
    
    rep(i,L,N){
        int tmpCost = sum[i];
        int tmpDay = i;
        rep(j,i,N){
            if (tmpCost > sum[j] - sum[j-i])
                tmpCost = sum[j] - sum[j-i];
        }
        if (tmpCost * day < cost * tmpDay){
            cost = tmpCost;
            day = tmpDay;
        }
    }

    ret = cost;
    ret /= day;
    return ret;
}
int main(){
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>C;
    while(C--){
        cin>>N>>L;
        rep(i,1,N){
            cin>>a[i];
            sum[i] = sum[i-1]+a[i];
        }
        ans = proc();
        printf("%.9Lf\n",ans);
    }

    return 0;
}
