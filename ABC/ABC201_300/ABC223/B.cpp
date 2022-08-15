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
    vector<string> v;
    ll N = S.length();
    for(ll i = 0; i < N; i++) {
        S = S.substr(1, N - 1) + S.at(0);
        v.push_back(S);
    }
    sort(ALL(v));
    cout << v.at(0) << endl;
    cout << v.at(N - 1) << endl;
    return 0;
}