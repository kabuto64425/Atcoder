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

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, vector<bool> &seen) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, seen); // 再帰的に探索
    }
    //帰りがけの処理を書く（タイムスタンプなど）
    //timeStampMap[ptr] = v;
    //ans++;
    //ここまで
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> U(M), V(M);
    for(ll i = 0; i < M; i++) {
        cin >> U.at(i) >> V.at(i);
        U.at(i)--;
        V.at(i)--;
    }

    scc_graph graph(N);

    for(ll i = 0; i < M; i++) {
        graph.add_edge(U.at(i), V.at(i));
    }

    vector<vector<int>> scc = graph.scc();

    //ll ans = 0;
    vector<bool> flags(N, false);
    for(ll i = 0; i < scc.size(); i++) {
        if(scc.at(i).size() >= 2) {
            //ans += scc.at(i).size();
            for(int j : scc.at(i)) {
                flags.at(j) = true;
            }
        }
    }

    Graph RG(N);
    
    for(ll i = 0; i < M; i++) {
        RG[V.at(i)].push_back(U.at(i));
    }

    vector<bool> seen = flags;
    for(ll i = 0; i < N; i++) {
        if(!flags.at(i)) {
            continue;
        }
        dfs(RG, i, seen);
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(seen.at(i)) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}