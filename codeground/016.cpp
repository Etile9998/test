#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;
int t,m;
ll b[100000],ans,d;

ll gcd(ll x,ll y){
    if(!x)return 0;
    return y?gcd(y,x%y):x;
}

ll proc(){
    if(b[0] == b[m-1])return 1;
    ll ret = 0;
    int i;
    for(i=1;i*i<=d;++i){
        if(d%i == 0)ret+=2;
        if(i*i == d)--ret;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("a.in","r",stdin);
    cin>>t;
    rep(tc,1,t+1){
        cin>>m;
        cin>>b[0]>>b[1];
        d = b[1] - b[0];
        rep(i,2,m){
            cin>>b[i];
            d = gcd(d, b[i] - b[i-1]);
        }
        ans = proc();
        cout<<"Case #"<<tc<<'\n'<<ans<<'\n';
    }
    return 0;
}
