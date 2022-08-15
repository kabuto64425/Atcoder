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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> x(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> x.at(i);
    }
    vector<ll> vec1(N + 1), vec2(N + 1);
    for(ll i = 1; i <= N; i++) {
        vec1.at(i) = i;
        vec2.at(i) = i;
    }
    for(ll i = 0; i < Q; i++) {
        ll num1 = x.at(i);
        ll index1 = vec1.at(num1);
        ll index2 = index1;
        if(index1 == N) {
            index2--;
        } else {
            index2++;
        }
        ll num2 = vec2.at(index2);
        swap(vec1.at(num1), vec1.at(num2));
        swap(vec2.at(index1), vec2.at(index2));
    }
    for(ll i = 1; i <= N; i++) {
        cout << vec2.at(i) << " ";
    }
    cout << endl;
    return 0;
}