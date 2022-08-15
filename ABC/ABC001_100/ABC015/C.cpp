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

bool recur(const ll N, const ll K, const vector<vector<ll>> &T, vector<ll> &A) {
    if(A.size() == N) {
        ll x = 0;
        for(ll i = 0; i < N; i++) {
            x = x ^ T.at(i).at(A.at(i));
        }
        if(x == 0) {
            return true;
        }
        return false;
    }

    bool flag = false;

    for(ll i = 0; i < K; i++) {
        A.push_back(i);
        flag = flag | recur(N, K, T, A);
        A.pop_back();
    }
    return flag;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> T(N, vector<ll>(K));
    for(ll i = 0; i < N; i++) for(ll j = 0; j < K; j++) {
        cin >> T.at(i).at(j);
    }
    vector<ll> A;
    if(recur(N, K, T, A)) {
        cout << "Found" << endl;
        return 0;
    }
    cout << "Nothing" << endl;
    return 0;
}