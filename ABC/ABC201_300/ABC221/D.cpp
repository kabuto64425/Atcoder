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
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    vector<pair<ll, ll>> p(2 * N);
    for(ll i = 0; i < N; i++) {
        p.at(i * 2).first = A.at(i);
        p.at(i * 2).second++;
        p.at(i * 2 + 1).first = A.at(i) + B.at(i);
        p.at(i * 2 + 1).second--;
    }

    vector<ll> pos;
    for(ll i = 0; i < 2 * N; i++) {
        pos.push_back(p.at(i).first);
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    vector<ll> dp(440000);
    for(ll i = 0; i < 2 * N; i++) {
        ll j = lower_bound(pos.begin(), pos.end(), p.at(i).first) - pos.begin();
        dp.at(j) += p.at(i).second;
    }

    for(ll i = 1; i < (ll)dp.size(); i++) {
        dp.at(i) += dp.at(i - 1);
    }

    vector<ll> ans(N + 1);

    for(ll i = 1; i < (ll)pos.size(); i++) {
        ans.at(dp.at(i - 1)) += (pos.at(i) - pos.at(i - 1));
    }

    for(ll i = 1; i <= N; i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}