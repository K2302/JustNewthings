#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int mod=1e9+7;

int binary_expo(int a,int b){int ans=1;while(b){if(b&1){ans=(ans*a)%mod; }a=(a*a)%mod;b>>=1; }return ans;}int inv(int a){ return binary_expo(a,mod-2);}int add(int a,int b){return (((a+b)%mod)+mod)%mod;}
int sub(int a,int b){ return (((a-b)%mod)+mod)%mod;}int mul(int a,int b){ return (a*b)%mod;}

vector<vector<int>> g;
int parent[100001][20],depth[1000000];
int dp[100001][20];
vector<int> v;

int gcd(int a,int b)
{
	return __gcd(a,b);
}

void dfs(int node,int par,int dep)
{
	parent[node][0]=par;
	depth[node]=dep;
	dp[node][0]=v[node];
	for(int i=1;i<20;i++)
	{
		parent[node][i]=parent[parent[node][i-1]][i-1];
		dp[node][i]=gcd(dp[node][i-1],dp[parent[node][i-1]][i-1]);
	}
	for(auto it:g[node])
	{
		if(it!=par)
		{
			dfs(it,node,dep+1);
		}
	}
}

int lca(int a,int b)
{
	if(depth[a]<depth[b])
	{
		swap(a,b);
	}
	int ans=0;
	for(int i=19;i>=0;i--)
	{
		if((depth[a]-depth[b])&(1<<i))
		{
			ans=gcd(ans,dp[a][i]);
			a=parent[a][i];
		}
	}
	if(a==b)return gcd(ans,dp[a][0]);
	for(int i=19;i>=0;i--)
	{
		if(parent[a][i]!=parent[b][i])
		{
			ans=gcd(ans,dp[a][i]);
			ans=gcd(ans,dp[b][i]);
			a=parent[a][i];
			b=parent[b][i];
		}
	}
	return gcd(gcd(v[a],v[b]),gcd(ans,dp[parent[a][0]][0]));
}

void solve()
{
	int n;
	cin>>n;
	g.resize(n+1);
	v.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0,0);
	g.clear();
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<endl;
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
           solve();
    return 0;
}
