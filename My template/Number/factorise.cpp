const int N = 10000005;
vll spf(N + 1, 1);
void sieve()
{
    int i, j;
    fl(i, 2, N)
    {
        if (spf[i] == 1)
        {
            spf[i] = i;
            for (j = i * i; j <= N; j += i)
            {
                if (spf[j] == 1)spf[j] = i;
            }
        }
    }
}

vll factorize(int n)
{
    vll ans;
    while (n > 1)
    {
        int fact = spf[n];
        while (n % fact == 0)
        {
            n /= fact;
        }
        ans.pb(fact);
    }
    return ans;
}
