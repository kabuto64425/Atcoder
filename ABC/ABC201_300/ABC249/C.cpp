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
    vector<string> S(N);
    for(ll  i = 0; i < N; i++) {
        cin >> S.at(i);
    }
    ll ans = 0;
    for(ll bit = 0; bit < (1 << N); bit++) {
        bitset<20> s(bit);
        map<char, ll> m;
        for(ll i = 0; i < N; i++) {
            if(s.test(i)) {
                for(ll j = 0; j < S.at(i).length(); j++) {
                    m[S.at(i).at(j)]++;
                }
            }
        }
        ll current = 0;
        for(auto elm : m) {
            if(elm.second == K) {
                current++;
            }
        }
        ans = max(ans, current);
    }
    cout << ans << endl;
    return 0;
}