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

using Graph = vector<vector<ll>>;

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            cin >> A.at(i).at(j);
        }
    }

    ll M;
    cin >> M;
    vector<pair<ll, ll>> XY(M);
    for(pair<ll, ll> &xy : XY) {
        cin >> xy.first >> xy.second;
        xy.first--;
        xy.second--;
    }

    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[XY[i].first].push_back(XY[i].second);
        G[XY[i].second].push_back(XY[i].first);
    }

    // 昇順にソート済みの入力
    vector<ll> v(N);
    for(ll i = 0; i < N; i++) {
        v.at(i) = i;
    }

    ll ans = INF;

    do {
        bool flag = true;
        for(ll i = 1; i < N; i++) {
            if(count(G.at(v.at(i - 1)).begin(), G.at(v.at(i - 1)).end(), v.at(i))) {
                flag = false;
                break;
            }
        }
        if(!flag) {
            continue;
        }
        ll sum = A.at(v.at(0)).at(0);
        for(ll i = 1; i < N; i++) {
            sum += A.at(v.at(i)).at(i);
        }
        ans = min(ans, sum);
    } while (next_permutation(v.begin(), v.end()));

    if(ans == INF) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
    return 0;
}