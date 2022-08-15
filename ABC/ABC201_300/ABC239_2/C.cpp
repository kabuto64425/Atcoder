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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

vector<pair<ll, ll>> d = {
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2},
};

int main(){
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<pair<ll, ll>> v1(8);
    for(ll i = 0; i < 8; i++) {
        v1.at(i) = {x1 + d.at(i).first, y1 + d.at(i).second};
    }
     vector<pair<ll, ll>> v2(8);
    for(ll i = 0; i < 8; i++) {
        v2.at(i) = {x2 + d.at(i).first, y2 + d.at(i).second};
    }
    for(ll i = 0; i < 8; i++) for(ll j = 0; j < 8; j++) {
        if(v1.at(i) == v2.at(j)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}