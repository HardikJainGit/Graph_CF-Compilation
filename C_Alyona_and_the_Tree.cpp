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
#define aint(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}

const int NUM = 3e5 + 7;
 
int rem = 0;
int parent[NUM], dist[NUM], vis[NUM];
vector<pair<int,int>> g[NUM];
 
void dfs(int node, int par)
{
    parent[node] = par;
    for (auto i : g[node])
    {
        if (i.first == par)
            continue;
         if(dist[node]+i.second>0) dist[i.first] = dist[node] + i.second; //distance from 1
        dfs(i.first, node);
    }
}
 
/* Only process positive distances so that v=1 is at highest risk of being sad and dist from it is max */

void dfs_after_dist_is_measured(int node)
{
    if (vis[node])
        return;
    vis[node] = 1;
    //cout<<node+1<<" ";
    rem++; //counts no of nodes to be removed -> removing a node removes all nodes in subtree
    for (auto i : g[node])
    {
        if (i.first == parent[node]) //for a node all nodes in its subtree are marked visited
            continue;
        dfs_after_dist_is_measured(i.first);
    }
}
 
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
   
    while (t--)
    {
    int n;
    cin >> n;
    inp(a,n);
    f(i, 0, n-1){
        int v;
        cin >> v;
        --v;
        int w;
        cin >> w;
        g[i+1].pb({v, w});
        g[v].pb({i+1, w});
    }
    dfs(0, -1);
    f(i, 0, n){
        //cout<<dist[i]<<" a ";
        //cout<<a[i]<<" "<<endl;
        if (dist[i] > a[i]) //dist[i] is the maximum value of dist(v,u) for u=i
            dfs_after_dist_is_measured(i); //remove the subtree with i as root
    }
    cout << rem << endl;
    }

}
