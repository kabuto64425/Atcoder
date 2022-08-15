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
    ll N;
    cin >> N;
    vector<ll> T(N);
    for(ll i = 0; i < N; i++) {
        cin >> T.at(i);
    }
    ll M;
    cin >> M;
    vector<ll> P(M), X(M);
    for(ll i = 0; i < M; i++) {
        cin >> P.at(i) >> X.at(i);
    }
    ll sum = accumulate(ALL(T), 0LL);
    for(ll i = 0; i < M; i++) {
        cout << sum + X.at(i) - T.at(P.at(i) - 1) << endl;
    }
    return 0;
}