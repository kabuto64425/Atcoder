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

vector<pair<ll, ll>> d = {
    {1, 0},
    {0, -1},
    {-1, 0},
    {0, 1}
};

int main(){
    ll N;
    string T;
    cin >> N;
    cin >> T;
    pair<ll, ll> ans = {0, 0};
    ll x = 0;
    for(ll i = 0; i < N; i++) {
        if(T.at(i) == 'S') {
            ans.first += d.at(x).first;
            ans.second += d.at(x).second;
        }
        if(T.at(i) == 'R') {
            x = (x + 1) % 4;
        }
    }

    cout << ans.first << " " << ans.second << endl;

    return 0;
}