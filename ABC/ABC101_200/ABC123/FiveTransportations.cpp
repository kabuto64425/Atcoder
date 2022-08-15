#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;
    ll minPeople = min({A, B, C, D, E});
    cout << ((N + (minPeople - 1)) / minPeople + 4 ) << endl;
}