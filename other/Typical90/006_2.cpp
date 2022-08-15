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
    string S;
    cin >> S;
    vector<vector<ll>> v(26, vector<ll>(N, N));
    for(ll i = 0; i < N; i++) {
        v.at(S.at(i) - 'a').at(i) = i;
    }
    for(ll i = 0; i < 26; i++) {
        for(ll j = N - 1; j >= 1; j--) {
            chmin(v.at(i).at(j - 1), v.at(i).at(j));
        }
    }
    string ans = "";
    ll p = 0;
    for(ll i = 0; i < K; i++) {
        ll rest = K - i;
        for(ll j = 0; j < 26; j++) {
            if(N - v.at(j).at(p) >= rest) {
                ans += (char)('a' + j);
                p = v.at(j).at(p);
                p++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}