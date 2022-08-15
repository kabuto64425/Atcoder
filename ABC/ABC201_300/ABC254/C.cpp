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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    vector<vector<ll>> vec(K);
    for(ll i = 0; i < N; i++) {
        vec.at(i % K).push_back(a.at(i));
    }
    for(ll i = 0; i < K; i++) {
        sort(ALL(vec.at(i)));
    }
    vector<ll> B(N);
    
    for(ll i = 0; i < N; i++) {
        B.at(i) = vec.at(i % K).at(i / K);
    }
    sort(ALL(a));
    for(ll i = 0; i < N; i++) {
        if(a.at(i) != B.at(i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}