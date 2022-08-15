#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> p;
    for(ll bit = 0; bit < (1 << (N + 1) / 2); bit++) {
        ll x = 0;
        for(ll i = 0; i < (N + 1) / 2; i++) {
            if(bit & (1 << i)) {
                x += A.at(i);
            }
        }
        p.push_back(x);
    }
    sort(p.begin(), p.end());
    vector<ll> q;
    for(ll bit = 0; bit < (1 << N / 2); bit++) {
        ll x = 0;
        for(ll i = 0; i < N / 2; i++) {
            if(bit & (1 << i)) {
                x += A.at((N + 1) / 2 + i);
            }
        }
        q.push_back(x);
    }
    sort(q.begin(), q.end());
    ll ans = 0;
    for(ll i = 0; i < p.size(); i++) {
        ll t1 = p.at(i);
        if(t1 > T) {
            continue;
        }
        ll index = upper_bound(q.begin(), q.end(), T - t1) - q.begin();
        ll t2 = q.at(index -1);
        ans = max(ans, t1 + t2);
    }
    cout << ans << endl;
    return 0;
}