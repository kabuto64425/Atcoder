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

ll recur(ll h, ll w, const ll H, const ll W, const vector<string> &A, vector<vector<ll>> &memo) {
    if(abs(memo.at(h).at(w)) != INF) {
        return memo.at(h).at(w);
    }
    
    if((h + w) % 2 == 0) {
        ll ret = -INF;
        if(h + 1 < H) {
            chmax(ret, recur(h + 1, w, H, W, A, memo) + ((A.at(h + 1).at(w) == '+')? 1 : -1));
        }
        if(w + 1 < W) {
            chmax(ret, recur(h, w + 1, H, W, A, memo) + ((A.at(h).at(w + 1) == '+')? 1 : -1));
        }
        memo.at(h).at(w) = ret;
        return ret;
    } else {
        ll ret = INF;
        if(h + 1 < H) {
            chmin(ret, recur(h + 1, w, H, W, A, memo) + ((A.at(h + 1).at(w) == '+')? -1 : 1));
        }
        if(w + 1 < W) {
            chmin(ret, recur(h, w + 1, H, W, A, memo) + ((A.at(h).at(w + 1) == '+')? -1 : 1));
        }
        memo.at(h).at(w) = ret;
        return ret;
    }
}

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> A(H);
    for(ll i = 0; i < H; i++) {
        cin >> A.at(i);
    }
    vector<vector<ll>> memo(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if((i + j) % 2 == 0) {
                memo.at(i).at(j) = -INF;
            } else {
                memo.at(i).at(j) = INF;
            }
        }
    }
    memo.at(H - 1).at(W - 1) = 0;
    ll res = recur(0, 0, H, W, A, memo);
    if(res > 0) {
        cout << "Takahashi" << endl;
        return 0;
    } else if(res == 0) {
        cout << "Draw" << endl;
        return 0;
    } else {
        cout << "Aoki" << endl;
        return 0;
    }
    return 0;
}