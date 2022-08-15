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

int main(){
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<vector<ll>> v(26, vector<ll>(N, N));
    for(ll i = 0; i < N; i++) {
        char c = S.at(i);
        v.at(c - 'a').at(i) = i;
    }

    for(ll i = 0; i < 26; i++) {
        for(ll j = N - 2; j >= 0; j--) {
            v.at(i).at(j) = min(v.at(i).at(j), v.at(i).at(j + 1));
        }
    }
    
    queue<char> ans;
    ll p = 0;
    for(ll i = 0; i < K; i++) {
        for(ll j = 0; j < 26; j++) {
            if(N - (v.at(j).at(p) + 1) >= K - (i + 1)) {
                ans.push((char)('a' + j));
                p = v.at(j).at(p);
                break;
            }
        }
        p++;
    }
    while(!ans.empty()) {
        cout << ans.front();
        ans.pop();
    }
    cout << endl;
    return 0;
}