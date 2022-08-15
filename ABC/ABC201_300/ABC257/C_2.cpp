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
    string S;
    cin >> S;
    vector<ll> W(N);
    for(ll i = 0; i < N; i++) {
        cin >> W.at(i);
    }
    map<ll, ll> m;
    ll correct = 0;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) == '1') {
            m[W.at(i)] -= 1;
            correct++;
        } else {
            m[W.at(i)] += 1;
        }
    }
    ll ans = correct;
    for(auto p : m) {
        correct += p.second;
        chmax(ans, correct);
    }
    cout << ans << endl;

    return 0;
}