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
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    stack<pair<ll, ll>> s;
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(s.empty()) {
            s.push({a.at(i), 1});
            ans++;
            cout << ans << endl;
            continue;
        }
        pair<ll, ll> current = s.top();
        if(a.at(i) != current.first) {
            s.push({a.at(i), 1});
            ans++;
            cout << ans << endl;
        } else {
            current.second++;
            ans++;
            if(current.second == current.first) {
                s.pop();
                ans -= current.second;
            } else {
                s.pop();
                s.push({current.first, current.second});
            }
            cout << ans << endl;
        }
    }
    return 0;
}