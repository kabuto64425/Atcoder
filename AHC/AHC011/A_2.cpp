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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

const char dc[4] = {'L', 'U', 'R', 'D'};
const ll di[4] = { 0, -1, 0, 1};
const ll dj[4] = { -1, 0, 1, 0};

ll toDec(const char c) {
    if(c >= '0' and c <= '9') {
        return c - '0';
    }
    if(c >= 'a' and c <= 'f') {
        return 10 + c - 'a';
    }
    return -1;
}

ll compute_score(const ll N, const ll T, const ll turn, const string &vertex) {
    dsu d(N * N);
    vector<bool> tree(N * N, true);

     vector<vector<ll>> tiles(N, vector<ll>(N));
    for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
        tiles[i][j] = toDec(vertex.at(i * N + j));
    }

    for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
        if(i + 1 < N && (tiles[i][j] & 8) != 0 && (tiles[i + 1][j] & 2) != 0) {
            ll a = d.leader(i * N + j);
            ll b = d.leader((i + 1) * N + j);
            if(a == b) {
                tree[a] = false;
            } else {
                ll t = tree[a] && tree[b];
                d.merge(a, b);
                tree[d.leader(a)] = t;
            }
        }
        if(j + 1 < N && (tiles[i][j] & 4) != 0 && (tiles[i][j + 1] & 1) != 0) {
            ll a = d.leader(i * N + j);
            ll b = d.leader(i * N + j + 1);
            if(a == b) {
                tree[a] = false;
            } else {
                ll t = tree[a] && tree[b];
                d.merge(a, b);
                tree[d.leader(a)] = t;
            }
        }
    }

    ll max_tree = -1;
    for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
        if(tiles[i][j] != 0 && tree[d.leader(i * N + j)]) {
            if(max_tree == -1 || (d.size(max_tree) < d.size(i * N + j))) {
                max_tree = i * N + j;
            }
        }
    }

    vector<vector<bool>> bs(N, vector<bool>(N, false));

    if(max_tree != -1) {
        for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
            bs[i][j] = d.same(max_tree, i * N + j);
        }
    }

    if(turn > T) {
        return 0;
    }

    ll size = ((max_tree == -1)? 0 : d.size(max_tree));
    ll score = 0;
    if(size == N * N - 1) {
        score = round((long double)(500000) * ((long double)1.0 + (long double)(T - turn) / (long double)T));
    } else {
        score = round((long double)(500000) * ((long double)size) / ((long double)(N * N - 1)));
    }

    return score;
}

int main(){
    clock_t start = clock();
    ll N, T;
    cin >> N >> T;
    vector<string> t(N);
    for(ll i = 0; i < N; i++) {
        cin >> t.at(i);
    }

    vector<vector<ll>> tiles(N, vector<ll>(N));
    ll zeroPosI = -1, zeroPosJ = -1;
    for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
        tiles[i][j] = toDec(t.at(i).at(j));
        if(t.at(i).at(j) == '0') {
            zeroPosI = i;
            zeroPosJ = j;
        }
    }

    map<string, ll> dist;
    string vertex = "";
    for(ll i = 0; i < N; i++) {
        vertex += t.at(i);
    }
    dist[vertex] = 0;
    // BFS のためのデータ構造
    queue<string> que;
    queue<pair<ll, ll>> posQue;

    ll score = 0;

    que.push(vertex); // 0 を橙色頂点にする
    posQue.push({zeroPosI, zeroPosJ});
    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty() and (long double)(clock() - start) / CLOCKS_PER_SEC < 2.88) {
        string v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        pair<ll, ll> pos = posQue.front();
        posQue.pop();

        chmax(score, compute_score(N, T, dist[v], v));

        for(ll r = 0; r < 4; r++) {
            if(pos.first + di[r] < 0) {
                continue;
            }
            if(pos.first + di[r] >= N) {
                continue;
            }
            if(pos.second + dj[r] < 0) {
                continue;
            }
            if(pos.second + dj[r] >= N) {
                continue;
            }
            string nv = v;
            pair<ll, ll> npos = {pos.first + di[r], pos.second + dj[r]};
            swap(nv.at(pos.first * N + pos.second), nv.at(npos.first * N + npos.second));

            if (dist.count(nv)) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
            posQue.push(npos);
        }
    }

    cout << score << endl;

    return 0;
}