#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define int long long

#define N 200100
int tr[N];
int n, mod;
void add(int x, int c) {
	for (int i = x; i <= n; i += (i & -i)) {
		tr[i] = (tr[i] + c) % mod;
	}
}
int sum(int x) {
	int res = 0;
	for (int i = x; i; i -= (i & -i)) {
		res = (res + tr[i]) % mod;
	}
	return res;
}
void solve() {

	cin >> n >> mod;
	vector<int>dp(n + 1);
	vector<int>pre(n + 1);
	
	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] += pre[i - 1];
		dp[i] += sum(i);
		dp[i] %= mod;
		for (int j = i + i; j <= n; j += i) {
			add(j, dp[i]);
		}
		for (int j = i + i + 2; j <= n; j += i + 1) {
			add(j, -dp[i]);
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
