#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

int main(){
    ll A, B;
    cin >> A >> B;
    cout << (A * 2 + 100 - B) << endl;
    //小数の桁数の出力指定
    //cout << fixed << setprecision(20) << endl;
    return 0;
}