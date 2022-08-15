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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    vector<ll> t(Q);
    vector<ll> q1(Q);
    vector<char> q2(Q);
    vector<ll> l(Q), r(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> t.at(i);
        if(t.at(i) == 1) {
            cin >> q1.at(i) >> q2.at(i);
        } else {
            cin >> l.at(i) >> r.at(i);
        }
    }

    map<char, set<ll>> m;
    for(ll i = 0; i < N; i++) {
        m[S.at(i)].insert(i + 1);
    }

    for(ll i = 0; i < Q; i++) {
        if(t.at(i) == 1) {
            char c = S.at(q1.at(i) - 1);
            m[c].erase(q1.at(i));
            m[q2.at(i)].insert(q1.at(i));
            S.at(q1.at(i) - 1) = q2.at(i);
        } else{
            ll ans = 0;
            for(char c = 'a'; c <= 'z'; c++) {
                set<ll> &se = m[c];
                auto rite = se.upper_bound(r.at(i));
                auto lite = se.lower_bound(l.at(i));
                if(rite != lite) {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}