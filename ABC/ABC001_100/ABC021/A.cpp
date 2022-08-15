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
    ll N;
    cin >> N;
    bitset<20> s(N);
    ll count = 0;
    ll current = 1;
    vector<ll> vec;
    for(ll i = 0; i < 4; i++) {
        if(s.test(i)) {
            count++;
            vec.push_back(current);
        }
        current *= 2;
    }
    cout << count << endl;
    for(ll i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << endl;
    }
    return 0;
}