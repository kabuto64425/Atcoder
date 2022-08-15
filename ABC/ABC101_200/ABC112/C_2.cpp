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
    vector<ll> x(N), y(N), h(N);
    for(ll i = 0; i < N ; i++) {
        cin >> x.at(i) >> y.at(i) >> h.at(i);
    }
    for(ll cx = 0; cx <= 100; cx++) {
        for(ll cy = 0; cy <= 100; cy++) {
            ll ansH = INF;
            for(ll i = 0; i < N; i++) {
                ansH = min(ansH, h.at(i) + abs(x.at(i) - cx) + abs(y.at(i) - cy));
            }
            bool flag = true;
            for(ll i = 0; i < N; i++) {
                ll hi = max(ansH - abs(x.at(i) - cx) - abs(y.at(i) - cy), 0LL);
                if(hi != h.at(i)) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << cx << " " << cy << " " << ansH << endl;
                return 0;
            }
        }
    }
    return 0;
}