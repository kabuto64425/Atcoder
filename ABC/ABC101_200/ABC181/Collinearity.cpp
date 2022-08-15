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
    ll N;
    cin >> N;
    vector<pair<ll, ll>> xy(N);
    for(auto &elm : xy) {
        cin >> elm.first >> elm.second;
    }
    FOR(i, 0, N - 3) {
        FOR(j, i + 1, N - 2) {
            FOR(k, j + 1, N - 1) {
                pair<ll, ll> a = xy.at(i);
                pair<ll, ll> b = xy.at(j);
                pair<ll, ll> c = xy.at(k);
                
                pair<ll, ll> v1 = {a.first - c.first, a.second - c.second};
                pair<ll, ll> v2 = {b.first - c.first, b.second - c.second};
                if(v1.first * v2.second == v1.second * v2.first) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}