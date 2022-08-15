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
    ll N;
    cin >> N;
    vector<string> w(N);
    for(string &elm : w) {
        cin >> elm;
        transform(elm.begin(), elm.end(), elm.begin(), ::tolower);
    }
    bool flag = false;
    for(const string &elm : w) {
        string s = "";
        for(const char &c : elm) {
            if(c == 'b' or c == 'c') {
                s += '1';
            }
            if(c == 'd' or c == 'w') {
                s += '2';
            }
            if(c == 't' or c == 'j') {
                s += '3';
            }
            if(c == 'f' or c == 'q') {
                s += '4';
            }
            if(c == 'l' or c == 'v') {
                s += '5';
            }
            if(c == 's' or c == 'x') {
                s += '6';
            }
            if(c == 'p' or c == 'm') {
                s += '7';
            }
            if(c == 'h' or c == 'k') {
                s += '8';
            }
            if(c == 'n' or c == 'g') {
                s += '9';
            }
            if(c == 'z' or c == 'r') {
                s += '0';
            }
        }
        if(s != "") {
            if(flag) {
                cout << " ";
            } else {
                flag = true;
            }
            cout << s;
        }
    }
    cout << endl;
    return 0;
}