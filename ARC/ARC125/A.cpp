#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> S(N);
    for(ll &s : S) {
        cin >> s;
    }
    vector<ll> T(M);
    for(ll &t : T) {
        cin >> t;
    }
    
    bool allZeroS = all_of(S.begin(), S.end(), [](ll s) {
        return s == 0;
    });

    bool anyOneT = any_of(T.begin(), T.end(), [](ll t) {
        return t == 1;
    });

    if(allZeroS and anyOneT) {
        cout << -1 << endl;
        return 0;
    }

    bool allOneS = all_of(S.begin(), S.end(), [](ll s) {
        return s == 1;
    });

    bool anyZeroT = any_of(T.begin(), T.end(), [](ll t) {
        return t == 0;
    });

    if(allOneS and anyZeroT) {
        cout << -1 << endl;
        return 0;
    }

    ll index1 = 0;
    while(index1 < N and S.at(0) == S.at(index1)) {
        index1++;
    }

    ll index2 = 0;
    while(index2 < N and S.at(0) == S.at((N - index2) % N)) {
        index2++;
    }

    ll dist = min(index1, index2);

    ll ans = 0;

    ll currentS = S.at(0);

    bool differenceFirst = true;

    for(ll i = 0; i < M; i++) {
        if(T.at(i) == currentS) {
            ans++;
        } else {
            if(differenceFirst) {
                ans += (dist + 1);
                differenceFirst = false;
            } else {
                ans += 2;
            }
        }
        currentS = T.at(i);
    }

    cout << ans << endl;

    return 0;
}