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

void dfs(ll N,const vector<vector<ll>> &A, ll rest, ll &ans, set<ll> &used, vector<ll> &vec) {
    if(rest == 0) {
        ll current = 0;
        for(ll i = 0; i < N; i++) {
            current = current ^ A.at(vec.at(i * 2)).at(vec.at(i * 2 + 1));
        }
        ans = max(ans, current);
        return;
    }
    if(rest % 2 == 0) {
        ll i = 0;
        while(used.count(i)) {
            i++;
        }
        used.insert(i);
        vec.push_back(i);
        dfs(N, A, rest - 1, ans, used, vec);
        used.erase(i);
        vec.pop_back();
    } else {
        for(ll i = 0; i < N * 2; i++) {
            if(used.count(i)) {
                continue;
            }
            used.insert(i);
            vec.push_back(i);
            dfs(N, A, rest - 1, ans, used, vec);
            used.erase(i);
            vec.pop_back();
        }
    }
}

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(2 * N, vector<ll>(2 * N));
    for(ll i = 0; i < 2 * N; i++) {
        for(ll j = i + 1; j < 2 * N; j++) {
            cin >> A.at(i).at(j);
        }
    }
    ll ans = 0;
    set<ll> used;
    vector<ll> vec;
    dfs(N, A, N * 2, ans, used, vec);
    cout << ans << endl;
    return 0;
}