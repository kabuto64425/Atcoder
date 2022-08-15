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
    /*for(ll i = 0; i < N; i++) {
        swap(LR.at(i).first, LR.at(i).second);
    }*/
    sort(ALL(LR));
    /*for(ll i = 0; i < N; i++) {
        swap(LR.at(i).first, LR.at(i).second);
    }*/
    vector<pair<ll, ll>> ans;
    ll currentMax = -10;
    for(ll i = 0; i < N; i++) {
        if(LR.at(i).first > currentMax) {
            ans.push_back({LR.at(i).first, LR.at(i).second});
        } else {
            if(ans.back().second < LR.at(i).second) {
                ans.back().second = LR.at(i).second;
            }
        }
        /*if(LR.at(i).first <= pre) {
            ans.back().second = LR.at(i).second;
        } else {
            ans.push_back({LR.at(i).first, LR.at(i).second});
        }*/
        chmax(currentMax, LR.at(i).second);
        //pre = LR.at(i).second;
    }

    for(auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}