#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
#define re(i,a) rep(i,0,a-1)

int T,N,S,ans;
int a[100000];

int proc(){
    int ret = 0x7fffffff;
    int st,ed,sum;
    st = ed = sum = 0;
    while(1){
        if(sum - a[st] >= S){
            sum -= a[st++];
        }
        else if(ed < N)
            sum += a[ed++];
        else
            break;
        if(sum >= S && ret > ed-st)
            ret = ed-st;
    }
    if(ret == 0x7fffffff)return 0;
    return ret;
}
int main(){
    freopen("a.in","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    rep(tc,1,T){
        cin>>N>>S;
        re(i,N){
            cin>>a[i];
        }
        ans = proc();
        cout<<"#testcase"<<tc<<'\n';
        cout<<ans<<'\n';
    }
    return 0;
}
