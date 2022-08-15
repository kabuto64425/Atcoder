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

const vector<pair<ll, ll>> uv = {
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
    {-1, 0},
    {-1, -1},
    {0, -1},
    {1, -1}
};

int main(){
    ll N, T;
    cin >> N >> T;
    vector<pair<ll, ll>> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i).first >> A.at(i).second;
    }
    vector<pair<ll, ll>> B(N);
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i).first >> B.at(i).second;
    }
    sort(ALL(B));

    for (ll bit = 0; bit < (1 << 3 * N); bit++) {
        ll x = bit;
        vector<ll> oct(N);
        for(ll i = N - 1; i >= 0; i--) {
            oct.at(i) = x % 8;
            x /= 8;
        }
        vector<pair<ll, ll>> Ad;
        for(ll i = 0; i < N; i++) {
            Ad.push_back({A.at(i).first + uv.at(oct.at(i)).first * T, A.at(i).second + uv.at(oct.at(i)).second * T});
        }
        sort(ALL(Ad));
        bool flag = true;
        for(ll i = 0; i < N; i++) {
            if(Ad.at(i).first != B.at(i).first) {
                flag = false;
                break;
            }
            if(Ad.at(i).second != B.at(i).second) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "Yes" << endl;
            for(ll i = 0; i < N; i++) {
                cout << oct.at(i) + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}