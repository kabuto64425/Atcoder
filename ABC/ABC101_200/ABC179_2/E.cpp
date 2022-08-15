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
    ll N, X, M;
    cin >> N >> X >> M;

    deque<ll> a; // 繰り返しの部分
    vector<bool> seen(M, false); // 一度見たかどうか
    ll cur = X;
    ll ans = 0;
    while(true) {
        if(seen.at(cur)) {
            while(a.front() != cur) {
                ans += a.front();
                a.pop_front();
                N--;

                if(N == 0) {
                    cout << ans << endl;
                    return 0;
                }
            }
            break;
        }

        seen.at(cur) = true;
        a.push_back(cur);
        cur = (cur * cur) % M;
    }

    ll sum = 0;
    ll cycle = N / a.size();
    ll x = N % a.size();
    while(!a.empty()) {
        sum += a.front();
        if(x > 0) {
            ans += a.front();
            x--;
        }
        a.pop_front();
    }

    ans += sum * cycle;
    cout << ans << endl;

    return 0;
}