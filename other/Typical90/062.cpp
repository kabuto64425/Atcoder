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
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < N; ++i) {
        G[A.at(i)].push_back(i);
        G[B.at(i)].push_back(i);
    }

    vector<ll> dist(G.size(), -1); // 全頂点を「未訪問」に初期化
    queue<ll> que;
    vector<bool> checked(N, false);
    for(ll i = 0; i < N; i++) {
        for(ll to : G[i]) {
            if(to == i) {
                if(!checked.at(i)) {
                    checked.at(i) = true;
                    que.push(i);
                }
            }
        }
    }
    
    vector<int> vec;
    while(!que.empty()) {
        ll x = que.front();
        que.pop();
        vec.push_back(x);
        for(ll to : G[x]) {
            if(!checked.at(to)) {
                checked.at(to) = true;
                que.push(to);
            }
        }
    }
    reverse(ALL(vec));
    if(vec.size() != N) {
        cout << -1 << endl;
    } else {
        for(ll i = 0; i < vec.size(); i++) {
            cout << vec.at(i) + 1 << endl;
        }
    }
    return 0;
}