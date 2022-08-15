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

ll solver(ll N, ll K, vector<ll> &A) {
    vector<ll> csum(N + 1);
    for(ll i = 1; i <= N; i++) {
        csum.at(i) = csum.at(i - 1) + A.at(i - 1);
    }
    map<ll, ll> m;
    ll ans = 0;
    for(const ll &c : csum) {
        if(m.count(c - K)) {
            ans += m[c - K];
        }
        m[c]++;
    }
    return ans;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    
    cout << solver(N, K, A) << endl;
    return 0;
}