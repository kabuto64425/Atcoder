#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

bool sort_by(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second > b.second;
}

int main(){
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<pair<ll, ll>> WV(N);
    for(pair<ll, ll> &wv : WV) {
        cin >> wv.first >> wv.second;
    }
    vector<ll> X(M);
    for(ll &x : X) {
        cin >> x;
    }
    vector<pair<ll, ll>> Query(Q);
    for(pair<ll, ll> &query : Query) {
        cin >> query.first >> query.second;
    }
    sort(WV.begin(), WV.end(), sort_by);

    for(const pair<ll, ll> &query : Query) {
        vector<ll> Y = X;
        Y.erase(Y.begin() + query.first - 1, Y.begin() + query.second);
        ll num = Y.size();
        sort(Y.begin(), Y.end());
        vector<bool> used(num);
        ll ans = 0;
        for(ll i = 0; i < N; i++) {
            for(ll j = 0; j < num; j++) {
                if(used.at(j)) {
                    continue;
                }
                if(WV.at(i).first <= Y.at(j)) {
                    ans += WV.at(i).second;
                    used.at(j) = true;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}