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

ll recur(ll N, ll K, ll isFirst, const vector<ll> &A, vector<vector<ll>> &dp) {
    if(K < 0) {
        return isFirst;
    }
    if(dp.at(K).at(isFirst) != -1) {
        return dp.at(K).at(isFirst);
    }
    if(isFirst == 1) {
        bool flag = false;
        for(ll i = 0; i < N; i++) {
            if(recur(N, K - A.at(i), 0, A, dp) == 1) {
                flag = true;
            }
        }
        if(flag) {
            return dp.at(K).at(isFirst) = 1;
        } else {
            return dp.at(K).at(isFirst) = 0;
        }
    } else {
        bool flag = false;
        for(ll i = 0; i < N; i++) {
            if(recur(N, K - A.at(i), 1, A, dp) == 0) {
                flag = true;
            }
        }
        if(flag) {
            return dp.at(K).at(isFirst) = 0;
        } else {
            return dp.at(K).at(isFirst) = 1;
        }
    }
}

int main(){
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<vector<ll>> dp(K + 1, vector<ll>(2, -1));
    if(recur(N, K, 1, A, dp) == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}