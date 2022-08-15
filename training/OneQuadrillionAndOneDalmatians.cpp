#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char arrayOfChars[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main() {
    //入力
    ll N;
    cin >> N;

    //処理
    ll x = N;

    bool flag = false;

    vector<ll> vec;

    while(true) {
        ll y = x % 26;
        if(flag) {
            y--;
            flag = false;
        }

        if(y <= 0) {
            y += 26;
            flag = true;
        }

        x = x / 26;
        if(x == 0) {
            if(!flag) {
                vec.push_back(y);
            }
            break;
        } else {
            vec.push_back(y);
        }
    }

    reverse(vec.begin(), vec.end());

    string str;

    for(ll element : vec) {
        if(element == 0) {
            continue;
        }

        str += arrayOfChars[element - 1];
    }

    cout << str << endl;
}