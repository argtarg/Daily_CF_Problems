void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>dis(n + 1, vector<int>(n + 1, -1)), g(n + 1);
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	vector<int>vis(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
		queue<int>q;
		q.push(i);
		while (q.size()) {
			int x = q.front();
			q.pop();
			for (int j : g[x]) {
				if (vis[j] == -1) {
					q.push(j);
					vis[j] = vis[x] + 1;
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			dis[i][j] = vis[j];
			vis[j] = -1;
		}
	}
	vector<priority_queue<pii, vector<pii>, greater<pii>>>q(n + 1), q2(n + 1);
	vector<array<int, 3>>ar(n + 1), ar2(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || dis[i][j] == -1)continue;
			q[i].push({ dis[i][j],j });
			if (q[i].size() > 3)q[i].pop();
			q2[j].push({ dis[i][j],i });
			if (q2[j].size() > 3)q2[j].pop();
		}
		while (q[i].size()) {
			ar[i][q[i].size() - 1] = q[i].top().second;
			q[i].pop();
		}
	}
	for (int i = 1; i <= n; i++) {
		while (q2[i].size()) {
			ar2[i][q2[i].size() - 1] = q2[i].top().second;
			q2[i].pop();
		}
	}
	int ans = 0;
	array<int, 4>ansi;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || dis[i][j] == -1)continue;
			int tmp = dis[i][j];
			for (int ki = 0; ki < 3; ki++) {
				for (int mi = 0; mi < 3; mi++) {
					int k = ar2[i][ki], m = ar[j][mi];
					if (k == i || k == j || m == k || m == i || m == j || m * k == 0)continue;
					int cnt = tmp + dis[k][i] + dis[j][m];
					if (ans < cnt) {
						ans = cnt;
						ansi = { k,i,j,m };
					}

				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		cout << ansi[i];
		if (i != 3)cout << ' ';
	}
}
