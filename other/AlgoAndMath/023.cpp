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
    vector<ll> B(N), R(N);
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    for(ll i = 0; i < N; i++) {
        cin >> R.at(i);
    }
    vector<ll> bucketB(101);
    vector<ll> bucketR(101);
    for(ll i = 0; i < N; i++) {
        bucketB.at(B.at(i))++;
    }
    for(ll i = 0; i < N; i++) {
        bucketR.at(R.at(i))++;
    }
    ll denominator = 0;
    for(ll i = 0; i <= 100; i++) for(ll j = 0; j <= 100; j++) {
        denominator += bucketB.at(i) * bucketR.at(j) * (i + j);
    }
    cout << fixed << setprecision(20) << (denominator / (long double)(N * N)) << endl;
    return 0;
}