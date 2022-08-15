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
    vector<ll> W(N);
    for(ll i = 0; i < N; i++) {
        cin >> W.at(i);
    }
    vector<ll> cs;
    vector<ll> as;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) == '0') {
            cs.push_back(W.at(i));
        } else {
            as.push_back(W.at(i));
        }
    }
    sort(ALL(cs));
    sort(ALL(as));
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ll count1 = lower_bound(ALL(cs), W.at(i)) - cs.begin();
        ll count2 = lower_bound(ALL(as), W.at(i)) - as.begin();
        chmax(ans, count1 + ((ll)as.size() - count2));
    }
    ll count1 = lower_bound(ALL(cs), INF) - cs.begin();
    ll count2 = lower_bound(ALL(as), INF) - as.begin();
    chmax(ans, count1 + ((ll)as.size() - count2));
    cout << ans << endl;
    return 0;
}