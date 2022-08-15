#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //入力
    ll N;
    cin >> N;
    vector<ll> vec;
    for(ll i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            vec.push_back(i);
            vec.push_back(N / i);
        }
    }
    sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    for(ll i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << endl;
    }
}