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
const ll mod = 998244353,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n = 3e5 + 5,m;
vvi adj(n);
vi col(n,-1);//either 0 or 1 and -1 signals unvisited node
vb vis(n);//a visited array because this undirected graph is not neccessarily a tree
vl power2(n,1);//initialize powers of 2 with 1's
ll c0,c1;//count of the # of 0's and the # of 1's

bool dfs(int u)
{
    vis[u] = 1;
    for (int v:adj[u]){
        if (col[v] == col[u])return false;//graph is not bipartite
        if (!vis[v]){
            col[v] = !col[u];
            if (col[v])c1++;
            else c0++;
            
            if (!dfs(v))return false;
        }
    }
    return true;
}
void solve()
{
    ll ans = 1;//the final answer
    for (int i = 1;i<=n;i++){
        if (!vis[i]){
            //assign node i a color (arbitarily)
            c0 = 0;
            c1 = 1;
            col[i] = 1;
            if (!dfs(i)){ans = 0;break;}
            else{
                ans = (ans * (power2[c0] + power2[c1])%mod)%mod;
                //power2 array which stores the powers of 2
            }
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    for (int i = 1;i<n;i++)power2[i] = (power2[i - 1] * 2)%mod;
    int t;
    cin>>t;
    while (t--){
        cin>>n>>m;
        for (int i = 1;i<=n;i++)adj[i].clear(),col[i] = -1,vis[i] = false;
        while (m--){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v),adj[v].pb(u);
        }
        solve();
    }
    return 0;
}