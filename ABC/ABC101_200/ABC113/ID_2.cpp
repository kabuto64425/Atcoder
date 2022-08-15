#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

ll digNum(ll n) {
    ll res = 0;
    while(n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<tuple<ll, ll, ll, string>> PY(M);
    for(ll i = 0; i < M; i++) {
        auto &elm = PY[i];
        get<0>(elm) = i;
        cin >> get<1>(elm) >> get<2>(elm);
    }
    auto comp1 = [](tuple<ll, ll, ll, string> a, tuple<ll, ll, ll, string> b) {
        if(get<1>(a) == get<1>(b)) {
            return get<2>(a) < get<2>(b);
        }
        return get<1>(a) < get<1>(b);
    };
    sort(PY.begin(), PY.end(), comp1);
    ll birth = 1;
    ll pref = 0;
    for(ll i = 0; i < M; i++) {
        auto &elm = PY[i];
        if(pref != get<1>(elm)) {
            birth = 1;
            pref = get<1>(elm);
        }
        string S = "";
        for(ll j = 0; j < 6 - digNum(pref); j++) {
            S += "0";
        }
        S += to_string(pref);
        for(ll j = 0; j < 6 - digNum(birth); j++) {
            S += "0";
        }
        S += to_string(birth);
        get<3>(elm) = S;
        birth++;
    }
    sort(PY.begin(), PY.end());
    for(const auto &elm : PY) {
        cout << get<3>(elm) << endl;
    }
    return 0;
}