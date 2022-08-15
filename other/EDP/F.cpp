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
    string s;
    string t;
    cin >> s >> t;
    ll N, M;
    N = s.length();
    M = t.length();
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1));
    vector<vector<tuple<ll, ll, char>>> pre(N + 1, vector<tuple<ll, ll, char>>(M + 1));
    for(ll i = 0; i <= N; i++) {
        for(ll j = 0; j <= M ; j++) {
            if(j + 1 <= M) {
                if(chmax(dp.at(i).at(j + 1), dp.at(i).at(j))) {
                    pre.at(i).at(j + 1) = {i, j, '0'};
                }
            }
            if(i + 1 <= N) {
                if(chmax(dp.at(i + 1).at(j), dp.at(i).at(j))) {
                    pre.at(i + 1).at(j) = {i, j, '0'};
                }
            }
            if(i + 1 <= N and j + 1 <= M) {
                if(s.at(i) == t.at(j)) {
                    if(chmax(dp.at(i + 1).at(j + 1), dp.at(i).at(j) + 1)) {
                        pre.at(i + 1).at(j + 1) = {i, j, s.at(i)};
                    }
                }
            }
        }
    }
    string ans = "";
    ll i = N;
    ll j = M;
    while(i != 0 or j != 0) {
        tuple<ll, ll, ll> v = pre.at(i).at(j);
        i = get<0>(v);
        j = get<1>(v);
        if(get<2>(v) >= 'a' and get<2>(v) <= 'z') {
            ans += get<2>(v);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}