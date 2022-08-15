#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

ll ngcd(vector<ll> numbers) {
    ll res;
    res = numbers[0];
    for(ll i = 1; i < numbers.size() && res != 1; i++) {
        res = gcd(numbers[i], res);
    }
    return res;
}

int main(){
    ll N, X;
    cin >> N >> X;
    vector<ll> vec(N);
    for(ll &elm : vec) {
        cin >> elm;
        elm = abs(elm - X);
    }

    cout << ngcd(vec) << endl;

    return 0;
}