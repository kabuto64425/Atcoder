#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

vector<ll> enum_div(ll n){
    vector<ll> ret;
    for(ll i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i != 1 && i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll &elm : a) {
        cin >> elm;
    }
    vector<ll> count(N, 0);
    stack<ll> s;
    for(ll i = N - 1; i >= 0; i--) {
        if(count.at(i) % 2 != a.at(i)) {
            s.push(i + 1);
            vector<ll> vec = enum_div(i + 1);
            for(const ll &e : vec) {
                count.at(e - 1)++;
            }
        }
    }
    cout << s.size() << endl;
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}