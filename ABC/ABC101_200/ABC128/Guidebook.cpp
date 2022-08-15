#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

bool compare_by_tuple(tuple<string, ll, ll> a, tuple<string, ll, ll> b) {
    if(get<0>(a) != get<0>(b)) {
        return get<0>(a) < get<0>(b);
    } else {
        return get<1>(a) > get<1>(b);
    }
}

signed main(){
    ll N;
    cin >> N;
    vector<tuple<string, ll, ll>> SP(N);
    REP(i, N) {
        cin >> get<0>(SP.at(i)) >> get<1>(SP.at(i));
        get<2>(SP.at(i)) = i + 1;
    }
    sort(SP.begin(), SP.end(), compare_by_tuple);
    REP(i, N) {
        cout << get<2>(SP.at(i)) << endl;
    }
}