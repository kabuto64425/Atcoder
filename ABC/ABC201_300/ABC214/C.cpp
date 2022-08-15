#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> S(N);
    vector<ll> T(N);
    for(ll &s : S) {
        cin >> s;
    }
    for(ll &t : T) {
        cin >> t;
    }
    vector<ll>::iterator iter = min_element(T.begin(), T.end());
    size_t tm = distance(T.begin(), iter);

    ll current = T.at(tm);
    vector<ll> ans(N);

    for(ll i = 0; i < N; i++) {
        ans.at((tm + i) % N) = current;
        current = min(current + S.at((tm + i) % N), T.at((tm + i + 1) % N));
    }

    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }

    return 0;
}