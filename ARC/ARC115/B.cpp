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
    ll N;
    cin >> N;
    vector<vector<ll>> C(N, vector<ll>(N, 0));
    for(vector<ll> &vec : C) {
        for(ll &elm : vec) {
            cin >> elm;
        }
    }

    ll sum = 0;
    ll m = INF;
    pair<ll, ll> minIndex;

    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            sum += C.at(i).at(j);
            if(m > C.at(i).at(j)) {
                m = C.at(i).at(j);
                minIndex.first = i;
                minIndex.second = j;
            }
        }
    }

    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        A.at(i) = C.at(i).at(minIndex.second);
    }
    vector<ll> B(N);
    for(ll i = 0; i < N; i++) {
        B.at(i) = C.at(minIndex.first).at(i) - A.at(minIndex.first);
    }

    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            if(A.at(i) + B.at(j) != C.at(i).at(j)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    for(ll i = 0; i < N; i++) {
        cout << A.at(i) << " ";
    }
    cout << endl;
    for(ll i = 0; i < N; i++) {
        cout << B.at(i) << " ";
    }
    cout << endl;
    return 0;
}