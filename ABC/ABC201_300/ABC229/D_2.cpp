#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    string S;
    cin >> S;
    ll K;
    cin >> K;
    // '.'の位置(文字列の両外も1つずつ'.'としてposに追加しておく)
    vector<ll> pos;
    // 左外
    pos.push_back(0);
    for(ll i = 0; i < (ll) S.length(); i++) {
        if(S.at(i) == '.') {
            pos.push_back(i + 1);
        }
    }
    // 右外
    pos.push_back((ll)(S.length() + 1));
    // 区間の長さ
    ll d = min((ll)(pos.size() - 1), K + 1);
    ll ans = 0;
    // (区間の右端-1)がから(区間の左端+1)で、.をK個'X'に変えたときの'X'の長さを求める
    for(ll i = 0; i + d < pos.size(); i++) {
        ans = max(ans, (pos.at(i + d) - 1) - (pos.at(i) + 1) + 1);
    }
    cout << ans << endl;
    return 0;
}