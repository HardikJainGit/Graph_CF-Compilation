#include<bits/stdc++.h>
using namespace std;
#define pyes cout << "YES\n";
#define pno cout << "NO\n";
#define int long long
#define vi vector <int>
#define pb push_back
#define F first
#define S second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}
#define p(i) cout<<i<<" ";

bool cycle;
bool flag;

void dfs(int curr, vector<bool>& vis, vector<int> adj[], int par){
    vis[curr] = true;
    if(adj[curr].size() != 2){
        flag = false;
    }
    for(auto el:adj[curr]){
        if(vis[el]){
            if(el!=par){
                cycle = true;
            }
            continue;
        }
        dfs(el,vis,adj,curr);
    }
}

void isCyclicDFS(vector<int> adj[], vector<bool> &vis, int Node, int parent,bool &cycle) {
    vis[Node] = true;
    if(adj[Node].size() != 2){
        flag = false;
    }
    for(auto i : adj[Node]) {
        if(vis[i] == false) {
            isCyclicDFS(adj, vis, i, Node,cycle);
        } else if(i != parent) {
            cycle=1;
        }
    }
}


 
int32_t main() {

    int n,m;
    cin>>n>>m;
 
    vector<int> adj[n+1];

    f(i,0,m){
        int u,v;
        cin>>u>>v;
 
        adj[u].pb(v);
        adj[v].pb(u);
    }   
 
    int ans = 0;  
 
    vector<bool> vis(n+1);
 
    f(i,1,n+1){
        if(vis[i]){
            continue;
        }
        cycle = false;
        flag = true;
        isCyclicDFS(adj,vis,i,-1,cycle);
        if(cycle && flag){
            ans++;
        }
    }
 
    cout<<ans<<endl;

}

/* #include <bits/stdc++.h>
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
void setIO()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int n = 2e5 + 5,m;
vvi adj(n);
vb vis(n);
bool isCycle;
void dfs(int u)
{
    //if the # of adjacent nodes to u is exactly 2
    //adj[u].size() gives the # of adjacent nodes to u
    vis[u] = 1;
    if (adj[u].size() != 2){//dont return here but visit all nodes in this cc
        isCycle = false;
    }
    for (int v:adj[u]){
        if (!vis[v]){
            dfs(v);
        }
    }
}
int main()
{
    setIO();
    cin>>n>>m;
    while (m--){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }
    int ans = 0;
    for (int i = 1;i<=n;i++){
        if (!vis[i]){
            isCycle = true;
            dfs(i);
            if (isCycle)ans++;
        }
    }
    cout<<ans;
    return 0;
} */