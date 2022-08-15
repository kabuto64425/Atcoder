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

int main(){
    map<ll, ll> b;
    for(ll i = 0; i < 10; i++) {
        ll elm;
        cin >> elm;
        b[elm] = i;
    }
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll &elm : a) {
        cin >> elm;
    }
    auto comp = [&b](ll x, ll y){
        ll xres = 0;
        stack<ll> xs;
        while(x > 0) {
            xs.push(b[x % 10]);
            x /= 10;
        }
        while(!xs.empty()) {
            xres *= 10;
            xres += xs.top();
            xs.pop();
        }

        ll yres = 0;
        stack<ll> ys;
        while(y > 0) {
            ys.push(b[y % 10]);
            y /= 10;
        }
        while(!ys.empty()) {
            yres *= 10;
            yres += ys.top();
            ys.pop();
        }

        return xres < yres;
    };
    sort(a.begin(), a.end(), comp);
    for(const ll &elm : a) {
        cout << elm << endl;
    }
    return 0;
}