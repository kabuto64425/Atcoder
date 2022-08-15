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
    vector<vector<ll>> A(3, vector<ll>(3));
    for(ll i = 0; i < 3; i++) for(ll j = 0; j < 3; j++) {
        cin >> A.at(i).at(j);
    }
    ll N;
    cin >> N;
    vector<ll> b(N);
    for(ll i = 0; i < N; i++) {
        cin >> b.at(i);
    }
    vector<vector<bool>> C(3, vector<bool>(3));
    for(ll i = 0; i < N; i++) for(ll j = 0; j < 3; j++) for(ll k = 0; k < 3; k++) {
        if(b.at(i) == A.at(j).at(k)) {
            C.at(j).at(k) = true;
        }
    }
    bool ansFLag = false;
    for(ll i = 0; i < 3; i++) {
        if(C.at(i).at(0) and C.at(i).at(1) and C.at(i).at(2)) {
            ansFLag = true;
        }
    }
    for(ll i = 0; i < 3; i++) {
        if(C.at(0).at(i) and C.at(1).at(i) and C.at(2).at(i)) {
            ansFLag = true;
        }
    }
    if(C.at(0).at(0) and C.at(1).at(1) and C.at(1).at(1)) {
        ansFLag = true;
    }
    if(C.at(2).at(0) and C.at(1).at(1) and C.at(0).at(2)) {
        ansFLag = true;
    }
    if(ansFLag) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}