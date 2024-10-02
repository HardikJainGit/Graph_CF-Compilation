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
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}


vector<vector<int>> g(300005);
vector<int> dp(300005);
int child[300005];

//dp[i] is the vertices saved if ith node is infected
 
void dfs(int Node, int parent)
{
    child[Node]=1; //node itself
    dp[Node]=0;
    int s=0;
    for (auto it : g[Node]) 
    if (it!=parent)
    {
        dfs(it,Node);
        s+=dp[it]; //s=dp[c1]+dp[c2]
        child[Node]+=child[it]; //get the total no of children for a node including itself
    }

    for (auto it : g[Node]) if (it!=parent)
    {
        dp[Node]=max(dp[Node],s-dp[it]+child[it]-1); //we need children of other and dp of other
    }
   
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
 
    int t; cin>>t;
    while (t--)
    {
        int n; 
        cin>>n;
        f(i,1,n+1) 
        g[i].clear();
        f(i,1,n)
        {
            int u,v; 
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
 
        dfs(1,-1);
        cout<<dp[1]<<endl;
    
    }
}