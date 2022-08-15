#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

bool solve(const ll mid, const ll N, const vector<tuple<ll, ll, ll, ll, ll>> &ABCDE) {
    
    set<ll> s;
    for(ll i = 0; i < N; i++) {
        tuple<ll, ll, ll, ll, ll> abcde = ABCDE.at(i);
        ll b = 0;
        if(get<0>(abcde) >= mid) {
            b += (1 << 0);
        }
        if(get<1>(abcde) >= mid) {
            b += (1 << 1);
        }
        if(get<2>(abcde) >= mid) {
            b += (1 << 2);
        }
        if(get<3>(abcde) >= mid) {
            b += (1 << 3);
        }
        if(get<4>(abcde) >= mid) {
            b += (1 << 4);
        }
        s.insert(b);
    }
    for(ll x : s) for(ll y : s) for(ll z : s) {
        if((x | y | z) == 31) {
            return true;
        }
    }
    return false;
}

int main(){
    ll N;
    cin >> N;
    vector<tuple<ll, ll, ll, ll, ll>> ABCDE(N);
    for(tuple<ll, ll, ll, ll, ll> &abcde : ABCDE) {
        cin >> get<0>(abcde) >> get<1>(abcde) >> get<2>(abcde) >> get<3>(abcde) >> get<4>(abcde);
    }

    ll ok = 1;
    ll ng = 1000000001;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(mid, N, ABCDE)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;

    return 0;
}