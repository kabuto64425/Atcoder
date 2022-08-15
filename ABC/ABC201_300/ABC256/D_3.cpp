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
    vector<pair<ll, ll>> LR(N);
    for(ll i = 0; i < N; i++) {
        cin >> LR.at(i).first >> LR.at(i).second;
    }

    vector<ll> csum(220000, 0);
    for(ll i = 0; i < N; i++) {
        csum.at(LR.at(i).first) += 1;
        csum.at(LR.at(i).second) -= 1;
    }
    for(ll i = 0; i <= 200000; i++) {
        csum.at(i + 1) += csum.at(i);
    }
    vector<pair<ll, ll>> ans;
    for(ll i = 0; i <= 200000; i++) {
        if(csum.at(i) == 0 and csum.at(i + 1) >= 1) {
            ans.emplace_back(i + 1, i + 1);
        }
        if(csum.at(i) >= 1 and csum.at(i + 1) == 0) {
            ans.back().second = i + 1;
        }
    }
    
    for(auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}