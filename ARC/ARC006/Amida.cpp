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
    ll N, L;
    cin >> N >> L;
    cin.ignore();
    vector<string> S(L + 1);
    for(string &s : S) {
        getline(cin, s);
    }
    ll position = 0;
    for(ll i = 0; i < S.at(L).length(); i++) {
        if(S.at(L).at(i) == 'o') {
            position = (i / 2) + 1;
        }
    }

    vector<vector<bool>> left(L, vector<bool>(N + 1, false));
    vector<vector<bool>> right(L, vector<bool>(N + 1, false));
    for(ll i = 0; i < L; i++) {
        for(ll j = 1; j < S.at(i).length(); j += 2) {
            if(S.at(i).at(j) == '-') {
                left.at(i).at((j + 3) / 2) = true;
                right.at(i).at((j + 1) / 2) = true;
            }
        }
    }
    for(ll i = L - 1; i >= 0; i--) {
        if(left.at(i).at(position)) {
            position--;
            continue;
        }
        if(right.at(i).at(position)) {
            position++;
            continue;
        }
    }
    cout << position << endl;
    return 0;
}