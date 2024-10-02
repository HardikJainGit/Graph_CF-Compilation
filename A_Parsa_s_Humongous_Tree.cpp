#include<bits/stdc++.h>
using namespace std;

#define pyes cout << "YES\n";
#define pno cout << "NO\n";
#define int long long
#define vi vector <int>
#define vvi vector<vector<int>>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())
#define vvvi vector<vvi>
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int n = 1e5 + 5;
vvi adj(n);
vi l(n),r(n);
vvi dp(n,vi(2));

bool isLeaf(int u){
    return(u!=1 && sz(adj[u])==1);
}

void dfs(int u,int p)
{
/*     if(isLeaf(u)){
        dp[u][0]=0;
        dp[u][1]=0;
    } */

    for (int v:adj[u]){
        if (v == p)continue;
        dfs(v,u);
    }
 
    for (int v:adj[u]){
        if (v == p)continue;
        dp[u][0] += max(abs(l[u] - l[v]) + dp[v][0],
            abs(l[u] - r[v]) + dp[v][1]);
        
        dp[u][1] += max(abs(r[u] - l[v]) + dp[v][0],
            abs(r[u] - r[v]) + dp[v][1]);
    }
}
int32_t main()
{
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        
        for (int i = 1;i<=n;i++)adj[i].clear(), dp[i][0]=0,dp[i][1]=0;
 
        for (int i = 1;i<=n;i++)cin>>l[i]>>r[i];
 
        for (int i = 1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v),adj[v].pb(u);
        }
 
        dfs(1,-1);
        
        cout<<max(dp[1][0],dp[1][1])<<'\n';
    }
    return 0;
}