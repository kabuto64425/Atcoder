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

    do {
        vector<ll> ans;
        for(ll i = 0; i < N; i++) {
            ll dx = B.at(i).first - A.at(i).first;
            ll dy = B.at(i).second - A.at(i).second;
            bool flag = false;
            for(ll j = 0; j < 8; j++) {
                if(make_pair(A.at(i).first + uv.at(j).first * T, A.at(i).second + uv.at(j).second * T) == B.at(i)) {
                    flag = true;
                    ans.push_back(j);
                    break;
                }
            }
            if(!flag) {
                break;
            }
        }
        if(ans.size() == N) {
            cout << "Yes" << endl;
            for(ll i = 0; i < N; i++) {
                cout << ans.at(i) + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    } while (next_permutation(ALL(B)));

    cout << "No" << endl;

    return 0;
}