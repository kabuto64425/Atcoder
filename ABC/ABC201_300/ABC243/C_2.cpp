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
    // Rの最小, Lの最大
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for(ll i = 0; i < N; i++) {
        cin >> X.at(i) >> Y.at(i);
    }
    string S;
    cin >> S;
    map<ll, ll> map1;
    map<ll, ll> map2;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) == 'L') {
            if(map1.count(Y.at(i))) {
                map1[Y.at(i)] = max(map1[Y.at(i)], X.at(i));
            } else {
                map1[Y.at(i)] = X.at(i);
            }
        }
        if(S.at(i) == 'R') {
            if(map2.count(Y.at(i))) {
                map2[Y.at(i)] = min(map2[Y.at(i)], X.at(i));
            } else {
                map2[Y.at(i)] = X.at(i);
            }
        }
    }
    for(pair<ll, ll> p : map1) {
        if(map2.count(p.first)) {
            ll l = p.second;
            ll r = map2[p.first];
            if(r < l) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}