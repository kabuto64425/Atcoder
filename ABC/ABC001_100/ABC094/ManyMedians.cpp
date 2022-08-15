#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N;
    cin >> N;
    vector<ll> X(N);

    REP(i, N) {
        cin >> X.at(i);
    }

    vector<ll> Y = X;
    sort(Y.begin(), Y.end());

    ll ansSmall = Y.at(N / 2 -1);
    ll ansLarge = Y.at(N / 2);

    REP(i, N) {
        if(X.at(i) <= ansSmall) {
            cout << ansLarge << endl;
        } else if(X.at(i) >= ansLarge) {
            cout << ansSmall << endl;
        }
    }
}