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
    ll si, sj, ti, tj;
    cin >> si >> sj >> ti >> tj;
    long double p;
    cin >> p;
    vector<string> h(20);
    vector<string> v(19);
    for(ll i = 0; i < 20; i++) {
        cin >> h.at(i);
    }
    for(ll i = 0; i < 19; i++) {
        cin >> v.at(i);
    }
    ll currenti = si;
    ll currentj = sj;
    string ans = "";
    char pre = '-';
    for(ll turn = 0; turn < 200; turn++) {
        if(currenti == ti and currentj == tj) {
            break;
        }
        if(currentj < tj and h.at(currenti).at(currentj) != '1') {
            currentj++;
            ans += "R";
        } else if(currenti < ti and v.at(currenti).at(currentj) != '1') {
            currenti++;
            ans += "D";
        }
    }
    cout << ans << endl;
    return 0;
}