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

    for(ll i = 0; i < N; i++) {
        string s = vec.at(i);
        sort(s.begin(), s.end());
        vec.at(i) = s;
    }

    sort(vec.begin(), vec.end());

    ll ans = 0;
    ll count = 1;

    for(ll i = 0; i < N - 1; i++) {
        if(vec.at(i) == vec.at(i + 1)) {
            count++;
        } else {
            ans += count * (count - 1) / 2;
            count = 1;
        }
    }

    ans += count * (count - 1) / 2;

    cout << ans << endl;
}