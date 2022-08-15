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

int main(){
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> a(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            cin >> a.at(i).at(j);
        }
    }
    ll N = 0;
    vector<ll> x, y, xd, yd;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W - 1; j++) {
            if(a.at(i).at(j) % 2 == 1) {
                a.at(i).at(j)--;
                a.at(i).at(j + 1)++;
                y.push_back(i + 1);
                x.push_back(j + 1);
                yd.push_back(i + 1);
                xd.push_back(j + 2);
                N++;
            }
        }
    }
    for(ll i = 0; i < H - 1; i++) {
        for(ll j = 0; j < W; j++) {
            if(a.at(i).at(j) % 2 == 1) {
                a.at(i).at(j)--;
                a.at(i + 1).at(j)++;
                y.push_back(i + 1);
                x.push_back(j + 1);
                yd.push_back(i + 2);
                xd.push_back(j + 1);
                N++;
            }
        }
    }
    cout << N << endl;
    for(ll i = 0; i < N; i++) {
        cout << y.at(i) << " " << x.at(i) << " " << yd.at(i) << " " << xd.at(i) << endl;
    }
    return 0;
}