#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n, x;
int arr[101];
const int mod = 1e9 + 7;
vector<int> dp;

int recur(int s) {
    int ways = 0;

    if(s > x) {
        return 0;
    }

    if(s == x) return 1;

    if(dp[s] != -1) return dp[s];

    for(int i = 0; i < n; i++) {
        ways = (ways + recur(s + arr[i])) % mod;
    }
    return dp[s] = ways;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;

    dp.resize(x + 1, - 1);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << recur(0) << endl;


    return 0;
}
