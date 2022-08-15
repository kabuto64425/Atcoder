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
    string N;
    cin >> N;
    ll K;
    cin >> K;
    for(ll i = 0; i < K; i++) {
        string T;
        ll deg = 0;
        for(ll j = 0; j < (ll) N.length(); j++) {
            deg *= 8;
            deg += (N.at(j) - '0');
        }
        stack<char> s;
        if(deg == 0) {
            s.push('0');
        } else {
            while(deg > 0) {
                s.push((char)(deg % 9) + '0');
                deg /= 9;
            }
        }
        while(!s.empty()) {
            if(s.top() == '8') {
                T += '5';
            } else {
                T += s.top();
            }
            s.pop();
        }
        N = T;
    }
    cout << N << endl;
    return 0;
}