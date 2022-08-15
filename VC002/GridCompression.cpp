#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> a(H);
    for(ll i = 0; i < H; i++) {
        cin >> a.at(i);
    }

    vector<bool> line(W);

    for(ll i = 0; i < W; i++) {
        bool flag = false;
        for(ll j = 0; j < H; j++) {
            if(a.at(j).at(i) != '.') {
                flag = true;
                break;
            }
        }
        line.at(i) = flag;
    }

    vector<bool> row(H);

    for(ll i = 0; i < H; i++) {
        bool flag = false;
        for(ll j = 0; j < W; j++) {
            if(a.at(i).at(j) != '.') {
                flag = true;
                break;
            }
        }
        row.at(i) = flag;
    }

    for(ll i = 0; i < H; i++) {
        if(row.at(i)) {
            for(ll j = 0; j < W; j++) {
                if(line.at(j)) {
                    cout << a.at(i).at(j);
                }
            }
            cout << endl;
        }
    }
}