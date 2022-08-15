#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    vector<string> vec(N);
    for(ll i = 0; i < N; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());
    map<string, ll> map;
    ll currentMax = 0;
    for(ll i = 0; i < N; i++) {
        string key = vec.at(i);
        if(map.find(key) == map.end()) {
            map[key] = 1;
        } else {
            map.at(key) += 1;
        }
        currentMax = max(currentMax, map.at(key));
    }

    vector<string> answers();
    for (auto elm : map) {
        if(elm.second == currentMax) {
           cout << elm.first << endl;
        }
    }
}