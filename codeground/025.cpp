#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
typedef unsigned long long ull;

int T,K;
ull ans;

ull proc(){
    ull ret,n = 1;
    ull cnt;
    while(1){
        cnt = 0;
        ret = n;
        while(1){
            if(ret == 1)break;
            ++cnt;
            if (ret % 2){
                ret = 3*ret+1;
            }
            else
                ret /= 2;
        }
        if(cnt == K)break;
        ++n;
    }
    return ret = n;
}
int main(){
    //freopen("a.in","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    rep(tc,1,T+1){
        cin>>K;
        ans = proc();
        cout<<"Case #"<<tc<<'\n';
        cout<<ans<<" "<<(1ULL<<K)<<'\n';
    }
}
