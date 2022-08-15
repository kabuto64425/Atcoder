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
    string SA, SB, SC;
    cin >> SA;
    cin >> SB;
    cin >> SC;
    ll NA = SA.length();
    ll NB = SB.length();
    ll NC = SC.length();
    ll curA = 0;
    ll curB = 0;
    ll curC = 0;
    ll turn = 0;
    string ans;
    while(true) {
        if(turn == 0) {
            if(curA == NA) {
                ans = "A";
                break;
            }
            turn = (ll)(SA.at(curA) - 'a');
            curA++;
        } else if(turn == 1) {
            if(curB == NB) {
                ans = "B";
                break;
            }
            turn = (ll)(SB.at(curB) - 'a');
            curB++;
        } else {
            if(curC == NC) {
                ans = "C";
                break;
            }
            turn = (ll)(SC.at(curC) - 'a');
            curC++;
        }
    }
    cout << ans << endl;
    return 0;
}