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
    ll N;
    cin >> N;
    vector<ll> ans(2600);
    ans.at(1) = 6;
    ans.at(2) = 10;
    ans.at(3) = 15;

    ll index = 4;
    ll num = ans.at(1);
    while(num + ans.at(1) <= 10000 and index <= 2500) {
        num += ans.at(1);
        ans.at(index) = num;
        index++;
    }

    num = ans.at(2);
    while(num + ans.at(2) <= 10000 and index <= 2500) {
        num += ans.at(2);
        if(num % ans.at(1) == 0) {
            continue;
        }
        ans.at(index) = num;
        index++;
    }

    num = ans.at(3);
    while(num + ans.at(3) <= 10000 and index <= 2500) {
        num += ans.at(3);
        if(num % ans.at(1) == 0 or num % ans.at(2) == 0) {
            continue;
        }
        ans.at(index) = num;
        index++;
    }

    for(ll i = 1; i <= N; i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}