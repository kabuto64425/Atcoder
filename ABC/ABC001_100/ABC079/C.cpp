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
    string S;
    cin >> S;
    ll A = S.at(0) - '0';
    ll B = S.at(1) - '0';
    ll C = S.at(2) - '0';
    ll D = S.at(3) - '0';
    for(ll bit = 0; bit < (1 << 3); bit++) {
        bitset<3> s(bit);
        ll current = A;
        current += ((s.test(0))? B : -B);
        current += ((s.test(1))? C : -C);
        current += ((s.test(2))? D : -D);
        if(current == 7) {
            cout << A << ((s.test(0))? '+' : '-') << B << ((s.test(1))? '+' : '-') << C << ((s.test(2))? '+' : '-') << D << "=7" << endl;
            return 0;
        }
    }
    return 0;
}