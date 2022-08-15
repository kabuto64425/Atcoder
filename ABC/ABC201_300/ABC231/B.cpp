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
    ll N;
    cin >> N;
    map<string, ll> m;
    for(ll i = 0; i < N; i++) {
        string S;
        cin >> S;
        m[S]++;
    }
    ll ma = 0;
    string ans;
    for(auto a : m) {
        if(a.second > ma) {
            ma = a.second;
            ans = a.first;
        }
    }
    cout << ans << endl;
    return 0;
}