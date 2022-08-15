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

ll dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
ll dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int main(){
    ll N;
    cin >> N;
    vector<string> A(N);
    for(ll i = 0; i < N; i++){
        cin >> A.at(i);
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
        ll x = i;
        ll y = j;
        for(ll r = 0; r < 8; r++) {
            ll current = 0;
            for(ll k = 0; k < N; k++) {
                current *= 10;
                current += (ll)(A.at(x).at(y) - '0');
                x += dx[r];
                y += dy[r];
                if(x < 0) {
                    x = N - 1;
                }
                if(x >= N) {
                    x = 0;
                }
                if(y < 0) {
                    y = N - 1;
                }
                if(y >= N) {
                    y = 0;
                }
            }
            chmax(ans, current);
        }
    }
    cout << ans << endl;
    return 0;
}