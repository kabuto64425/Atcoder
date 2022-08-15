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
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> cm(M);
    for(pair<ll, ll> &elm : cm) {
        cin >> elm.first >> elm.second;
    }
    for(ll i = 0; i <= 999; i++) {
        string str = to_string(i);
        if(str.length() != N) {
            continue;
        }
        bool flag = true;
        for(const pair<ll, ll> &elm : cm) {
           ll num = str.at(elm.first - 1) - '0';
           if(num != elm.second) {
               flag = false;
               break;
           }
        }
        if(flag) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}