int cnt1, cnt2;
vector<int> col;
bool status = true;
vector<vector<pair<int, int>>> g;
void dfs(int src, int color)
{
	if (color)
		cnt1++;
	else
		cnt2++;
	col[src] = color;
	for (auto x : g[src])
	{
		if (col[x.F] != -1)
		{
			if ((col[x.F] ^ color) != x.S)
			{
				status = false;
				return;
			}
			continue;
		}
		dfs(x.F, x.S ^ color);
	}
}
void Shaan()
{
	// test case analyse kro and then start kro solve krna...khud se ustadi nhiiiiii
	// dont forget to clear if you are using global variable
	int n, q;
	cin >> n >> q;
	col.assign(n + 1, -1);
	g.assign(n + 1, {});
	for (int i = 0; i < q; i++)
	{
		int u, v;
		string s;
		cin >> u >> v >> s;
		int c = 0;
		if (s[0] == 'i')
			c = 1;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (col[i] == -1)
		{
			status = true;
			cnt1 = 0, cnt2 = 0;
			dfs(i, 0);
			if (!status)
			{
				cout << -1 << nn;
				return;
			}
			ans += max(cnt1, cnt2);
		}
	}
	cout << ans << nn;
}
