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
    ll N, M, T;
    cin >> N >> M >> T;
    vector<pair<ll, ll>> AB(M);
    for(pair<ll, ll> &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    ll battery = N;
    for(ll i = 0; i < M; i++) {
        if(i == 0) {
            battery -= AB.at(i).first;
        } else {
            battery -= (AB.at(i).first - AB.at(i - 1).second);
        }
        if(battery <= 0) {
            cout << "No" << endl;
            return 0;
        }
        battery = min(N, battery + AB.at(i).second - AB.at(i).first);
    }
    battery -= T - AB.at(M - 1).second;
    if(battery > 0) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}