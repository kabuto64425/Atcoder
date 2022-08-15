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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(M), B(M);
    for(ll i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    vector<ll> C(K), D(K);
    for(ll i = 0; i < K; i++) {
        cin >> C.at(i) >> D.at(i);
        C.at(i)--;
        D.at(i)--;
    }
    dsu d(N);
    for(ll i = 0; i < M; i++) {
        d.merge(A.at(i), B.at(i));
    }
    vector<ll> ans(N);
    for(ll i = 0; i < N; i++) {
        ans.at(i) = d.size(i) - 1;
    }
    for(ll i = 0; i < M; i++) {
        // 確実にtrueだが念のため
        if(d.same(A.at(i), B.at(i))) {
            ans.at(A.at(i))--;
            ans.at(B.at(i))--;
        }
    }
    for(ll i = 0; i < K; i++) {
        if(d.same(C.at(i), D.at(i))) {
            ans.at(C.at(i))--;
            ans.at(D.at(i))--;
        }
    }
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}