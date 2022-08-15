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
    ll N;
    cin >> N;
    vector<string> S(N);
    for(ll i = 0; i < N; i++) {
        cin >> S.at(i);
    }
    // 横
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N - 5; j++) {
            ll count = 0;
            for(ll k = 0; k < 6; k++) {
                if(S.at(i).at(j + k) == '.') {
                    count++;
                }
            }
            if(count <= 2) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    // 縦
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N - 5; j++) {
            ll count = 0;
            for(ll k = 0; k < 6; k++) {
                if(S.at(j + k).at(i) == '.') {
                    count++;
                }
            }
            if(count <= 2) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    // 斜め
    for(ll i = 0; i < N; i++) {
        if(N - i < 6) {
            continue;
        }
        for(ll j = 0; j < N - i - 5; j++) {
            ll count = 0;
            for(ll k = 0; k < 6; k++) {
                if(S.at(j + k).at(i + j + k) == '.') {
                    count++;
                }
            }
            if(count <= 2) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    for(ll i = 0; i < N; i++) {
        if(N - i < 6) {
            continue;
        }
        for(ll j = 0; j < N - i - 5; j++) {
            ll count = 0;
            for(ll k = 0; k < 6; k++) {
                if(S.at(i + j + k).at(i + k) == '.') {
                    count++;
                }
            }
            if(count <= 2) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    for(ll i = 0; i < N; i++) {
        reverse(ALL(S.at(i)));
    }

    // 斜め
    for(ll i = 0; i < N; i++) {
        if(N - i < 6) {
            continue;
        }
        for(ll j = 0; j < N - i - 5; j++) {
            ll count = 0;
            for(ll k = 0; k < 6; k++) {
                if(S.at(j + k).at(i + j + k) == '.') {
                    count++;
                }
            }
            if(count <= 2) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    for(ll i = 0; i < N; i++) {
        if(N - i < 6) {
            continue;
        }
        for(ll j = 0; j < N - i - 5; j++) {
            ll count = 0;
            for(ll k = 0; k < 6; k++) {
                if(S.at(i + j + k).at(i + k) == '.') {
                    count++;
                }
            }
            if(count <= 2) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}