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

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    sort(ALL(A));
    vector<bool> v(1000001, true);
    map<ll, ll> m;
    for(ll i = 0; i < N; i++) {
        m[A.at(i)]++;
        if(!v.at(A.at(i))) {
            continue;
        }
        if(m[A.at(i)] >= 2) {
            continue;
        }
        ll x = A.at(i);
        for(ll y = x * 2; y <= 1000000; y += x) {
            v.at(y) = false;
        }
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(v.at(A.at(i)) and m[A.at(i)] == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}