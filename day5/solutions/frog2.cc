//https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define mp make_pair
using namespace std;

using ll = long long;
using ii = pair<int, int>;
const int INF = (int)10e9;
int N, K;
vector<int> v;
vector<int> dp;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    v.resize(N);
    dp.resize(N);
    fill(all(dp), 0);

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = 1; i < N; i++) {
        dp[i] = INF;
        for(int j = 1; j <= K; j++) {
            if(i - j >= 0) dp[i] = min(dp[i], abs(v[i] - v[i-j]) + dp[i-j]);
        }
    }

    cout << dp[N-1] << endl;

    return 0;
}
