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

ll f[440000];
ll g[440000];

void COMinitmod3(){
    f[0] = 0;
    g[0] = 1;
    for(ll i = 1; i <= 400000; i++) {
        ll j = i;
        while(j % 3 == 0) {
            j /= 3;
            f[i]++;
        }
        f[i] += f[i - 1];
        g[i] = j;
        g[i] *= g[i - 1];
        g[i] %= 3;
    }
}

ll ncrmod3(ll n, ll r) {
    if(f[n] - f[r] - f[n - r] > 0) {
        return 0;
    }
    return g[n] * g[r] * g[n - r] % 3;
    return 0;
}

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;

    COMinitmod3();
    map<char, ll> colormap;
    colormap['B'] = 0;
    colormap['W'] = 1;
    colormap['R'] = 2;
    ll colorNum = 0;
    for(ll i = 0; i < N; i++) {
        colorNum += colormap[S.at(i)] * ncrmod3(N - 1, i) % 3;
        colorNum %= 3;
    }
    if(N % 2 == 0) {
        colorNum = (3 - colorNum) % 3;
    }
    if(colorNum == 0) {
        cout << 'B' << endl;
    } else if(colorNum == 1) {
        cout << 'W' << endl;
    } else {
        cout << 'R' << endl;
    }
    return 0;
}