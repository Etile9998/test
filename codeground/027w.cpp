#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

int T,K,L,N,M,ans;
int u, v;
int a[100][100];

int proc(){
    int ret = 0;


    return ret;
}
int main(){
    cin >>T;
    rep(tc,1,T+1){
        cin>>K>>L>>N>>M;
        rep(i,0,M){
            cin>>u>>v;
            a[u][v] = a[v][u] = 1;
        }
        ans = proc();
        cout<<"Case #"<<tc<<'\n';
        cout<<ans<<'\n';
    }
    return 0;
}
