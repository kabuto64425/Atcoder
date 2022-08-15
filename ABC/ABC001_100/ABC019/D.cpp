#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    ll vertexFarthestFromOne = 0;
    ll farthestDistance = 0;
    for(ll i = 2; i <= N; i++) {
        cout << "? " << 1 << " " << i << endl;
        ll distFromOne;
        cin >> distFromOne;
        if(distFromOne > farthestDistance) {
            farthestDistance = distFromOne;
            vertexFarthestFromOne = i;
        }
    }

    ll ans = 0;

    for(ll i = 1; i <= N; i++) {
        if(i == vertexFarthestFromOne) {
            continue;
        }
        cout << "? " << vertexFarthestFromOne << " " << i << endl;
        ll distFromFartestVertex = 0;
        cin >> distFromFartestVertex;
        ans = max(ans, distFromFartestVertex);
    }
    cout << "! " << ans << endl;
    return 0;
}