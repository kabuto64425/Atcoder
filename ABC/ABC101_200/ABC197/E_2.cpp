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
    ll N;
    cin >> N;
    vector<pair<ll, ll>> XC(N);
    for(ll i = 0; i < N; i++) {
        cin >> XC.at(i).first >> XC.at(i).second;
    }
    map<ll, vector<ll>> m;
    vector<pair<ll, ll>> CX(N);
    for(ll i = 0; i < N; i++) {
        m[XC.at(i).second].push_back(XC.at(i).first);
        //CX.at(i).first = XC.at(i).second;
        //CX.at(i).second = XC.at(i).first;
    }
    vector<vector<ll>> v;
    v.push_back({0, 0});
    for(auto &elm : m) {
        sort(ALL(elm.second));
        v.push_back({elm.second.at(0), elm.second.back()});
    }
    v.push_back({0, 0});
    ll M = v.size();

    vector<vector<ll>> dp(M + 1, vector<ll>(2, INF));
    dp.at(0).at(0) = 0;
    dp.at(0).at(1) = 0;
    for(ll i = 0; i < M - 1; i++) {
        chmin(dp.at(i + 1).at(0), dp.at(i).at(0) + abs(v.at(i + 1).at(1) - v.at(i).at(0)) + abs(v.at(i + 1).at(0) - v.at(i + 1).at(1)));
        chmin(dp.at(i + 1).at(0), dp.at(i).at(1) + abs(v.at(i + 1).at(1) - v.at(i).at(1)) + abs(v.at(i + 1).at(0) - v.at(i + 1).at(1)));
        
        chmin(dp.at(i + 1).at(1), dp.at(i).at(0) + abs(v.at(i + 1).at(0) - v.at(i).at(0)) + abs(v.at(i + 1).at(1) - v.at(i + 1).at(0)));
        chmin(dp.at(i + 1).at(1), dp.at(i).at(1) + abs(v.at(i + 1).at(0) - v.at(i).at(1)) + abs(v.at(i + 1).at(1) - v.at(i + 1).at(0)));
    }
    cout << min(dp.at(M - 1).at(0), dp.at(M - 1).at(1)) << endl;
    return 0;
}