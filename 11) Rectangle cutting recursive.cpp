#include<bits/stdc++.h>

using namespace std;

#define int long long


signed main() {

    int a, b; cin >> a >> b;
    vector<vector<int>> dp(501, vector<int>(501, -1));

    function<int(int, int)> recur = [&](int x, int y) -> int {

        if(x == y) return 0;

        if(dp[x][y] != -1) return dp[x][y];
        if(dp[y][x] != -1) return dp[y][x];
        int pick = INT_MAX;

        for(int i = 1; i < x; i++) {
            pick = min(pick, recur(x - i, y) + recur(i, y) + 1);
        }

        for(int j = 1; j < y; j++) {
            pick = min(pick, recur(x, y - j) + recur(x, j) + 1);
        }

        return dp[x][y] = pick;
    };

    cout << recur(a, b) << endl;
}
