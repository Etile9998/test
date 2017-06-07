#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
#deinfe re(i,a) rep(i,0,a-1)

int T,N,h,ans;
int a[50][50];
int p[50];

int proc(){
    int ret = -1;
    memset(p,0,sizeof(p));


    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    rep(tc,1,T){
        cin>>N;
        re(i,N){
            cin>>h;
            re(j,h){
                cin>>a[i][j];
            }
        }
        ans = proc();
        cout<<"Case #"<<tc<<'\n';
        cout<<ans<<'\n';
    }
    return 0;
}
