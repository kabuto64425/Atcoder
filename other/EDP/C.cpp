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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i) >> C.at(i);
    }
    vector<vector<ll>> ABC(N, vector<ll>(3));
    for(ll i = 0; i < N; i++) {
        ABC.at(i).at(0) = A.at(i);
        ABC.at(i).at(1) = B.at(i);
        ABC.at(i).at(2) = C.at(i);
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(3, 0));
    dp.at(0).at(0) = 0;
    dp.at(0).at(1) = 0;
    dp.at(0).at(2) = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < 3; j++) {
            for(ll k = 0; k < 3; k++) {
                if(j == k) {
                    continue;
                }
                chmax(dp.at(i + 1).at(j), dp.at(i).at(k) + ABC.at(i).at(j));
            }
        }
    }
    ll ans = *max_element(ALL(dp.at(N)));
    cout << ans << endl;
    return 0;
}