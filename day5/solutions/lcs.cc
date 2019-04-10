#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define mp make_pair
using namespace std;

using ll = long long;
using ii = pair<int, int>;
const int INF = (int)10e9;

int dp[3005][3005];

string res = "";
string s, t;

void reconstruct(int i, int j) {
    if(i <= 0 || j <= 0) return;
    if(s[i-1] == t[j-1]) {
        res = s[i-1] + res;
        reconstruct(i-1, j-1);
    } else {
        if(dp[i-1][j] > dp[i][j-1]) reconstruct(i-1, j);
        else reconstruct(i, j-1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> s >> t;

    for(int i = 1; i <= s.length(); i++) {
        for(int j = 1; j <= t.length(); j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    reconstruct(s.length(), t.length());
    cout<<res<<endl;

    return 0;
}
