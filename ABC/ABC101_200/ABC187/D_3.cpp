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
    vector<tuple<ll, ll, ll>> AB(N);
    for(ll i = 0; i < N; i++) {
        ll A, B;
        cin >> A >> B;
        get<0>(AB.at(i)) = -2 * A - B;
        get<1>(AB.at(i)) = A;
        get<2>(AB.at(i)) = B;
    }
    sort(ALL(AB));
    ll aoki = 0;
    for(ll i = 0; i < N; i++) {
        aoki += get<1>(AB.at(i));
    }
    ll takahashi = 0;
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        aoki -= get<1>(AB.at(i));
        takahashi += get<1>(AB.at(i)) + get<2>(AB.at(i));
        ans++;
        if(takahashi > aoki) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}