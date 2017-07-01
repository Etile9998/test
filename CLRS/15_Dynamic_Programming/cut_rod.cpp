#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()

int cut_rod(int p[],int n){
    if (n == 0)
        return 0;
    int q = -MOD;
    FOR(i,1,n+1){
        q = max(q,p[i]+cut_rod(p,n-i));
    }
    return q;
}

int memoized_cut_rod_aux(int p[],int n,int r[]){
    int q = -MOD;
    if(r[n]>=0)
        return r[n];
    if(n==0)
        q = 0;
    else if(q == -MOD){
        FOR(i,1,n+1)
            q = max(q,p[i]+memoized_cut_rod_aux(p,n-i,r));
    }
    r[n] = q;
    return q;
}

int memoized_cut_rod(int p[],int n){
    int *r = new int[n+1];
    REP(i,n+1)
        r[i] = -MOD;
    return memoized_cut_rod_aux(p,n,r);
}

int bottom_up_cut_rod(int p[],int n){
    int *r = new int[n+1];
    r[0] = 0;
    FOR(j,1,n+1){
        int q = -MOD;
        FOR(i,1,j+1)
            q = max(q,p[i]+r[j-i]);
        r[j] = q;
    }
    return r[n];
}


pair<int*,int*> extended_bottom_up_cut_rod(int p[],int n){
    int *r = new int[n+1];
    int *s = new int[n+1];
    r[0] = 0;
    FOR(j,1,n+1){
        int q = -MOD;
        FOR(i,1,j+1){
            if (q < p[i]+r[j-i]){
                q = p[i]+r[j-i];
            }
        }
        r[j] = q;
    }
    return {r,s};
}

void print_cut_rod_solution(int p[],int n){
    //...
}
int main(){
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    return 0;
}
