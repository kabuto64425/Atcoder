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
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> A(N, vector<ll>(N));
    for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
        cin >> A.at(i).at(j);
    }
    ll ok = 1000000000;
    ll ng = -1;
    while(abs(ok - ng) != 1) {
        ll mid = (ok + ng) / 2;
        bool flag = false;
        vector<vector<ll>> csum(N + 1, vector<ll>(N + 1));
        for(ll i = 1; i <= N; i++) for(ll j = 1; j <= N; j++) {
            if(mid >= A.at(i - 1).at(j - 1)) {
                csum.at(i).at(j) = 1;
            } else {
                csum.at(i).at(j) = -1;
            }
        }
        for(ll i = 1; i <= N; i++) {
            for(ll j = 0; j <= N; j++) {
                csum.at(i).at(j) += csum.at(i - 1).at(j);
            }
        }
        for(ll i = 0; i <= N; i++) {
            for(ll j = 1; j <= N; j++) {
                csum.at(i).at(j) += csum.at(i).at(j - 1);
            }
        }
        for(ll i = K; i <= N; i++) for(ll j = K; j <= N; j++) {
            ll x = csum.at(i).at(j) - csum.at(i - K).at(j) - csum.at(i).at(j - K) + csum.at(i - K).at(j - K);
            if(x >= 0) {
                flag = true;
                break;
            }
        }
        if(flag) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}