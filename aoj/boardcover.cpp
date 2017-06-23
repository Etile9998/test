#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int C,H,W;
char a[20][21];
int diov;
const int ddd[4][2][2] = {
    {{1,-1},{1,0}},
    {{1,0},{1,1}},
    {{0,1},{1,1}},
    {{1,0},{0,1}}
};

bool check(int r, int c, int x,int val){
    
}
int proc(){
    if(!doiv)return 1;
    int ret = 0;
    rep(i,0,H-1){
        rep(j,0,W-1){
            if(a[i][j] == '.'){
                rep(dir,0,3){
                    if(check(dir)){
                        doiv -= 3;
                        proc();
                        doiv += 3;
                    }
                }
            }
        }
    }
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>C;
    while(C--){
        cin>>H>>W;
        rep(i,0,H-1){
            rep(j,0,W-1){
                cin>>a[i][j];
                if (a[i][j] == '.')
                    ++diov;
            }
        }
        if(diov%3){
            cout<<"0\n";
            continue;
        }
        ans = proc();
        cout<<ans<<'\n';
    }
    return 0;
}
