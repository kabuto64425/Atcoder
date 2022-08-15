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
    ll A, B;
    cin >> A >> B;
    queue<ll> s1, s2;
    while(A > 0) {
        s1.push(A % 10);
        A /= 10;
    }
    while(B > 0) {
        s2.push(B % 10);
        B /= 10;
    }
    while(!s1.empty() and !s2.empty()) {
        ll a = s1.front();
        ll b = s2.front();
        if(a + b >= 10) {
            cout << "Hard" << endl;
            return 0;
        }
        s1.pop();
        s2.pop();
    }
    cout << "Easy" << endl;
    return 0;
}