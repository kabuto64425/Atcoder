#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &elm : a) {
        cin >> elm;
    }
    deque<ll> deq;
    for(ll i = 0; i < n; i++) {
        if(i % 2 == 0) {
            deq.push_back(a[i]);
        } else {
            deq.push_front(a[i]);
        }
    }
    if(deq.size() % 2 == 0) {
        while(!deq.empty()) {
            ll elm = deq.front();
            cout << elm << " ";
            deq.pop_front();
        }
    } else {
        while(!deq.empty()) {
            ll elm = deq.back();
            cout << elm << " ";
            deq.pop_back();
        }
    }
    cout << endl;
    return 0;
}