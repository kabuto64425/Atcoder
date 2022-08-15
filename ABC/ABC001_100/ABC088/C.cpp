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

int main(){
    vector<vector<ll>> c(3, vector<ll>(3));
    for(ll i = 0; i < 3; i++) {
        for(ll j = 0; j < 3; j++) {
            cin >> c.at(i).at(j);
        }
    }
    for(ll i = 0; i < 3; i++) {
        for(ll j = i + 1; j < 3; j++) {
            ll x = c.at(j).at(0) - c.at(i).at(0);
            ll y = c.at(j).at(1) - c.at(i).at(1);
            ll z = c.at(j).at(2) - c.at(i).at(2);
            if(x != y or x != z) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    for(ll i = 0; i < 3; i++) {
        for(ll j = i + 1; j < 3; j++) {
            ll x = c.at(0).at(j) - c.at(0).at(i);
            ll y = c.at(1).at(j) - c.at(1).at(i);
            ll z = c.at(2).at(j) - c.at(2).at(i);
            if(x != y or x != z) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}