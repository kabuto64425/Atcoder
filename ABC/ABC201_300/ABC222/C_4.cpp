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
    vector<string> S(2 * N);
    for(ll i = 0; i < 2 * N; i++) {
        cin >> S.at(i);
    }
    map<char, ll> m;
    m['G'] = 0;
    m['C'] = 1;
    m['P'] = 2;
    vector<pair<ll, ll>> jun(2 * N);
    for(ll i = 0; i < 2 * N; i++) {
        jun.at(i).second = i;
    }
    for(ll i = 0; i < M; i++) {
        sort(ALL(jun));
        for(ll j = 0; j < N; j++) {
            ll x = jun.at(j * 2).second;
            ll y = jun.at(j * 2 + 1).second;
            ll xt = m[S.at(x).at(i)];
            ll yt = m[S.at(y).at(i)];
            if((xt - yt + 3) % 3 == 2) {
                jun.at(j * 2).first -= 1;
            }
            if((xt - yt + 3) % 3 == 1) {
                jun.at(j * 2 + 1).first -= 1;
            }
        }
    }
    sort(ALL(jun));
    for(ll i = 0; i < 2 * N; i++) {
        cout << jun.at(i).second + 1 << endl;
    }
    return 0;
}