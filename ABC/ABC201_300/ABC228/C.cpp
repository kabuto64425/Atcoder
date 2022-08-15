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
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> P(N, vector<ll>(3));
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < 3; j++) {
            cin >> P.at(i).at(j);
        }
    }
    vector<ll> sum(N);
    for(ll i = 0; i < N; i++) {
        sum.at(i) = P.at(i).at(0) + P.at(i).at(1) + P.at(i).at(2);
    }
    sort(ALL(sum), greater<ll>());
    ll target = sum.at(K - 1);
    for(ll i = 0; i < N; i++) {
        if(P.at(i).at(0) + P.at(i).at(1) + P.at(i).at(2) + 300 >= target) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}