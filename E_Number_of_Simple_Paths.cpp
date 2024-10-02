#include <bits/stdc++.h>
using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A> void __print(const A &x);
template <typename A, typename B> void __print(const pair<A, B> &p);
template <typename... A> void __print(const tuple<A...> &t);
template <typename T> void __print(stack<T> s);
template <typename T> void __print(queue<T> q);
template <typename T, typename... U> void __print(priority_queue<T, U...> q);
template <typename A> void __print(const A &x) {
    bool first = true;
    cerr << '{';
    for (const auto &i : x) {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B> void __print(const pair<A, B> &p) {
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A> void __print(const tuple<A...> &t) {
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T> void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T> void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U> void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail> void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T)) cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif

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
#define aint(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}
#define pr(x) cout<<x<<endl;

/* ∑v∈cycle cntv(cntv−1)2+cntv⋅(n−cntv) */

int n = 2e5 + 5;
vvi adj(n);
vi par(n);
vector<bool> vis(n);
vi cycle;
bool found;
vector<bool> isOnCycle(n);//whether or not u is a cycle node
vi subtree(n);

void dfs(int u,int p)
{

    par[u] = p;
    vis[u] = 1;
    for (int v:adj[u]){

        if (found)
        return;

        if (!vis[v]){
            dfs(v,u);
        }
    

        else if (v != p){ //this means cycle contains u and v as visited and not parent
            found = true;

            while (u != v){ //take in account all nodes for a cycle
                isOnCycle[u] = 1;
                cycle.pb(u);
                u = par[u];
       
            }

            isOnCycle[v] = 1; //pb for u==v
            cycle.pb(v);
            return;
        }
    }
    int re=1;
}

//finding the subtree sizes including the root
int dfs2(int u,int p)
{
    subtree[u] = 1; //assign the node itself val 1
    for (int v:adj[u])
        if (!isOnCycle[v] && v != p)subtree[u] += dfs2(v,u); //or dfs2(u,v) subtree[v]+=subtree[u]
    return subtree[u];
    
}

//isLeaf:
/* if(u!=1 && adj[u].sz==1){
    return true;
} 
return false;
*/

//dp code to find subtree sizes including root

/* void dfs(int u,,int p){

    base case:
    if(isLeaf(u)){
        subtree[u]=1;
        return;
    }
    for neigh:
    v!=p:
    dfs(u,v); 
    }

    for neigh:
    v!=p
    sub[u]+=sub[v];

    sub[u]++ as initially all are set to 0 so have to include that node also for non leaf nodes

} */


int32_t main()
{

    int t;
    cin>>t;
    while (t--){
        cin>>n;
        found = false;

        cycle.clear();
       f(i,1,n+1){
            adj[i].clear(),par[i] = -1,isOnCycle[i] = 0,vis[i] = 0,
            subtree[i] = 0;
        }

        f(i,1,n+1){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v),adj[v].pb(u);
        }

        dfs(1,-1);

        int ans =  n * ( n - 1); //complementary counting

        for (int u:cycle){
            dfs2(u,0);
            int val = subtree[u];
            ans -= ((val - 1) * (val))/2;//subtree size choose 2
        }

        cout<<ans<<endl;
    }
    return 0;
}