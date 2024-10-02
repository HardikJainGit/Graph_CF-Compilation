// ▄████▄   ▒█████  ▓█████▄ ▓█████ 
// ▒██▀ ▀█  ▒██▒  ██▒▒██▀ ██▌▓█   ▀ 
// ▒▓█    ▄ ▒██░  ██▒░██   █▌▒███   
// ▒▓▓▄ ▄██▒▒██   ██░░▓█▄   ▌▒▓█  ▄ 
// ▒ ▓███▀ ░░ ████▓▒░░▒████▓ ░▒████▒

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
#define pr(x) cout<<x<<endl;

bool possible;
 
void dfs(int Node,int parent,int c,vector<int> adj[],vector<int>& color){

    color[Node]=c;

    for(auto it:adj[Node]){
        if(color[it] == -1){
            dfs(it,Node,1-c,adj,color); //complementary color for adj node
        }
        if(color[it]==color[Node]){ //odd cycles bipartite coloring fails
            possible=false;
        }
 
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    possible=1;
    vector<pair<int,int>> v;

    f(i,0,m) {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
        adj[a].pb(b);
        adj[b].pb(a);
 
    } 
    
    vector<int>color(n+1,-1);  
 
    dfs(1,0,0,adj,color);

    if(!possible){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;

    f(i,0,m) {
        cout << !(color[v[i].first] < color[v[i].second]);
    }
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
vi col(n,-1);//initialize to -1 so that a 0 value is not wrongly considered
vb vis(n);
bool dfs(int u)
{
    vis[u] = 1;
    for (int v:adj[u]){
        if (col[v] == col[u])return false;        
        else if (!vis[v]){
            col[v] = !col[u];
            if (!dfs(v))return false;
        }
    }
    return true;
}
int main()
{
    setIO();
    cin>>n>>m;
    
    vvi el;

    for (int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        el.pb({u,v});
    }
    col[1] = 0;
    if (!dfs(1)){
        cout<<"NO";
    }
    else{
        cout<<"YES"<<endl;
        string ans = "";
        for (int i = 0;i<m;i++){//iterating over all edges
            int u = el[i][0],v = el[i][1];
            if (col[u] == 0){//u is an outgoing node
                ans += "0";
            }
            else{
                ans += "1";
            }
        }
        cout<<ans;
    }
    return 0;
} */