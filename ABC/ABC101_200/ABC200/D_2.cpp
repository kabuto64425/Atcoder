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
    for(ll &a : A) {
        cin >> a;
    }
    ll n = min(8LL, N);
    for(ll bit1 = 1; bit1 < (1 << n); bit1++) {
        for(ll bit2 = 1; bit2 < (1 << n); bit2++) {
            if(bit1 == bit2) {
                continue;
            }
            vector<ll> B;
            vector<ll> C;
            ll sumB = 0;
            ll sumC = 0;
            for(ll i = 0; i < n; i++) {
                if(bit1 & (1 << i)) {
                    sumB += A.at(i);
                    sumB %= 200;
                    B.push_back(i + 1);
                }
                if(bit2 & (1 << i)) {
                    sumC += A.at(i);
                    sumC %= 200;
                    C.push_back(i + 1);
                }
            }
            if(sumB == sumC) {
                cout << "Yes" << endl;
                cout << B.size() << " ";
                for(const ll &b : B) {
                    cout << b << " ";
                }
                cout << endl;
                cout << C.size() << " ";
                for(const ll &c : C) {
                    cout << c << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
     cout << "No" << endl;
    return 0;
}