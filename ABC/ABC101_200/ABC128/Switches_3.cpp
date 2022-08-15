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
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, vector<ll>>> ks(M);
    for(auto &elm : ks) {
        ll f;
        cin >> f;
        elm.first = f;
        vector<ll> s(f);
        for(auto &e : s) {
            cin >> e;
        }
        elm.second = s;
    }
    vector<ll> p(M);
    for(auto &elm : p) {
        cin >> elm;
    }
    ll ans = 0;
    for(ll bit = 0; bit < (1 << N); bit++) {
        vector val(M, 0);
        for(ll i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                for(ll j = 0; j < M; j++) {
                    if(count(ks.at(j).second.begin(), ks.at(j).second.end(), i + 1)) {
                        val.at(j)++;
                    }
                }
            }
        }
        bool flag = true;
        for(ll j = 0; j < M; j++) {
            if(val.at(j) % 2 != p.at(j)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}