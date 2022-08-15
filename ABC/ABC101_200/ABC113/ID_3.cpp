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

bool compare_by_first(tuple<ll, ll, ll, ll> a, tuple<ll, ll, ll, ll> b) {
    if(get<1>(a) == get<1>(b)) {
        return get<2>(a) < get<2>(b);
    }
    return get<1>(a) < get<1>(b);
}

bool compare_by_second(tuple<ll, ll, ll, ll> a, tuple<ll, ll, ll, ll> b) {
    return get<0>(a) < get<0>(b);
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<tuple<ll, ll, ll, ll>> PY(M);
    for(ll i = 0; i < M; i++) {
        tuple<ll, ll, ll, ll> &py = PY[i];
        get<0>(py) = i;
        cin >> get<1>(py);
        cin >> get<2>(py);
    }
    sort(PY.begin(), PY.end(), compare_by_first);
    ll cur = 0;
    for(ll i = 0; i < M; i++) {
        if(i > 0 and get<1>(PY[i - 1]) != get<1>(PY[i])) {
            cur = 0;
        }
        get<3>(PY[i]) = cur;
        cur++;
    }
    sort(PY.begin(), PY.end(), compare_by_second);
    REP(i, M) {
        cout << setfill('0') << right << setw(6) << get<1>(PY[i]) << setfill('0') << right << setw(6) << get<3>(PY[i]) + 1 << endl;
    }
    return 0;
}