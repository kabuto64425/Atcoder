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
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    for(ll i = 0; i < N; i++) {
        cin >> P.at(i);
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(ll i = 0; i < K; i++) {
        pq.push(P.at(i));
    }
    cout << pq.top() << endl;
    for(ll i = K; i < N; i++) {
        ll t = pq.top();
        if(P.at(i) > t) {
            pq.pop();
            pq.push(P.at(i));
            t = pq.top();
        }
        cout << t << endl;
    }
    return 0;
}