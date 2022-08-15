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
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    ll len = min(8LL, N);
    map<ll, ll> m;
    for(ll bit = 1; bit < (1 << len); bit++) {
        bitset<20> bs(bit);
        ll sum = 0;
        for(ll i = 0; i < len; i++) {
            if(bs.test(i)) {
                sum += A.at(i);
            }
        }
        if(sum % 200 == 160) {
            cout << bs.count() << " ";
            for(ll i = 0; i < len; i++) {
                if(bs.test(i)) {
                    cout << (i + 1) << " ";
                }
            }
            cout << endl;
        }
        /*if(m.count(sum % 200)) {
            cout << "Yes" << endl;
            cout << bs.count() << " ";
            for(ll i = 0; i < len; i++) {
                if(bs.test(i)) {
                    cout << (i + 1) << " ";
                }
            }
            cout << endl;
            bitset<20> bs2(m[sum % 200]);
            cout << bs2.count() << " ";
            for(ll i = 0; i < len; i++) {
                if(bs2.test(i)) {
                    cout << (i + 1) << " ";
                }
            }
            cout << endl;
            return 0;
        }*/
        m[sum % 200] = bit;
    }
    cout << "No" << endl;
    return 0;
}