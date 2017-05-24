#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define rep(i,a,b) for(int i=a;i<b;++i)

int T,ans;
int A,B,C,D,E,N,x,y;
const ld PI = acos(-1);
int p[20] = {6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10};

int proc(){
	int ret;
	ld points;
	int dist = x*x + y*y;

	if(dist <= A*A){ // BULL : 50 points
		return 50;
	}
	else if(dist <= B*B){ // SINGLE : X1
		ret = 1;	
	}
	else if(dist <= C*C){ // TRIPLE : X3
		ret = 3;
	}
	else if(dist <= D*D){ // SINGLE : X1
		ret = 1;
	}
	else if(dist <= E*E){ // DOUBLE : X2
		ret = 2;
	}
	else{ // OUT BOARD : 0
		return 0;
	}

	points = atan2(y,x)*180/PI + 9;
	if (points < 0)
		points += 360;
	if (points >= 360)
		points -= 360;

	return ret * p[(int)(points/18)];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	rep(tc,1,T+1){
		cin>>A>>B>>C>>D>>E>>N;
		rep(i,0,N){
			cin>>x>>y;
			ans += proc();
		}
		printf("Case #%d\n%d\n",tc,ans);
		ans = 0;
	}
	return 0;
}
