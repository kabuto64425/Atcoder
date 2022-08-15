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
    vector<vector<ll>> gS(N, vector<ll>(N));
    vector<vector<ll>> gT(N, vector<ll>(N));
    ll countS = 0;
    ll countT = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            if(S.at(i).at(j) == '#') {
                gS.at(i).at(j) = 1;
                countS++;
            } else {
                gS.at(i).at(j) = 0;
            }
            if(T.at(i).at(j) == '#') {
                gT.at(i).at(j) = 1;
                countT++;
            } else {
                gT.at(i).at(j) = 0;
            }
        }
    }
    if(countS != countT) {
        cout << "No" << endl;
        return 0;
    }
    for(ll r = 0; r < 4; r++) {
        rotate(N, gT);
        for(ll isT = -N; isT < N; isT++) {
            for(ll jsT = -N; jsT < N; jsT++) {
                bool flag = true;
                for(ll i = 0; i < N; i++) {
                    for(ll j = 0; j < N; j++) {
                        ll iT = isT + i;
                        ll jT = jsT + j;
                        if(iT < 0 or jT < 0 or iT >= N or jT >= N) {
                            if(gS.at(i).at(j) == 1) {
                                flag = false;
                                break;
                            }
                        }else if(gS.at(i).at(j) != gT.at(iT).at(jT)) {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) {
                        break;
                    }
                }
                if(flag) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}