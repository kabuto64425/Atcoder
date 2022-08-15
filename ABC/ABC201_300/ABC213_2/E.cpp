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

typedef long long ll;
const long long INF = 1LL << 60;

vector<ll> dx = {-1, 0, 1, 0};
vector<ll> dy = {0, -1, 0, 1};


void dijkstra(const ll H, const ll W, const vector<string> &S, vector<vector<ll>> &cost) {
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    cost[0][0] = 0;
    pq.emplace(cost[0][0], 0, 0);
    while (!pq.empty()) {
        tuple<ll, ll, ll> p = pq.top();
        pq.pop();
        int x = get<1>(p);
        int y = get<2>(p);
        if (cost[x][y] < get<0>(p)) {  // 最短距離で無ければ無視
            continue;
        }
        for(ll i = 0; i < 4; i++) {
            if(x + dx.at(i) < 0) {
                continue;
            }
            if(x + dx.at(i) >= H) {
                continue;
            }
            if(y + dy.at(i) < 0) {
                continue;
            }
            if(y + dy.at(i) >= W) {
                continue;
            }
            if(S.at(x + dx.at(i)).at(y + dy.at(i)) == '#') {
                continue;
            }
            if(cost[x + dx.at(i)][y + dy.at(i)] > cost[x][y] + 0) {
                cost[x + dx.at(i)][y + dy.at(i)] = cost[x][y] + 0;
                pq.emplace(cost[x + dx.at(i)][y + dy.at(i)], x + dx.at(i), y + dy.at(i));
            }
        }

        for(ll i = -2; i <= 2; i++) for(ll j = -2; j<= 2; j++) {
            if(abs(i) * abs(j) == 4) {
                continue;
            }
            if(x + i < 0) {
                continue;
            }
            if(x + i >= H) {
                continue;
            }
            if(y + j < 0) {
                continue;
            }
            if(y + j >= W) {
                continue;
            }
            if(cost[x + i][y + j] > cost[x][y] + 1) {
                cost[x + i][y + j] = cost[x][y] + 1;
                pq.emplace(cost[x + i][y + j], x + i, y + j);
            }
        }
    }
}

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(ll i = 0; i < H; i++) {
        cin >> S.at(i);
    }
    vector<vector<ll>> cost(H, vector<ll>(W, INF));
    dijkstra(H, W, S, cost);
    cout << cost[H - 1][W - 1] << endl;
    return 0;
}