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

void dfs(ll N, ll R, ll cur, vector<ll> &vec) {
    if((ll)vec.size() == R) {
        // vecを使った処理を書く
        return;
    }
    for(ll i = cur; i < N; i++) {
        vec.push_back(i);
        dfs(N, R, i, vec);
        vec.pop_back();
    }
}

void dfs2(ll N, ll R, ll cur, vector<ll> &vec) {
    if((ll)vec.size() == R) {
        // vecを使った処理を書く
        return;
    }
    if((ll)vec.size() + (N - cur) < R) {
        // 見込みなしと判断
        return;
    }
    for(ll i = cur + 1; i < N; i++) {
        vec.push_back(i);
        dfs2(N, R, i, vec);
        vec.pop_back();
    }
}

void dfs3(ll N, ll R, vector<ll> &vec, set<ll> &s) {
    if((ll)vec.size() == R) {
        // vecを使った処理を書く
        return;
    }
    for(ll elm : s) {
        vec.push_back(elm);
        s.erase(elm);
        dfs3(N, R, vec, s);
        s.insert(elm);
        vec.pop_back();
    }
}

int main(){
    ll N, R;
    cin >> N >> R;
    vector<ll> vec;
    dfs(N, R, 0, vec);
    // 関数内部で最初に+1されるので、初期値は-1にしておく
    dfs2(N, R, -1, vec);
    set<ll> s;
    for(ll i = 0; i < N; i++) {
        s.insert(i);
    }
    dfs3(N, R, vec, s);
    return 0;
}