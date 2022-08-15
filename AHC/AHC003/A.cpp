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
    REP(i, 1000) {
        ll si, sj, ti, tj;
        cin >> si >> sj >> ti >> tj;
        if(si >= ti) {
            for(ll j = 0; j < si - ti; j++) {
                cout << 'U';
            }
        } else {
            for(ll j = 0; j < ti - si; j++) {
                cout << 'D';
            }
        }
        if(sj >= tj) {
            for(ll j = 0; j < sj - tj; j++) {
                cout << 'L';
            }
        } else {
            for(ll j = 0; j < tj - sj; j++) {
                cout << 'R';
            }
        }
        cout << endl;
        ll score;
        cin >> score;
    }
    return 0;
}