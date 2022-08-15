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
    for(vector<ll> &vec : T) {
        for(ll &t : vec) {
            cin >> t;
        }
    }
    vector<ll> root(N - 1);
    REP(i, N - 1) {
        root[i] = i + 1;
    }
    ll ans = 0;
    do {
        ll dist = 0;
        for(ll i = 0; i < N - 1; i++) {
            if(i == 0) {
                dist += T[0][root[i]];
            } else {
                dist += T[root[i - 1]][root[i]];
            }
        }
        dist += T[root[N - 2]][0];
        if(dist == K) {
            ans++;
        }
    } while (next_permutation(root.begin(), root.end()));
    cout << ans << endl;
    return 0;
}