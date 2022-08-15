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

void dfs(ll H, ll W, vector<ll> &vec, ll a, ll b, ll &ans) {
    if(a == 0 and b == 0) {
        ll current = 0;
        vector<vector<bool>> used(H, vector<bool>(W, false));
        for(ll i = 0; i < H; i++) {
            for(ll j = 0; j < W; j++) {
                if(used.at(i).at(j)) {
                    continue;
                }
                if(vec.at(current) == 0) {
                    if(j >= W - 1) {
                        return;
                    }
                    if(used.at(i).at(j + 1)) {
                        return;
                    }
                    used.at(i).at(j) = true;
                    used.at(i).at(j + 1) = true;
                    current++;
                } else if(vec.at(current) == 1) {
                    if(i >= H - 1) {
                        return;
                    }
                    if(used.at(i + 1).at(j)) {
                        return;
                    }
                    used.at(i).at(j) = true;
                    used.at(i + 1).at(j) = true;
                    current++;
                } else if(vec.at(current) == 2) {
                    used.at(i).at(j) = true;
                    current++;
                }
            }
        }
        if(current == vec.size()) {
            ans++;
        }
        return;
    }
    if(a > 0) {
        vec.push_back(0);
        dfs(H, W, vec, a - 1, b, ans);
        vec.pop_back();
        vec.push_back(1);
        dfs(H, W, vec, a - 1, b, ans);
        vec.pop_back();
    }
    if(b > 0) {
        vec.push_back(2);
        dfs(H, W, vec, a, b - 1, ans);
        vec.pop_back();
    }
}

int main(){
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    vector<vector<bool>> used(H, vector<bool>(W));
    ll ans = 0;
    vector<ll> vec;
    dfs(H, W, vec, A, B, ans);
    cout << ans << endl;
    //dfs(H, W, 0, 0, B, used, ans);
    return 0;
}