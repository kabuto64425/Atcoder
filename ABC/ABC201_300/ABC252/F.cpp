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
    ll N, L;
    cin >> N >> L;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    ll x = L - accumulate(ALL(A), 0LL);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(ll i = 0; i < N; i++) {
        pq.push(A.at(i));
    }
    if(x > 0) {
        pq.push(x);
    }
    ll ans = 0;
    while(pq.size() >= 2) {
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();
        ans += (x + y);
        pq.push(x + y);
    }
    cout << ans << endl;
    return 0;
}