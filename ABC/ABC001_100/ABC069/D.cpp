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
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    vector<vector<ll>> c(H, vector<ll>(W));
    ll currentColor = 0;
    for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++) {
        a.at(currentColor)--;
        c.at(i).at(j) = currentColor;
        if(a.at(currentColor) <= 0) {
            currentColor++;
        }
    }
    for(ll i = 0; i < H; i++) {
        if(i % 2 == 0) {
            reverse(ALL(c.at(i)));
        }
    }
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            cout << c.at(i).at(j) + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}