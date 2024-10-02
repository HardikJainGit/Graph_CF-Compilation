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

 
vector<bool> visited;
int ec,node_count,mxEd;
 
void dfs(int Node,vector<int> adj[],vector<bool>& visited){
    node_count++;
    visited[Node] = true;
    for(auto it:adj[Node]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
    }
}
 
int32_t main() {
 
    in(n);
    in(m);
    in(k);
 
    inpv(c,k);  
 
    vector<int> adj[n+1];

    f(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    visited.resize(n+1);
 
    mxEd = 0;
 
    int mxNodeCount = 0; //for govt groups
 
    for(int i=0;i<k;i++){
        node_count = 0;
        dfs(c[i],adj,visited);
        mxEd += node_count*(node_count - 1)/2;
        mxNodeCount = max(mxNodeCount,node_count);
    }
 
 
    int notVisited = 0;
    f(i,1,n+1){
        notVisited += (!visited[i]); //iterating over all nodes
    }
 
   
    mxEd += notVisited*mxNodeCount + notVisited*(notVisited-1)/2; //add the internal connections to main
 
    cout<<mxEd - m<<endl;
    return 0;
}