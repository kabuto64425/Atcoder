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
    vector<ll> A(K);
    for(ll i = 0; i < K; i++) {
        cin >> A.at(i);
    }
    vector<ll> X(N), Y(N);
    for(ll i = 0; i < N; i++) {
        cin >> X.at(i) >> Y.at(i);
    }
    ll ok = 80000000000LL;
    ll ng = -1LL;
    while(abs(ok - ng) != 1) {
        ll mid = (ok + ng) / 2;
        bool flag1 = true;
        for(ll i = 0; i < N; i++) {
            ll xi = X.at(i);
            ll yi = Y.at(i);
            bool flag2 = false;
            for(ll j = 0; j < K; j++) {
                ll xj = X.at(A.at(j) - 1);
                ll yj = Y.at(A.at(j) - 1);

                ll d = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
                if(mid >= d) {
                    flag2 = true;
                }
            }
            if(!flag2) {
                flag1 = false;
            }
        }
        if(flag1) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << fixed << setprecision(20) << sqrtl(ok) << endl;
    return 0;
}