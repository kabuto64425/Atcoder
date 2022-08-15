#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> T(N, vector<ll>(N));
    REP(i, N) {
        REP(j, N) {
            cin >> T.at(i).at(j);
        }
    }

    vector<ll> jun(N - 1);

    for(ll i = 0; i < N - 1; i++) {
        jun.at(i) = i + 1;
    }

    ll ans = 0;

    do {
        ll d = 0;

        for(ll i = 0; i < N - 1; i++) {
            if(i == 0) {
                d += T.at(0).at(jun.at(i));
            } else {
                d += T.at(jun.at(i - 1)).at(jun.at(i));
            }
        }
        d += T.at(jun.at(N - 2)).at(0);
        if(d == K) {
            ans++;
        }
    } while (next_permutation(jun.begin(), jun.end()));

    cout << ans << endl;

    return 0;
}