#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n = 5e4 + 5,k = 505;
vvl dp(n,vl(k));
vvi adj(n);
ll ans = 0;

void dfs(int u,int p)
{
    dp[u][0] = 1;

    //dp[u][i] is no of nodes at dist i FROM u in subtree of u

    for (int v:adj[u]){
        if (v == p)continue;
        dfs(v,u);

        for (int x = 1;x<=k;x++)
            dp[u][x] += dp[v][x - 1];
    }
    
    ans += dp[u][k]; //go k dist end at u

    ll tot = 0;
    
    for (int v:adj[u]){
        if (v == p)continue;
        
        for (int x = 1;x<=k - 1;x++)
            tot += dp[v][x - 1] * (dp[u][k - x] - dp[v][k - x - 1]); //we dont want dist of k-x from sbutree of v
            //go x from one side ->
            //go to u -> go k-x another side
        
    }

    ans += tot/2;
}

int main()
{
    fast
    cin>>n>>k;

    for (int i = 1;i<=n - 1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }

    dfs(1,-1);

    //cout<<(dp[2][3]);

    cout<<ans;
    return 0;
}