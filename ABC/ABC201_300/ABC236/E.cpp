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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

long double solveAverage(ll N, const vector<ll> &A) {
    long double ok = 1;
    long double ng = INF;
    while(abs(ok - ng) >= 1e-5) {
        long double mid = (ok + ng) / 2;
        vector<long double> B(N);
        for(ll i = 0; i < N; i++) {
            B.at(i) = (long double)A.at(i) - mid;
        }
        vector<vector<long double>> dp(N + 1, vector<long double>(2, -INF));
        dp.at(0).at(0) = 0;
        dp.at(0).at(1) = 0;
        for(ll i = 0; i < N; i++) {
            // 取る
            chmax(dp.at(i + 1).at(1), dp.at(i).at(1) + B.at(i));
            chmax(dp.at(i + 1).at(1), dp.at(i).at(0) + B.at(i));
            // 取らない
            chmax(dp.at(i + 1).at(0), dp.at(i).at(1));
        }
        long double res = max(dp.at(N).at(0), dp.at(N).at(1));
        if(res >= 0) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

ll solveMedian(ll N, const vector<ll> &A) {
    ll ok = 1;
    ll ng = INF;
    while(abs(ok - ng) != 1) {
        ll mid = (ok + ng) / 2;
        bool flag = true;
        ll count = 0;
        for(ll i = 0; i < N; i++) {
            if(A.at(i) >= mid) {
                flag = true;
                count++;
            } else {
                if(flag) {
                    flag = false;
                } else {
                    flag = true;
                    count--;
                }
            }
        }
        if(count >= 1) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    cout << fixed << setprecision(20) << solveAverage(N, A) << endl;
    cout << solveMedian(N, A) << endl;
    return 0;
}