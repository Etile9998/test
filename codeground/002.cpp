#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
int C,N,maxScore,ans;
int a[300000];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>C;
	rep(tc,1,C+1){
		cin>>N;
		rep(i,0,N)
			cin>>a[i];
		sort(a,a+N);
		rep(i,0,N){
			a[i]-=i;
			if (maxScore < a[i])
				maxScore = a[i];
		}
		rep(i,0,N){
			a[i]+=i;
			if (maxScore<=a[i])
				++ans;
		}
		printf("Case #%d\n%d\n",tc,ans);
		maxScore = ans = 0;
	}
	return 0;
}
