#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
#define endl "\n"
 
int n;
vector<int> arr;
set<int> ans;
 
vector<vector<int>> dp;
 
void recur(int idx, int s) {
    if(idx > n) return;
 
    if(ans.find(s) == ans.end() and s != 0) {
        ans.insert(s);
    } 
 
    if(dp[idx][s] != -1) return;
 
    dp[idx][s] = 1;
 
    recur(idx + 1, s + arr[idx]);
    recur(idx + 1, s);
 
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
 
    arr.resize(n);
 
    dp.resize(n + 1, vector<int>(1e5 + 1, -1));
 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];           
    }
 
    recur(0, 0);
 
    cout << ans.size() << endl;
 
    for(auto it : ans) cout << it << " ";
 
 
    return 0;
}
