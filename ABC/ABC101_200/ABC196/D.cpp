#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

ll recur(ll y, ll x, const vector<vector<bool>> &vec, ll A, ll B) {
    ll H = vec.size();
    ll W = vec.at(0).size();
    if(y == H - 1 and x == W - 1) {
        return 1;
    }
    if(vec.at(y).at(x)) {
        return recur(y + (x + 1) / W, (x + 1) % W, vec, A, B);
    }
    ll res = 0;
    if(B > 0) {
        vector<vector<bool>> copied = vec;
        copied.at(y).at(x) = true;
        res += recur(y + (x + 1) / W, (x + 1) % W, copied, A, B - 1);
    }
    if(A > 0 and x <= W - 2 and !vec.at(y).at(x + 1)) {
        vector<vector<bool>> copied = vec;
        copied.at(y).at(x) = true;
        copied.at(y).at(x + 1) = true;
        res += recur(y + (x + 1) / W, (x + 1) % W, copied, A - 1, B);
    }
    if(A > 0 and y <= H - 2 and !vec.at(y + 1).at(x)) {
        vector<vector<bool>> copied = vec;
        copied.at(y).at(x) = true;
        copied.at(y + 1).at(x) = true;
        res += recur(y + (x + 1) / W, (x + 1) % W, copied, A - 1, B);
    }
    return res;
}

int main(){
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    vector<vector<bool>> vec(H, vector<bool>(W, false));
    cout << recur(0, 0, vec, A, B) << endl;
    return 0;
}