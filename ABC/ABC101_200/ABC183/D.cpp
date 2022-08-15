#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, W;
    cin >> N >> W;
    vector<tuple<ll, ll, ll>> stp(N);
    for(auto &elm : stp) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }
    vector<ll> vec(200002, 0);
    REP(i, N) {
        vec.at(get<0>(stp.at(i))) += get<2>(stp.at(i));
        vec.at(get<1>(stp.at(i))) -= get<2>(stp.at(i));
    }
    ll current = 0;
    REP(i, 200001) {
        current += vec.at(i);
        if(current > W) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}