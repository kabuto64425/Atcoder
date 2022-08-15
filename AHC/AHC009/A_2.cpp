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

void bfs(const vector<string> &h, const vector<string> &v, vector<vector<ll>> &dist, vector<vector<ll>> &prev_i, vector<vector<ll>> &prev_j, pair<ll, ll> start) {

    const vector<pair<ll, ll>> ds = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    };

    auto culcDs = [h, v](pair<ll, ll> ver) {
        ll i = ver.first;
        ll j = ver.second;
        vector<pair<ll, ll>> res;
        //上
        if(i >= 1 && v.at(i - 1).at(j) != '1') {
            res.push_back({-1, 0});
        }
        //下
        if(i <= 20 - 2 && v.at(i).at(j) != '1') {
            res.push_back({1, 0});
        }
        //左
        if(j >= 1 && h.at(i).at(j - 1) != '1') {
            res.push_back({0, -1});
        }
        //右
        if(j <= 20 - 2 && h.at(i).at(j) != '1') {
            res.push_back({0, 1});
        }
        return res;
    };

    // BFS のためのデータ構造
    queue<pair<ll, ll>> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[start.first][start.second] = 0;
    que.push(start); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        pair<ll, ll> v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (pair<ll, ll> d : culcDs(v)) {
            if (dist[v.first + d.first][v.second + d.second] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[v.first + d.first][v.second + d.second] = dist[v.first][v.second] + 1;
            que.push({v.first + d.first, v.second + d.second});
            prev_i[v.first + d.first][v.second + d.second] = v.first;  // どの頂点から情報が伝播して来たか、縦方向の座標をメモ
            prev_j[v.first + d.first][v.second + d.second] = v.second;  // どの頂点から情報が伝播して来たか、横方向の座標をメモ
        }
    }

    return;
}

int main() {
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    ll si, sj, ti, tj;
    cin >> si >> sj >> ti >> tj;
    long double p;
    cin >> p;
    vector<string> h(20);
    vector<string> v(19);
    for(ll i = 0; i < 20; i++) {
        cin >> h.at(i);
    }
    for(ll i = 0; i < 19; i++) {
        cin >> v.at(i);
    }

    vector<vector<ll>> dist(20, vector<ll>(20, -1)); // 全頂点を「未訪問」に初期化

     // 探索中に各マスはどのマスから来たのかを表す配列 (最短経路長を知るだけなら、これは不要)
    vector<vector<ll>> prev_i(20, vector<ll>(20, -1));
    vector<vector<ll>> prev_j(20, vector<ll>(20, -1));

    bfs(h, v, dist, prev_i, prev_j, {si, sj});
    /* ゴールに至るまでの最短経路を復元してみる */
    ll i = ti, j = tj;
    stack<char> st;
    while(prev_i.at(i).at(j) != -1 and prev_j.at(i).at(j) != -1) {
        // 前の頂点へ行く
        int pi = prev_i[i][j];
        int pj = prev_j[i][j];
        if(i - pi == 1 and j - pj == 0) {
            st.push('D');
        }
        if(i - pi == -1 and j - pj == 0) {
            st.push('U');
        }
        if(i - pi == 0 and j - pj == 1) {
            st.push('R');
        }
        if(i - pi == 0 and j - pj == -1) {
            st.push('L');
        }
        i = pi, j = pj;
    }

    uniform_int_distribution<ll> dist_d(0, 3);
    vector<char> dc = {'U', 'R', 'D', 'L'};

    // 0.0以上1.0未満の値を等確率で発生させる
    std::uniform_real_distribution<> dist_r(0.0, 1.0);

    string ans = "";
    while(!st.empty() and ans.length() < 200) {
        long double r = dist_r(rnd);
        if(r < p) {
            ll d = dist_d(rnd);
            ans += dc.at(d);
        } else {
            ans += st.top();
            st.pop();
        }
    }

    while(ans.length() < 200) {
        ll d = dist_d(rnd);
        ans += dc.at(d);
    }

    cout << ans << endl;
    return 0;
}