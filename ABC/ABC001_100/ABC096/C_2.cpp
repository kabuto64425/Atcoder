#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(string &s : S) {
        cin >> s;
    }
    dsu d(H * W);
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(S.at(i).at(j) == '#') {
                if(i >= 1 and S.at(i - 1).at(j) == '#') {
                    d.merge(i * W + j, (i - 1) * W + j);
                }

                if(i <= H - 2 and S.at(i + 1).at(j) == '#') {
                    d.merge(i * W + j, (i + 1) * W + j);
                }

                if(j >= 1 and S.at(i).at(j - 1) == '#') {
                    d.merge(i * W + j, i * W + (j - 1));
                }

                if(j <= W - 2 and S.at(i).at(j + 1) == '#') {
                    d.merge(i * W + j, i * W + (j + 1));
                }
            }
        }
    }
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(S.at(i).at(j) == '#') {
                if(d.size(i * W + j) == 1) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}