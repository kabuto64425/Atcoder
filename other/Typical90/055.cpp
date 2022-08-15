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

void dfs(vector<ll> &V, const ll &N, const vector<ll> &A, const ll &P, const ll &Q, ll &ans) {
    // 数列の長さが N に達したら打ち切り
    if (V.size() == 5) {
        // 処理
        ll current = 1;
        for(ll i = 0; i < 5; i++) {
            current *= A.at(V.at(i));
            current %= P;
        }
        if(current == Q) {
            ans++;
        }
        return;
    }

    int prev_last = (V.empty() ? -1 : V.back());
    for (int i = prev_last + 1; i < N; ++i) {
        V.push_back(i);
        dfs(V, N, A, P, Q, ans);
        V.pop_back();
    }
}

int main(){
    ll N, P, Q;
    cin >> N >> P >> Q;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll ans = 0;
    vector<ll> V;
    dfs(V, N, A, P, Q, ans);
    cout << ans << endl;
    return 0;
}