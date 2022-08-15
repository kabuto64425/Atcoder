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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    vector<vector<ll>> v(110000);
    for(ll i = 0; i < N; i++) {
        v.at(A.at(i)).push_back(B.at(i));
    }
    priority_queue<ll, vector<ll>, less<ll>> pq;
    ll ans = 0;
    for(ll i = 0; i <= M; i++) {
        for(ll b : v.at(i)) {
            pq.push(b);
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}