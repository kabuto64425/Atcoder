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
    ll N, A, B;
    cin >> N >> A >> B;
    vector<vector<char>> vec(A * N, vector<char>(B * N));
    for(ll i = 0; i < A * N; i++) for(ll j = 0; j < B * N; j++) {
        ll a = i / A;
        ll b = j / B;
        if((a + b) % 2 == 0) {
            vec.at(i).at(j) = '.';
        } else {
            vec.at(i).at(j) = '#';
        }
    }
    for(ll i = 0; i < A * N; i++) {
        for(ll j = 0; j < B * N; j++) {
            cout << vec.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}