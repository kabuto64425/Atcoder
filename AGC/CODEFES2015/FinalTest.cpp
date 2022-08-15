#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K, M, R;
    cin >> N >> K >> M >> R;
    vector<ll> S(N - 1);
    for(ll &s : S) {
        cin >> s;
    }
    sort(S.begin(), S.end(), greater<ll>());
    ll current = K * R;
    for(ll i = 0; i < K - 1; i++) {
        current -= S.at(i);
    }
    if(N == K) {
        if(current <= M) {
            cout << max(0LL, current) << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    if(current > S.at(K - 1)) {
        if(current <= M) {
            cout << current << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        cout << 0 << endl;
    }
    return 0;
}