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

const vector<char> dc = {'L', 'U', 'R', 'D'};
const vector<ll> di = {0, -1, 0, 1};
const vector<ll> dj = {-1, 0, 1, 0}; 

int main(){
    ll N, si, sj;
    cin >> N >> si >> sj;
    vector<string> c(N);
    for(ll i = 0; i < N; i++) {
        cin >> c.at(i);
    }
    stack<tuple<ll, ll, ll>> trace;
    pair<ll, ll> pos = {si, sj};
    vector<vector<bool>> seen(N, vector<bool>(N));
    seen.at(pos.first).at(pos.second) = true;
    string ans = "";
    while(true) {
        bool flag = false;
        for(ll i = 0; i < 4; i++) {
            ll x = pos.first + di.at(i);
            ll y = pos.second + dj.at(i);
            if(x < 0 or x >= N) {
                continue;
            }
            if(y < 0 or y >= N) {
                continue;
            }
            if(c.at(x).at(y) == '#') {
                continue;
            }
            if(seen.at(x).at(y)) {
                continue;
            }
            trace.push({pos.first, pos.second, i});
            pos = {x, y};
            seen.at(x).at(y) = true;
            ans += dc.at(i);
            flag = true;
            break;
        }
        if(!flag) {
            tuple<ll, ll, ll> pre = trace.top();
            trace.pop();
            ll d = (get<2>(pre) + 2) % 4;
            ll x = pos.first + di.at(d);
            ll y = pos.second + dj.at(d);
            pos = {x, y};
            seen.at(x).at(y) = true;
            ans += dc.at(d);
        }
        if(trace.empty()) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}