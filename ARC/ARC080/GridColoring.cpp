#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W;
    cin >> H >> W;
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    queue<ll> que;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < A[i]; j++) {
            que.push(i + 1);
        }
    }
    vector<vector<ll>> grid(H, vector<ll>(W));
    for(ll i = 0; i < H; i++) {
        if(i % 2 == 0) {
            for(ll j = 0; j < W; j++) {
                grid[i][j] = que.front();
                que.pop();
            }
        } else {
            for(ll j = W - 1; j >= 0; j--) {
                grid[i][j] = que.front();
                que.pop();
            }
        }
    }
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
                cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}