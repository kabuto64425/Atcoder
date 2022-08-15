#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
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
    vector<string> C(H);
    for(string &c : C) {
        cin >> c;
    }
    mint count = 0;
    for(ll bit = 0; bit < (1 << (H * W)); bit++) {
        vector<ll> positions;
        for(ll i = 0; i < H * W; i++) {
            if(bit & (1 << i)) {
                ll h = i / W;
                ll w = i % W;
                if(C.at(h).at(w) == '.') {
                    positions.push_back(i);
                }
            }
        }
        bool flag = true;
        for(ll i = 0; i < (ll)positions.size() - 1; i++) {
            for(ll j = i + 1; j < (ll)positions.size(); j++) {
               ll h1 = positions.at(i) / W;
               ll w1 = positions.at(i) % W;
               ll h2 = positions.at(j) / W;
               ll w2 = positions.at(j) % W;
               if(abs(h1 - h2) <= 1 and abs(w1 - w2) <= 1) {
                   flag = false;
                   break;
               }
            }
            if(!flag) {
                break;
            }
        }
        if(flag) {
            count++;
        }
    }
    ll div = 1;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(C.at(i).at(j) == '#') {
                div *= 2;
            }
        }
    }
    count /= div;
    cout << count.val() << endl;
    return 0;
}