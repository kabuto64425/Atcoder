#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

void dfs(ll pos, ll last, string str, const ll N, const ll B, ll &ans) {

    if (pos == 0) {
        ll rem = 1;
        for (int i = 0; i < str.size(); i++) {
            rem *= (ll)(str[i] - '0');
        }
        ll goal = rem + B;
        if (goal <= N) {
            string goal_str = to_string(goal);
            sort(goal_str.begin(), goal_str.end());
            reverse(goal_str.begin(), goal_str.end());
            if (goal_str == str) {
                ans += 1;
            }
        }
        return;
    }

    for (ll i = last; i >= 1; i--) {
        string str2 = str;
        str2 += ('0' + i);
        dfs(pos - 1, i, str2, N, B, ans);
    }
}

int main(){
    ll N, B;
    cin >> N >> B;
    ll ans = 0;

    for (ll i = 1; i <= 11; i++) {
        dfs(i, 9, "", N, B, ans);
    }

    string V = to_string(B);
    bool flag = false;
    for (ll i = 0; i < V.size(); i++) {
        if (V[i] == '0') {
            flag = true;
        }
    }
    
    if (flag == true && N >= B) {
        ans += 1;
    }

    cout << ans << endl;

    return 0;
}