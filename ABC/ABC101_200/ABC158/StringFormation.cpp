#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    string S;
    cin >> S;
    ll N;
    cin >> N;

    deque<char> Q1;
    deque<char> Q2;

    bool isReverse = false;

    REP(i, N) {
        ll x;
        cin >> x;
        if(x == 1) {
            isReverse = !isReverse;
        } else if(x == 2) {
            ll y;
            cin >> y;
            if(y == 1) {
                char z;
                cin >> z;
                if(isReverse) {
                    Q2.push_back(z);
                } else {
                    Q1.push_back(z);
                }
            } else if(y == 2) {
                char z;
                cin >> z;
                if(isReverse) {
                    Q1.push_back(z);
                } else {
                    Q2.push_back(z);
                }
            }
        }
    }
    if(isReverse) {
        reverse(S.begin(), S.end());
        while(!Q2.empty()) {
            cout << Q2.back();
            Q2.pop_back();
        }
        cout << S;
        while(!Q1.empty()) {
            cout << Q1.front();
            Q1.pop_front();
        }
    } else {
        while(!Q1.empty()) {
            cout << Q1.back();
            Q1.pop_back();
        }
        cout << S;
        while(!Q2.empty()) {
            cout << Q2.front();
            Q2.pop_front();
        }
    }
    cout << endl;
}