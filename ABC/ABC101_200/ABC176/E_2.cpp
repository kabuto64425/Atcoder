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
    ll H, W, M;
    cin >> H >> W >> M;
    vector<ll> h(M), w(M);
    for(ll i = 0; i < M; i++) {
        cin >> h.at(i) >> w.at(i);
    }
    vector<set<ll>> rowcounts(H + 1);
    vector<set<ll>> columncounts(W + 1);
    set<pair<ll, ll>> sp;
    for(ll i = 0; i < M; i++) {
        rowcounts.at(h.at(i)).insert(w.at(i));
        columncounts.at(w.at(i)).insert(h.at(i));
        sp.insert({h.at(i), w.at(i)});
    }
    ll rowmax = 0;
    for(ll i = 1; i <= H; i++) {
        chmax(rowmax, (ll)rowcounts.at(i).size());
    }
    ll columnmax = 0;
    for(ll i = 1; i <= W; i++) {
        chmax(columnmax, (ll)columncounts.at(i).size());
    }

    set<ll> rowmaxinfo;
    for(ll i = 1; i <= H; i++) {
        if(rowmax == (ll)rowcounts.at(i).size()) {
            rowmaxinfo.insert(i);
        }
    }

    set<ll> columnmaxinfo;
    for(ll i = 1; i <= W; i++) {
        if(columnmax == (ll)columncounts.at(i).size()) {
            columnmaxinfo.insert(i);
        }
    }

    ll crosscounts = (ll)(rowmaxinfo.size() * columnmaxinfo.size());

    for(ll i = 0; i < M; i++) {
        if(rowmaxinfo.count(h.at(i)) and columnmaxinfo.count(w.at(i))) {
            crosscounts--;
        }
    }

    ll ans = rowmax + columnmax;
    if(crosscounts <= 0) {
        ans--;
    }

    cout << ans << endl;
    return 0;
}