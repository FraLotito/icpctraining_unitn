//https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define mp make_pair
using namespace std;

using ll = long long;
using ii = pair<int, int>;
const int INF = (int)10e9;
int N;
vector<int> v;
vector<int> dp;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v.resize(N);
    dp.resize(N);
    fill(all(dp), 0);

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = 1; i < N; i++) {
        if(i == 1) dp[i] = abs(v[i] - v[i-1]);
        else dp[i] = min(abs(v[i] - v[i-1]) + dp[i-1], abs(v[i] - v[i-2]) + dp[i-2]);
    }

    cout << dp[N-1] << endl;

    return 0;
}
