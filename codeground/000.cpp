#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 987654321;
#define rep(i,a,b) for(int i=a;i<b;++i)

string s;
int a[10],len,t,sum;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    len = s.length();
    rep(i,0,len){
        t = s[i]-'0';
        ++a[t];
        sum += t;
    }
    if(!a[0] || sum % 3){
        cout<<"-1\n";
        return 0;
    }
    for(int i = 9;i>=0;--i){
        while(a[i]--)cout<<i;
    }
    return 0;
}
