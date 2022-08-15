#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<ll> nums(M);
    vector<string> results(M);
    for(ll i = 0; i < M; i++) {
        cin >> nums.at(i);
        cin >> results.at(i);
    }

    vector<bool> corrects(N, false);
    vector<ll> penalties(N, false);
    ll ansCorrect = 0;
    ll ansPenalty = 0;
    for(ll i = 0; i < M; i++) {
        if(!corrects.at(nums.at(i) - 1)) {
            if(results.at(i) == "AC") {
                ansCorrect++;
                corrects.at(nums.at(i) - 1) = true;
                ansPenalty += penalties.at(nums.at(i) - 1);
            } else {
                penalties.at(nums.at(i) - 1) += 1;
            }
        }
    }

    cout << ansCorrect << " " << ansPenalty << endl;
}