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

void recur(const ll N, const vector<vector<ll>> &A, vector<ll> &v, vector<bool> &seen, ll &ans) {
    if(v.size() == 2 * N) {
        ll current = 0;
        for(ll i = 0; i < N; i++) {
            current = current ^ A.at(v.at(2 * i)).at(v.at(2 * i + 1));
        }
        chmax(ans, current);
        return;
    }
    if(v.size() % 2 == 0) {
        for(ll i = 0; i < 2 * N; i++) {
            if(!seen.at(i)) {
                seen.at(i) = true;
                v.push_back(i);
                recur(N, A, v, seen, ans);
                v.pop_back();
                seen.at(i) = false;
                break;
            }
        }
    } else {
        for(ll i = 0; i < 2 * N; i++) {
            if(seen.at(i)) {
                continue;
            }
            seen.at(i) = true;
            v.push_back(i);
            recur(N, A, v, seen, ans);
            v.pop_back();
            seen.at(i) = false;
        }
    }
}

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(2 * N, vector<ll>(2 * N));
    for(ll i = 0; i < 2 * N; i++) {
        for(ll j = i + 1; j < 2 * N; j++) {
            cin >> A.at(i).at(j);
        }
    }

    vector<ll> v;
    vector<bool> seen(2 * N);
    ll ans = 0;
    recur(N, A, v, seen, ans);
    cout << ans << endl;
    return 0;
}