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
    ll N, K;
    cin >> N >> K;
    vector<ll> V(N);
    for(ll i = 0; i < N; i++) {
        cin >> V.at(i);
    }
    ll ans = 0;
    for(ll left = 0; left <= K; left++) for(ll right = 0; right <= K - left; right++) {
        ll current = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll rest = K - left - right;
        if(right + left > N) {
            continue;
        }
        for(ll i = 0; i < left; i++) {
            if(V.at(i) >= 0) {
                current += V.at(i);
            } else {
                pq.push(V.at(i));
            }
        }
        for(ll i = 0; i < right; i++) {
            if(V.at(N - i - 1) >= 0) {
                current += V.at(N - i - 1);
            } else {
                pq.push(V.at(N - i - 1));
            }
        }
        for(ll i = 0; i < rest and !pq.empty(); i++) {
            pq.pop();
        }
        while(!pq.empty()) {
            current += pq.top();
            pq.pop();
        }

        chmax(ans, current);
    }
    cout << ans << endl;
    return 0;
}