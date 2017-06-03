#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9+9;
#define rep(i,a,b) for(int i=a;i<b;++i)

int T,N,K,L;
ll ans;
ll d[50001][101]; // d[i][0] mine
ll sum[50001];
int t;
ll proc(){
    ll ret = 0;
    rep(i,1,K+1)
        d[0][i] = 1;
    rep(i,1,N+1){
        if(d[i][0])continue;
        rep(j,1,K+1){
            if(i<j)continue;
            if(i==j)d[i][j] = 1;
            else{
                d[i][j] = (mod + sum[i-j] - d[i-j][j]) % mod;
            }
            sum[i] = (sum[i] + d[i][j]) % mod;
        }
    }
    ret = sum[N];
    return ret;
}
int main(){
    //freopen("a.in","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    rep(tc,1,T+1){
        memset(d,0,sizeof(d));
        memset(sum,0,sizeof(sum));
        cin>>N>>K>>L;
        rep(i,0,L){
            cin>>t;
            d[t][0] = 1;
        }
        ans = proc();
        cout << "Case #" << tc << '\n';
        cout << ans << '\n';
    }
    return 0;
}
