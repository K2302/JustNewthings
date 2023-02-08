    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = 0;
    for (int i = 0; i < 31; i++)
    {
        int cnt[2];
        cnt[0] = cnt[1] = 0;

        for (int j = 0; j < n; j++)
        {
            cnt[(v[j] >> i) & 31]++;
        }
        int numpairs = (cnt[1]*(cnt[1]-1))/2;
        ans+=numpairs*(1<<i);
    }
    cout<<ans<<endl;
