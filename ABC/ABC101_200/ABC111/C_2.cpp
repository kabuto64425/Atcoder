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

bool comp_by_second(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second > b.second;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll &elm : v) {
        cin >> elm;
    }
    vector<pair<ll, ll>> A(110000);
    vector<pair<ll, ll>> B(110000);
    for(ll i = 1; i <= 100000; i++) {
        A.at(i).first = i;
        B.at(i).first = i;
    }
    for(ll i = 0; i < n; i++) {
        if(i % 2 == 0) {
            A.at(v.at(i)).second++;
        } else {
            B.at(v.at(i)).second++;
        }
    }
    sort(A.begin(), A.end(), comp_by_second);
    sort(B.begin(), B.end(), comp_by_second);
    if(A.at(0).first != B.at(0).first) {
        cout << n - A.at(0).second - B.at(0).second << endl;
    } else {
        if(A.at(0).second > B.at(0).second) {
            cout << n - A.at(0).second - B.at(1).second << endl;
        } else if (A.at(0).second < B.at(0).second) {
            cout << n - A.at(1).second - B.at(0).second << endl;
        } else {
            if(A.at(1).second > B.at(1).second) {
                cout << n - A.at(1).second - B.at(0).second << endl;
            } else {
                cout << n - A.at(0).second - B.at(1).second << endl;
            }
        }
    }
    return 0;
}