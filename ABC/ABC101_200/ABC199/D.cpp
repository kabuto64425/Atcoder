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

using Graph = vector<vector<ll>>;

// 深さ優先探索
// 最長ルートや有向グラフなど、場合によっていはseenが不要になるケースもある。
void dfs(const Graph &G, ll v, ll previous, vector<bool> &seen, vector<pair<ll, ll>> &group) {
    //行きがけの処理を書く（タイムスタンプ・再帰終了条件など）
    group.push_back({v, previous});
    //ここまで
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, v, seen, group); // 再帰的に探索
    }

    //帰りがけの処理を書く（タイムスタンプなど）
    
    //ここまで
}

int main() {
    ll N, M;
    cin >> N >> M;

    // 辺の情報
    vector<pair<ll, ll>> edges(M);
    for(pair<ll, ll> &edge : edges) {
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
    }

    // グラフを作成 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }
    vector<bool> seen;

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化

    vector<vector<pair<ll, ll>>> groups;

    for(ll i = 0; i < N; i++) {
        if(seen.at(i)) {
            continue;
        }
        vector<pair<ll, ll>> group;
        dfs(G, i, -1, seen, group);
        groups.push_back(group);
    }

    ll ans = 1;

    for(ll i = 0; i < groups.size(); i++) {
        ll validCount = 0;
        vector<pair<ll, ll>> group = groups.at(i);
        map<ll, ll> colorMap;
        colorMap[group.at(0).first] = 0;
        for(ll bit = 0; bit < (1 << (group.size() - 1)); bit++) {
            for(ll i = 0; i < group.size() - 1; i++) {
                if(bit & (1 << i)) {
                    colorMap[group.at(i + 1).first] = (colorMap[group.at(i + 1).second] + 1) % 3;
                } else {
                    colorMap[group.at(i + 1).first] = (colorMap[group.at(i + 1).second] + 2) % 3;
                }
            }

            bool validFlag = true;

            for (const pair<char, ll> &elm : colorMap) {
                vector<ll> nodes = G.at(elm.first);
                for(const ll &node : nodes) {
                    if(colorMap[node] == colorMap[elm.first]) {
                        validFlag = false;
                        break;
                    }
                }
                if(!validFlag) {
                    break;
                }
            }

            if(validFlag) {
                validCount++;
            }
        }
        ans *= (validCount * 3);
    }
    
    cout << ans << endl;
    return 0;
}