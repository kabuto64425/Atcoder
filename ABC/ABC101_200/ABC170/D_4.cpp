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
    vector<bool> v(1100000);
    vector<ll> bucket(1100000);
    for(ll i = 0; i < N; i++) {
        v.at(A.at(i)) = true;
        bucket.at(A.at(i))++;
    }
    for(ll i = 1; i <= 1000000; i++) if(v.at(i)) {
        for(ll j = i * 2; j <= 1000000; j += i) {
            v.at(j) = false;
        }
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(v.at(A.at(i)) and bucket.at(A.at(i)) == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}