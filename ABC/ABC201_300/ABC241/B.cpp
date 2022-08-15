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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<ll> B(N);
    for(ll i = 0; i < M; i++) {
        cin >> B.at(i);
    }
    map<ll, ll> m;
    for(ll i = 0; i < N; i++) {
        m[A.at(i)]++;
    }
    for(ll i = 0; i < M; i++) {
        if(m[B.at(i)] == 0) {
            cout << "No" << endl;
            return 0;
        }
        m[B.at(i)]--;
    }
    cout << "Yes" << endl;
    return 0;
}