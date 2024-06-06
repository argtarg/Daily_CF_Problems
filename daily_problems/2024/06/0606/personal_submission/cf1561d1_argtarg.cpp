#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define int long long

void solve() {
	int n, mod;
	cin >> n >> mod;
	vector<int>dp(n + 1);
	vector<int>pre(n + 1);
	dp[1] = 1;
	vector<int>sum(n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i] += pre[i - 1];
		sum[i] = (sum[i] + sum[i - 1]) % mod;
		dp[i] += sum[i];
		dp[i] %= mod;
		for (int j = i + i; j <= n; j += i) {
			sum[j] += dp[i];
			sum[j] %= mod;
		}
		for (int j = i + i + 2; j <= n; j += i + 1) {
			sum[j] -= dp[i];
			sum[j] %= mod;
		}
		pre[i] = pre[i - 1] + dp[i];
		pre[i] %= mod;
	}
	cout << (dp[n]+mod)%mod << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	//cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
