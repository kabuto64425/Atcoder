#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> xy(N);
    for(pair<ll, ll> &elm : xy) {
        cin >> elm.first >> elm.second;
    }
    
    vector<pair<ll, ll>> rotatedxy(N);
    for(ll i = 0; i < N; i++) {
        rotatedxy.at(i).first = xy.at(i).first - xy.at(i).second;
        rotatedxy.at(i).second = xy.at(i).first + xy.at(i).second;
    }
    
    ll minX = INF;
    ll maxX = -INF;
    ll minY = INF;
    ll maxY = -INF;
    for(ll i = 0; i < N; i++) {
        minX = min(minX, rotatedxy.at(i).first);
        maxX = max(maxX, rotatedxy.at(i).first);
        minY = min(minY, rotatedxy.at(i).second);
        maxY = max(maxY, rotatedxy.at(i).second);
    }

    cout << max(abs(maxX - minX), abs(maxY - minY)) << endl;
    return 0;
}