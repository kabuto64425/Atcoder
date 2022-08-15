#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    for(vector<ll> &vec : A) {
        for(ll &elm : vec) {
            cin >> elm;
        }
    }
    vector<ll> sumRow(H);
    vector<ll> sumColumn(W);
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            sumRow.at(i) += A.at(i).at(j);
            sumColumn.at(j) += A.at(i).at(j);
        }
    }

    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            cout << sumRow.at(i) + sumColumn.at(j) - A.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}