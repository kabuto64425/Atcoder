#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> AB(N);
    for(ll i = 0; i < N; i++) {
        cin >> AB.at(i).first >> AB.at(i).second;
    }

    sort(AB.begin(), AB.end(), compare_by_b);

    ll sum = 0;
    bool flag = true;

    for(ll i = 0; i < N; i++) {
        sum += AB.at(i).first;
        if(sum > AB.at(i).second) {
            flag = false;
        }
    }

    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}