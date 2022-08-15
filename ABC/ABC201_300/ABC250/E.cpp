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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    ll Q;
    cin >> Q;
    vector<ll> x(Q), y(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> x.at(i) >> y.at(i);
    }

    set<ll> setA, setB;
    vector<ll> sizesA(N), sizesB(N);
    vector<ll> appearedOrderA, appearedOrderB;
    for(ll i = 0; i < N; i++) {
        if(!setA.count(A.at(i))) {
            appearedOrderA.push_back(A.at(i));
        }
        if(!setB.count(B.at(i))) {
            appearedOrderB.push_back(B.at(i));
        }
        setA.insert(A.at(i));
        setB.insert(B.at(i));
        sizesA.at(i) = setA.size();
        sizesB.at(i) = setB.size();
    }

    set<ll> setS;
    vector<ll> sizesS;
    for(ll i = 0; i < min(appearedOrderA.size(), appearedOrderB.size()); i++) {
        if(setS.count(appearedOrderA.at(i))) {
            setS.erase(appearedOrderA.at(i));
        } else {
            setS.insert(appearedOrderA.at(i));
        }
        if(setS.count(appearedOrderB.at(i))) {
            setS.erase(appearedOrderB.at(i));
        } else {
            setS.insert(appearedOrderB.at(i));
        }
        sizesS.push_back(setS.size());
    }

    for(ll i = 0; i < Q; i++) {
        ll indexA = x.at(i) - 1;
        ll indexB = y.at(i) - 1;
        if(sizesA.at(indexA) != sizesB.at(indexB)) {
            cout << "No" << endl;
            continue;
        }
        ll k = sizesA.at(indexA);
        if(sizesS.at(k - 1) != 0) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}