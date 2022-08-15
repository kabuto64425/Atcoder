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
    for(ll i = 0; i < M ; i++) {
        cin >> h.at(i) >> w.at(i);
    }
    vector<ll> rcount(H + 1, 0);
    for(ll i = 1; i <= M; i++) {
        rcount.at(h.at(i - 1))++;
    }
    vector<ll> ccount(W + 1, 0);
    for(ll i = 1; i <= M; i++) {
        ccount.at(w.at(i - 1))++;
    }

    ll rowmax = 0;
    for(ll i = 1; i <= H; i++) {
        chmax(rowmax, rcount.at(i));
    }

    ll columnmax = 0;
    for(ll i = 1; i <= W; i++) {
        chmax(columnmax, ccount.at(i));
    }

    set<ll> maxrownums;
    for(ll i = 1; i <= H; i++) {
        if(rcount.at(i) == rowmax) {
            maxrownums.insert(i);
        }
    }

    set<ll> maxcolumnnums;
    for(ll i = 1; i <= W; i++) {
        if(ccount.at(i) == columnmax) {
            maxcolumnnums.insert(i);
        }
    }

    ll crosscounts = maxrownums.size() * maxcolumnnums.size();

    for(ll i = 0; i < M; i++) {
        if(maxrownums.count(h.at(i)) and maxcolumnnums.count(w.at(i))) {
            crosscounts--;
        }
    }
    if(crosscounts > 0) {
        cout << rowmax + columnmax << endl;
    } else {
        cout << rowmax + columnmax - 1 << endl;
    }
    return 0;
}