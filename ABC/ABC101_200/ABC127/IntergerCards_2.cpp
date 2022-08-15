#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first > b.first;
    }
}

signed main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A.at(i);
    }
    vector<pair<ll, ll>> BC(M);
    REP(i, M) {
        cin >> BC.at(i).first >> BC.at(i).second;
    }

    sort(A.begin(), A.end());
    sort(BC.begin(), BC.end(), compare_by_b);

    ll j = 0;
    ll k = 0;
    ll ans = 0;
    FOR(i, 1, N) {
        if(j < BC.size()) {
            ans += max(A.at(i - 1), BC.at(j).second);
        } else {
            ans += A.at(i - 1);
        }
        
        if(j < BC.size() && BC.at(j).first <= (i - k)) {
            j++;
            k = i;
        }
    }
    cout << ans << endl;
}