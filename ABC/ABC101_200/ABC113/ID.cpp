#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

bool compare_by_first(tuple<ll, ll, ll, ll> a, tuple<ll, ll, ll, ll> b) {
    if(get<0>(a) != get<0>(b)){
        return get<0>(a) < get<0>(b);
    }else{
        return get<1>(a) < get<1>(b);
    }
}

bool compare_by_second(tuple<ll, ll, ll, ll> a, tuple<ll, ll, ll, ll> b) {
    return get<3>(a) < get<3>(b);
}

signed main(){
    ll N, M;
    cin >> N >> M;
    vector<tuple<ll, ll, ll, ll>> PY(M);
    REP(i, M) {
        cin >> get<0>(PY.at(i)) >> get<1>(PY.at(i));
        get<3>(PY.at(i)) = i;
    }
    sort(PY.begin(), PY.end(), compare_by_first);
    ll secondId = 1;
    REP(i, M) {
        if(i > 0 && get<0>(PY.at(i)) != get<0>(PY.at(i - 1))) {
            secondId = 1;
        }
        get<2>(PY.at(i)) = secondId;
        secondId++;
    }
    sort(PY.begin(), PY.end(), compare_by_second);
    REP(i, M) {
        cout << setfill('0') << right << setw(6) << get<0>(PY.at(i)) << setfill('0') << right << setw(6) << get<2>(PY.at(i)) << endl;
    }
}