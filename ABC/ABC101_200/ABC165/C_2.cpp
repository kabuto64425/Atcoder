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

void dfs(const ll N, const ll M, const ll Q, const vector<ll> &a, const vector<ll> &b, const vector<ll> &c, const vector<ll> &d, vector<ll> &vec, ll current, ll &ans) {
    if(vec.size() == N) {
        ll score = 0;
        for(ll i = 0; i < Q; i++) {
            ll l = a.at(i) - 1;
            ll r = b.at(i) - 1;
            if(vec.at(r) - vec.at(l) == c.at(i)) {
                score += d.at(i);
            }
        }
        ans = max(ans, score);
        return;
    }
    for(ll i = current; i <= M; i++) {
        vec.push_back(i);
        dfs(N, M, Q, a, b, c, d, vec, i, ans);
        vec.pop_back();
    }
}

int main(){
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> a(Q), b(Q), c(Q), d(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
    }
    ll ans = 0;
    vector<ll> A;
    dfs(N, M, Q, a, b, c, d, A, 1, ans);
    cout << ans << endl;
    return 0;
}