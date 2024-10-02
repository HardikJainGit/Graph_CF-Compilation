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
int n = 2e5 + 5;
vvi adj(n);
vb vis(n);
vi col(n,-1);

void dfs(int u)
{
    vis[u] = 1;
    for (int v:adj[u]){
        if (col[v] == col[u]){//discrepancy
            col[u] = 3;//we can also set col[v] = 3
            continue;
        }
        if (!vis[v]){
            if (col[u] == 1)col[v] = 2;
            else if (col[u] == 2)col[v] = 1;
            else col[v] = 1;//else col[u] == 3 hence set col[v] to be 1 or 2
            dfs(v);
        }
    }
}
void createGraph()
{
    cin>>n;
    for (int i = 1;i<=n;i++)adj[i].clear(),vis[i] = 0,col[i] = -1;
    vi t(n + 1);
    for (int i = 1;i<=n;i++)cin>>t[i];
    
    for (int i = 1;i<n;i++){
            if (t[i] != t[i + 1]){
            adj[i].pb(i + 1),adj[i + 1].pb(i);//because the graph is undirected
        }
    }

    if (t[1] != t[n]){
        adj[1].pb(n);
        adj[n].pb(1);
    }

    for (int i = 1;i<=n;i++){
        if (!vis[i]){
            col[i] = 1;//the colours are 1,2 or 3
            dfs(i);
        }
    }
    //output the # of colours
    int ans = 1;
    for (int i = 1;i<=n;i++)ans = max(ans,col[i]);//find the max colour # used
    cout<<ans<<'\n';
    for (int i = 1;i<=n;i++)cout<<col[i]<<" ";
    cout<<'\n';
}
int main()
{

    int t;
    cin>>t;
    while (t--){
        createGraph();
    }
    return 0;
}