#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    ll c1 = X / (A + C);
    ll d1 = c1 * B * A;
    ll e1 = X % (A + C);
    d1 += min(e1, A) * B;

    ll c2 = X / (D + F);
    ll d2 = c2 * E * D;
    ll e2 = X % (D + F);
    d2 += min(e2, D) * E;

    if(d1 > d2) {
        cout << "Takahashi" << endl;
        return 0;
    }
    if(d2 > d1) {
        cout << "Aoki" << endl;
        return 0;
    }
    cout << "Draw" << endl;
    return 0;
}