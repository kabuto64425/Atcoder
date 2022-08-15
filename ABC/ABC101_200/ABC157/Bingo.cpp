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
    vector<vector<pair<ll, bool>>> A(3, vector<pair<ll, bool>>(3));
    for(vector<pair<ll, bool>> &a : A) {
        cin >> a.at(0).first >> a.at(1).first >> a.at(2).first;
    }
    ll N;
    cin >> N;
    vector<ll> B(N);
    for(ll &b : B) {
        cin >> b;
        for(vector<pair<ll, bool>> &a : A) {
            if(b == a.at(0).first) {
                a.at(0).second = true;
            }
            if(b == a.at(1).first) {
                a.at(1).second = true;
            }
            if(b == a.at(2).first) {
                a.at(2).second = true;
            }
        }
    }
    if(A.at(0).at(0).second and A.at(0).at(1).second and A.at(0).at(2).second) {
        cout << "Yes" << endl;
        return 0;
    }
    if(A.at(1).at(0).second and A.at(1).at(1).second and A.at(1).at(2).second) {
        cout << "Yes" << endl;
        return 0;
    }
    if(A.at(2).at(0).second and A.at(2).at(1).second and A.at(2).at(2).second) {
        cout << "Yes" << endl;
        return 0;
    }
    if(A.at(0).at(0).second and A.at(1).at(0).second and A.at(2).at(0).second) {
        cout << "Yes" << endl;
        return 0;
    }
    if(A.at(0).at(1).second and A.at(1).at(1).second and A.at(2).at(1).second) {
        cout << "Yes" << endl;
        return 0;
    }
    if(A.at(0).at(2).second and A.at(1).at(2).second and A.at(2).at(2).second) {
        cout << "Yes" << endl;
        return 0;
    }
    if(A.at(0).at(0).second and A.at(1).at(1).second and A.at(2).at(2).second) {
        cout << "Yes" << endl;
        return 0;
    }
    if(A.at(0).at(2).second and A.at(1).at(1).second and A.at(2).at(0).second) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}