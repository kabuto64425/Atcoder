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
    vector<ll> bucket(220000, 0);
    for(ll i = 0; i < N; i++) {
        bucket.at(A.at(i))++;
    }
    ll count = 0;
    for(ll i = 1; i <= 200000; i++) {
        if(bucket.at(i) >= 1) {
            count++;
        }
    }
    /*if(count <= 2) {
        cout << 0 << endl;
        return 0;
    }*/
    ll minus = 0;
    for(ll i = 1; i <= 200000; i++) {
        if(bucket.at(i) >= 2) {
            ll current = bucket.at(i) * (bucket.at(i) - 1) / 2;
            minus += current * (N - bucket.at(i));
        }
        if(bucket.at(i) >= 3) {
            minus += bucket.at(i) * (bucket.at(i) - 1) * (bucket.at(i) - 2) / 6;
        }
    }
    ll ans = N * (N - 1) * (N - 2) / 6;
    ans -= minus;
    cout << ans << endl;
    return 0;
}