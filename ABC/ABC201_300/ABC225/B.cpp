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

using Graph = vector<vector<ll>>;

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N - 1), b(N - 1);
    for(ll i = 0; i < N - 1; i++) {
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    Graph G(N);
    for(ll i = 0; i < N - 1; i++) {
        G.at(a.at(i)).push_back(b.at(i));
        G.at(b.at(i)).push_back(a.at(i));
    }
    for(ll i = 0; i < N; i++) {
        if(G.at(i).size() == N - 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}