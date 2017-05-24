#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
int T,N,x,ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    rep(tc,1,T+1){
        cin>>N;
        while(N--){
            cin>>x;
            ans^=x;
        }
        cout<<"Case #"<<tc<<'\n'<<ans<<'\n';
        ans = 0;
    }
    return 0;
}
