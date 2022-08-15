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
    vector<ll> t(N + 1), y(N + 1);
    t.at(0) = 1, y.at(0) = 0;
    for(ll i = 1; i < N + 1; i++) {
        cin >> t.at(i) >> y.at(i);
    }
    ll ans = -INF;
    reverse(ALL(t));
    reverse(ALL(y));
    priority_queue<ll> pq;
    ll sum = 0;
    for(ll i = 0; i < N + 1; i++) {
        if(t.at(i) == 1) {
            ans = max(ans, y.at(i) + sum);
            if(K == 0) {
                break;
            }
            if((ll)pq.size() == K) {
                sum += pq.top();
                pq.pop();
            }
            K--;
        } else {
            if(y.at(i) < 0) {
                pq.push(y.at(i));
                if((ll)pq.size() > K) {
                    sum += pq.top();
                    pq.pop();
                }
            } else {
                sum += y.at(i);
            }
        }
    }

    cout << ans << endl;

    return 0;
}