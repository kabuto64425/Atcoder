#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

bool isMonth(int num) {
    return num >= 1 and num <= 12;
}

int main(){
    string S;
    cin >> S;
    string firstHalf = S.substr(0, 2);
    string latterHalf = S.substr(2, 2);
    int firstHalfInt = atoi(firstHalf.c_str());
    int latterHalfInt = atoi(latterHalf.c_str());

    if(isMonth(firstHalfInt) and isMonth(latterHalfInt)) {
        cout << "AMBIGUOUS" << endl;
        return 0;
    }

    if(isMonth(firstHalfInt)) {
        cout << "MMYY" << endl;
        return 0;
    }

    if(isMonth(latterHalfInt)) {
        cout << "YYMM" << endl;
        return 0;
    }

    cout << "NA" << endl;
    return 0;
}