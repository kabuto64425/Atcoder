#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

const vector<pair<ll, ll>> walks = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

signed main(){
    ll H, W;
    cin >> H >> W;
    vector<string> tizu(H);
    vector<vector<ll>> distOrigin(H, vector<ll>(W, -1));
    REP(i, H) {
        cin >> tizu.at(i);
        REP(j, W) {
            if(tizu.at(i).at(j) == '#') {
                distOrigin.at(i).at(j) = INF;
            }
        }
    }

    ll ans = 0;

    REP(i, H) {
        REP(j, W) {
            if(distOrigin.at(i).at(j) == INF) {
                continue;
            }
            vector<vector<ll>> dist = distOrigin;
            queue<pair<ll, ll>> que;

            dist[i][j] = 0;
            que.push({i, j}); // 0 を橙色頂点にする
            while (!que.empty()) {
                pair<ll, ll> v = que.front(); // キューから先頭頂点を取り出す
                que.pop();

                // v から辿れる頂点をすべて調べる
                for (pair<ll, ll> walk : walks) {
                    if(v.first + walk.first < 0) {
                        continue;
                    }
                    if(v.first + walk.first >= H) {
                        continue;
                    }
                    if(v.second + walk.second < 0) {
                        continue;
                    }
                    if(v.second + walk.second >= W) {
                        continue;
                    }
                    if (dist[v.first + walk.first][v.second + walk.second] != -1) continue; // すでに発見済みの頂点は探索しない
        
                    // 新たな白色頂点 nv について距離情報を更新してキューに追加する
                    dist[v.first + walk.first][v.second + walk.second] = dist[v.first][v.second] + 1;
                    que.push({v.first + walk.first, v.second + walk.second});
                }
            }
            REP(k, H) {
                REP(l, W) {
                    if(dist[k][l] == INF) {
                        continue;
                    }
                    ans = max(ans, dist[k][l]);
                }
            }
        }
    }

    cout << ans << endl;
}