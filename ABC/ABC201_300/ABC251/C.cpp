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
    vector<string> S(N);
    vector<ll> T(N);
    for(ll i = 0; i < N; i++) {
        cin >> S.at(i) >> T.at(i);
    }
    ll score = 0;
    ll ans = -1;
    set<string> se;
    for(ll i = 0 ; i < N; i++) {
        if(se.count(S.at(i))) {
            continue;
        }
        se.insert(S.at(i));
        if(T.at(i) > score) {
            score = T.at(i);
            ans = i;
        }
    }
    for(ll i = 0 ; i < N; i++) {
        
    }
    cout << ans + 1 << endl;
    return 0;
}