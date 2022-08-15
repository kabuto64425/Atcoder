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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> x(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> x.at(i);
    }
    vector<ll> v1(N + 1);
    vector<ll> v2(N + 1);
    for(ll i = 1; i <= N; i++) {
        v1.at(i) = i;
        v2.at(i) = i;
    }

    for(ll q = 0; q < Q; q++) {
        ll ball1 = x.at(q);
        ll index1 = v1.at(ball1);
        ll index2;
        if(index1 == N) {
            index2 = index1 - 1;
        } else {
            index2 = index1 + 1;
        }
        ll ball2 = v2.at(index2);
        swap(v1.at(ball1), v1.at(ball2));
        swap(v2.at(index1), v2.at(index2));
    }

    for(ll i = 1; i <= N; i++) {
        cout << v2.at(i) << " ";
    }
    cout << endl;

    return 0;
}