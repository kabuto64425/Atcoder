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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(ll i = 0; i < H; i++) {
        cin >> S.at(i);
    }
    vector<vector<bool>> v(H, vector<bool>(W, false));
    for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++) {
        if(i <= H - 2) {
            if(S.at(i).at(j) == '#' and S.at(i + 1).at(j) == '#') {
                v.at(i).at(j) = true;
                v.at(i + 1).at(j) = true;
            }
        }
        if(j <= W - 2) {
            if(S.at(i).at(j) == '#' and S.at(i).at(j + 1) == '#') {
                v.at(i).at(j) = true;
                v.at(i).at(j + 1) = true;
            }
        }
    }
    for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++) {
        if(S.at(i).at(j) == '#') {
            if(!v.at(i).at(j)) {
                cout << "No" << endl;
                return 0;
            }
        }
        if(S.at(i).at(j) == '.') {
            if(v.at(i).at(j)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}