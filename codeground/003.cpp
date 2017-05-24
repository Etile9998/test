#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

int T,N,K;
int a[200000],ans;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	rep(tc,1,T+1){
		cin>>N>>K;
		rep(i,0,N){
			cin>>a[i];
		}
		sort(a,a+N,greater<int>());
		rep(i,0,K){
			ans+=a[i];
		}
		printf("Case #%d\n%d\n",tc,ans);
		ans = 0;
	}
	return 0;
}
