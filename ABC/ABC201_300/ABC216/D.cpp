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
    ll N, M;
    cin >> N >> M;
    vector<ll> k(M);
    vector<vector<ll>> a(M);
    for(ll i = 0; i < M; i++) {
        cin >> k.at(i);
        for(ll j = 0; j < k.at(i); j++) {
           ll x;cin >> x;
           a.at(i).push_back(x);
        }
    }
    scc_graph graph(N);
    for(ll i = 0; i < M; i++) {
        vector<ll> v = a.at(i);
        for(ll j = 1; j < (ll)v.size(); j++) {
            // 始点と終点が同じで、1つの頂点で閉路ができてしまったパターン
            if(a.at(i).at(j - 1) - 1 == a.at(i).at(j) - 1) {
               cout << "No" << endl;
               return 0;
            }
            graph.add_edge(a.at(i).at(j - 1) - 1, a.at(i).at(j) - 1);
        }
    }
    if(graph.scc().size() == N) {
       cout << "Yes" << endl;
       return 0;
    }
    cout << "No" << endl;
    return 0;
}