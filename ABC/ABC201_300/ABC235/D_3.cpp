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

void bfs(ll x, ll a, vector<ll> &dist) {
    queue<ll> que;
    que.push(x);
    dist.at(x) = 0;
    while(!que.empty()) {
        ll v = que.front();
        que.pop();
        if(v * a <= 1000000) {
            ll nv = v * a;
            if(dist.at(nv) == -1) {
                que.push(nv);
                dist.at(nv) = dist.at(v) + 1;
            }
        }
        if(v >= 10 and v % 10 != 0) {
            string str;
            str += to_string(v % 10);
            str += to_string(v / 10);
            ll nv = stoi(str);
            if(dist.at(nv) == -1) {
                que.push(nv);
                dist.at(nv) = dist.at(v) + 1;
            }
        }
    }
}

int main(){
    ll a, N;
    cin >> a >> N;
    vector<ll> dist(1000000, -1);
    bfs(1, a, dist);
    cout << dist.at(N) << endl;
    return 0;
}