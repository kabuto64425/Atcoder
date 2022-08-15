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
    vector<ll> x(N), y(N), P(N);
    for(ll i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i) >> P.at(i);
    }
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++)  {
        ll dx = abs(x.at(i) - x.at(j));
        ll dy = abs(y.at(i) - y.at(j));
        dist[i][j] = (dx + dy + P.at(i) - 1) / P.at(i);
        dist[j][i] = (dx + dy + P.at(j) - 1) / P.at(j);
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
        }
    }
    ll ans = INF;
    for(ll i = 0; i < N; i++) {
        ll current = 0;
        for(ll j = 0; j < N; j++) {
            chmax(current, dist[i][j]);
        }
        chmin(ans, current);
    }
    cout << ans << endl;
    return 0;
}