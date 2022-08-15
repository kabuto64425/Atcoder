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

void recur(vector<ll> &v, ll pre, ll X, ll N, const vector<ll> &A, ll &ans) {
    if(v.size() == X) {
        ll sum = 0;
        for(ll i = 0; i < X; i++) {
            sum += A.at(v.at(i));
        }
        if(sum == 1000) {
            ans++;
        }
        return;
    }
    for(ll i = pre + 1; i < N; i++) {
        v.push_back(i);
        recur(v, i, X, N, A, ans);
        v.pop_back();
    }
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    vector<ll> v;
    ll ans = 0;

    recur(v, -1, 5, N, A, ans);
    cout << ans << endl;
    return 0;
}