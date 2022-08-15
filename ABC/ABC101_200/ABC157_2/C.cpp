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

ll digcount(ll n) {
    if(n == 0) {
        return 1;
    }
    ll res = 0;
    while(n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> s(M), c(M);
    for(ll i = 0; i < M; i++) {
        cin >> s.at(i) >> c.at(i);
    }
    for(ll num = 0; num <= 999; num++) {
        if(digcount(num) != N) {
            continue;
        }
        string numstr = to_string(num);
        bool flag = true;
        for(ll i = 0; i < M; i++) {
            char targetchar = (char)(c.at(i) + '0');
            if(numstr.at(s.at(i) - 1) != targetchar) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << num << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}