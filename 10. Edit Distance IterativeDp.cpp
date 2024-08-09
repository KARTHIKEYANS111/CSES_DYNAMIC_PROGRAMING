#include <bits/stdc++.h>
using namespace std;

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t; cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 1e9));

    // dp[i][j] : Stores the edit distance of 
    // first i chars in s and first j chars in t

    // Base case :

    // If size of s becomes 0 or size of t 
    // becomes 0 then dp[i][0] and dp[0]][j] becomes i and j.

    for(int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    for(int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            char x = s[i - 1];
            char y = t[j - 1];

            if(x == y) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1, dp[i - 1][j] + 1});
            }

        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
