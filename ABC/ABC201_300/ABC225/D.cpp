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
    ll N, Q;
    cin >> N >> Q;
    vector<vector<ll>> query(Q);
    for(ll i = 0; i < Q; i++) {
        ll c;
        cin >> c;
        query.at(i).push_back(c);
        if(c == 1) {
            ll x, y;
            cin >> x >> y;
            query.at(i).push_back(x);
            query.at(i).push_back(y);
        }
        if(c == 2) {
            ll x, y;
            cin >> x >> y;
            query.at(i).push_back(x);
            query.at(i).push_back(y);
        }
        if(c == 3) {
            ll x;
            cin >> x;
            query.at(i).push_back(x);
        }
    }
    vector<pair<ll, ll>> linked(N, {-1, -1});
    for(ll i = 0; i < Q; i++) {
        if(query.at(i).at(0) == 1) {
            ll x = query.at(i).at(1);
            ll y = query.at(i).at(2);
            x--;
            y--;
            linked.at(x).second = y;
            linked.at(y).first = x;
        }
        if(query.at(i).at(0) == 2) {
            ll x = query.at(i).at(1);
            ll y = query.at(i).at(2);
            x--;
            y--;
            linked.at(x).second = -1;
            linked.at(y).first = -1;
        }
        if(query.at(i).at(0) == 3) {
            deque<ll> ans;
            ll x = query.at(i).at(1);
            x--;
            ll cur = linked.at(x).first;
            while(cur != -1) {
                ans.push_front(cur);
                cur = linked.at(cur).first;
            }
            ans.push_back(x);
            cur = linked.at(x).second;
            while(cur != -1) {
                ans.push_back(cur);
                cur = linked.at(cur).second;
            }
            cout << ans.size() << " ";
            while(!ans.empty()) {
                cout << (ans.front() + 1) << " ";
                ans.pop_front();
            }
            cout << endl;
        }
    }
    return 0;
}