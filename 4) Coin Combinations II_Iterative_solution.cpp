THE BELOW GIVES AN RUNTIME ERROR, HENCE WE NEED TO REDUCE THE SPACE

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n, x;
int arr[101];
const int mod = 1e9 + 7;
vector<vector<int>> dp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;

    dp.resize(n + 1, vector<int>(x + 1, 0));

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }   

    for(int i = n - 1; i >= 0; i--) {
        dp[i][0] = 1;
        for(int j = 1; j <= x; j++) {
            int pick = 0;
            if(arr[i] <= j) pick = dp[i][j - arr[i]];
            int notpick = dp[i + 1][j];
            dp[i][j] = (pick + notpick) % mod;
        }
    }

    cout << dp[0][x] << endl;


    return 0;
}
