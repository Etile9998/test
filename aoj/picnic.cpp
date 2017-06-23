#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int C;
int n,m;
int u,v;
int ans,len;
bool a[10][10];
bool b[10];

int proc(){
    int ret = 0;
    int x = -1;
    rep(i,0,n-1){
        if(!b[i]){
            x = i;
            break;
        }
    }
    if(x==-1)return 1;
    rep(y,x+1,n-1){
        if(!b[y]&&a[x][y]){
            b[y] = b[x] = 1;
            ret += proc();
            b[y] = b[x] = 0;
        }
    }
    return ret;
}
int main(){
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>C;
    while(C--){
        memset(a,0,sizeof(a)); 
        cin>>n>>m;
        len = n;
        while(m--){
            cin>>u>>v;
            a[u][v] = a[v][u] = 1;
        }
        ans = proc();
        cout<<ans<<'\n';
    }
    return 0;
}
