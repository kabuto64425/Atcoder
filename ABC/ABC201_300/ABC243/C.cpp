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
    vector<ll> X(N), Y(N);
    for(ll i = 0; i < N; i++) {
        cin >> X.at(i) >> Y.at(i);
    }
    string S;
    cin >> S;
    map<ll, set<pair<ll, ll>>> m;
    for(ll i = 0; i < N; i++) {
        set<pair<ll, ll>> &s = m[Y.at(i)];
        ll d = ((S.at(i) == 'R') ? 1 : 0);
        s.insert({X.at(i), d});
    }
    for(const pair<ll, set<pair<ll, ll>>> &s : m) {
        bool flag = false;
        for(pair<ll, ll> p : s.second) {
            if(p.second == 1) {
                flag = true;
            } else if(p.second == 0) {
                if(flag) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}