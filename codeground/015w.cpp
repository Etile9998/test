#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

int t,n,m;
int u,v,weight;

bool ans[1001];

int main(){
    // your code goes here
    freopen("a.in","r",stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    rep(tc,1,t+1){
        cin>>n>>m;
        rep(i,0,m){
            cin>>u>>v>>weight;
        }
    }
    return 0;
}
