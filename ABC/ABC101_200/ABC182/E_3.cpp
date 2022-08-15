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
    ll H, W, N, M;
    cin >> H >> W >> N >> M;
    vector<ll> A(N), B(N);
    vector<ll> C(M), D(M);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    for(ll i = 0; i < M; i++) {
        cin >> C.at(i) >> D.at(i);
        C.at(i)--;
        D.at(i)--;
    }
    vector<vector<ll>> grid(H, vector<ll>(W));
    for(ll i = 0; i < N; i++) {
        grid.at(A.at(i)).at(B.at(i)) = 1;
    }
    for(ll i = 0; i < M; i++) {
        grid.at(C.at(i)).at(D.at(i)) = 2;
    }
    vector<vector<bool>> isLighted(H, vector<bool>(W));
    bool pre = false;
    for(ll i = 0; i < H; i++) {
        bool pre = false;
        for(ll j = 0; j < W; j++) {
            if(j == 0) {
                if(grid.at(i).at(j) == 1) {
                    isLighted.at(i).at(j) = true;
                    pre = true;
                }
            } else {
                if(grid.at(i).at(j) == 1) {
                    isLighted.at(i).at(j) = true;
                    pre = true;
                } else if(grid.at(i).at(j) == 2) {
                    isLighted.at(i).at(j) = false;
                    pre = false;
                } else {
                    isLighted.at(i).at(j) = isLighted.at(i).at(j) | pre;
                }
            }
        }
    }

    for(ll i = 0; i < H; i++) {
        pre = false;
        for(ll j = W - 1; j >= 0; j--) {
            if(j == W - 1) {
                if(grid.at(i).at(j) == 1) {
                    isLighted.at(i).at(j) = true;
                    pre = true;
                }
            } else {
                if(grid.at(i).at(j) == 1) {
                    isLighted.at(i).at(j) = true;
                    pre = true;
                } else if(grid.at(i).at(j) == 2) {
                    isLighted.at(i).at(j) = false;
                    pre = false;
                } else {
                    isLighted.at(i).at(j) = isLighted.at(i).at(j) | pre;
                }
            }
        }
    }

    for(ll j = 0; j < W; j++) {
        pre = false;
        for(ll i = 0; i < H; i++) {
            if(i == 0) {
                if(grid.at(i).at(j) == 1) {
                    isLighted.at(i).at(j) = true;
                    pre = true;
                }
            } else {
                if(grid.at(i).at(j) == 1) {
                    isLighted.at(i).at(j) = true;
                    pre = true;
                } else if(grid.at(i).at(j) == 2) {
                    isLighted.at(i).at(j) = false;
                    pre = false;
                } else {
                    isLighted.at(i).at(j) = isLighted.at(i).at(j) | pre;
                }
            }
        }
    }

    for(ll j = 0; j < W; j++) {
        pre = false;
        for(ll i = H - 1; i >= 0; i--) {
            if(i == H - 1) {
                if(grid.at(i).at(j) == 1) {
                    isLighted.at(i).at(j) = true;
                    pre = true;
                }
            } else {
                if(grid.at(i).at(j) == 1) {
                    isLighted.at(i).at(j) = true;
                    pre = true;
                } else if(grid.at(i).at(j) == 2) {
                    isLighted.at(i).at(j) = false;
                    pre = false;
                } else {
                    isLighted.at(i).at(j) = isLighted.at(i).at(j) | pre;
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            if(isLighted.at(i).at(j)) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}