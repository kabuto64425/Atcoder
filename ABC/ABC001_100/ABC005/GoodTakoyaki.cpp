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
    ll T;
    cin >> T;
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(auto &a: A) {
        cin >> a;
    }
    ll M;
    cin >> M;
    queue<ll> B;
    for(ll i = 0; i < M; i++) {
        ll b;
        cin >> b;
        B.push(b);
    }
    if(M > N) {
        cout << "no" << endl;
        return 0;
    }
    ll b = B.front();
    B.pop();
    for(ll i = 0; i < N; i++) {
        if(b >= A.at(i) && b <= A.at(i) + T) {
            if(B.empty()) {
                cout << "yes" << endl;
                return 0;
            }
            b = B.front();
            B.pop();
        }
    }
    cout << "no" << endl;
    return 0;
}