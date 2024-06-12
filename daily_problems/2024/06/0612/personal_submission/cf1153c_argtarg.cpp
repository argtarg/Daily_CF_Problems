void solve() {
	int n;
	string s;
	cin >> n >> s;
	if (n & 1) {
		cout << ":(\n";
		return;
	}
	stack<int>st;
	int cnt = 0;
	int f = n - 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')cnt++;
	}
	cnt = n / 2 - cnt;
	string ans;
	for (int i = 0; i < n; i++) {

		if (cnt > 0 && s[i] == '?') {
			cnt--;
			st.push('(');
			ans += st.top();
		}
		else if (s[i] == '(') {
			st.push('(');
			ans += st.top();
		}
		else {
			ans += ')';
			if (st.size() == 0) {
				f = 0;
				break;
			}
			else if (st.size() == 1) {
				f = i;
				st.pop();
				break;
			}
			else {
				st.pop();
			}
		}

	}
	if (f == n - 1 && st.size() == 0)cout << ans << endl;
	else cout << ":(\n";
}
