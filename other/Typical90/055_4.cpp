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

template <class It>
void aaa(It First) {
    cout << First[0] << endl;
}

void bbb(const function<void(vector<ll>::iterator)> &f) {
    vector<ll> v(100000, 0);
    for(ll i = 0; i < 100000; i++) {
        f(v.begin());
    }
}

void recur(ll n, ll r, const function<void(const vector<ll>&)> &f, vector<ll> &v) {
    if(v.size() == r) {
        f(v);
        return;
    }
    ll prev_last = (v.empty() ? -1 : v.back());
    for (ll i = prev_last + 1; i < n; i++) {
        v.push_back(i);
        recur(n, r, f, v);
        v.pop_back();
    }
}

void ccc(ll n, ll r, const function<void(const vector<ll>&)> &f) {
    vector<ll> v;
    recur(n, r, f, v);
}

int main(){
    //vector<ll> v({1,2,3});
    //cout << v.at(0) << endl;
    //v.begin();
    //aaa(v.begin());

    ccc(5, 3, [](const vector<ll> &v) {
        cout << v.at(0) << v.at(1) << v.at(2) << endl;
    });
    return 0;
}