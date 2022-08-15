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

void rotate(ll N, vector<vector<ll>> &v) {
    for (ll i = 0; i < N / 2; i++) {
        for (ll j = i; j < N - i - 1; j++) {
            ll temp = v[i][j];
            v[i][j] = v[N - 1 - j][i];
            v[N - 1 - j][i] = v[N - 1 - i][N - 1 - j];
            v[N - 1 - i][N - 1 - j] = v[j][N - 1 - i];
            v[j][N - 1 - i] = temp;
        }
    }
}

pair<ll, ll> getTopLeft(ll N, const vector<vector<ll>> &v) {
    for(ll i = 0 ; i < N ; i ++) {
        for(ll j = 0 ; j < N ; j ++) {
            if(v[i][j] == 1) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    for(ll i = 0; i < N; i++) {
        cin >> S.at(i);
    }
    vector<string> T(N);
    for(ll i = 0; i < N; i++) {
        cin >> T.at(i);
    }
    vector<vector<ll>> grid1(N, vector<ll>(N));
    ll count1 = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            if(S.at(i).at(j) == '#') {
                grid1.at(i).at(j) = 1;
                count1++;
            } else {
                grid1.at(i).at(j) = 0;
            }
        }
    }
    vector<vector<ll>> grid2(N, vector<ll>(N));
    ll count2 = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            if(T.at(i).at(j) == '#') {
                grid2.at(i).at(j) = 1;
                count2++;
            } else {
                grid2.at(i).at(j) = 0;
            }
        }
    }
    if(count1 != count2) {
        cout << "No" << endl;
        return 0;
    }
    for(ll r = 0; r < 4; r++) {
        rotate(N, grid1);
        pair<ll, ll> topLeft1 = getTopLeft(N, grid1);
        pair<ll, ll> topLeft2 = getTopLeft(N, grid2);
        ll diffVertical = topLeft2.first - topLeft1.first;
        ll diffHorizontal = topLeft2.second - topLeft1.second;
        bool flag = true;
        for(ll i = 0; i < N; i++) {
            for(ll j = 0; j < N; j++) {
                if(i - diffVertical < 0 or i - diffVertical >= N) {
                    if(grid2.at(i).at(j) == 1) {
                        flag = false;
                        break;
                    } else {
                        continue;
                    }
                }
                if(j - diffHorizontal < 0 or j - diffHorizontal >= N) {
                    if(grid2.at(i).at(j) == 1) {
                        flag = false;
                        break;
                    } else {
                        continue;
                    }
                }
                if(grid1.at(i - diffVertical).at(j - diffHorizontal) != grid2.at(i).at(j)) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}