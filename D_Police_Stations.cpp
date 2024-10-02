#include<bits/stdc++.h>
using namespace std;
#define pyes cout << "YES\n";
#define pno cout << "NO\n";
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
 

queue<pair<int, int>> q;
vector<pair<int, int>> adj[300005];
int v[300005];
int res[300005];

int main(){
    int n, k, d;
    cin>>n>>k>>d;
    d=0; //immaterial
    f(i,0,k){
        int p;
        cin>>p;
        q.push({p, -1}); /* multi source BFS */
        //if(i!=0) q.pop();
    }
    f(i,0,n-1){
        int u, v;
        cin>>u>>v;
        adj[u].push_back({v, i+1});
        adj[v].push_back({u, i+1});
    }

    while(!q.empty()) {

    int node = q.front().first;
    int pseudo_parent = q.front().second;
    //cout<<endl<<node<<" "<<pseudo_parent<<" "<<endl;
    q.pop();

    if(v[node]) continue; //We don't process visited as it would lead to removal of all roads

    v[node] = 1;

    for(auto i : adj[node]) {
        if(i.first != pseudo_parent){
        if(!v[i.first]) {
            //cout<<" It sucks "<<i.first<<" ";
            q.push({i.first,node});
        } 
        else{
            //cout<<i.first<<endl;
            res[i.second]=1;
        }
      }
    }
}

    cout<<k-1<<endl;

    f(i,1,n)
    if(res[i]){
        cout<<i<<" ";
    }

}


/* #include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const ll mod = 1e9 + 7,inf = 1e18;
#define UNVISITED -1
#define IMPORTANT 1
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
int main()
{
    setIO();
    int n,k,d;
    cin>>n>>k>>d;
    vvvi adj(n + 1);//because we need to store the indices of each edge
    vi dist(n + 1,1e9);
    vb vis(n + 1,false);
    vi colour(n,UNVISITED);
    queue<int>q;

    for (int i = 1;i<=k;i++){
        int ps;
        cin>>ps;
        q.push(ps);
        vis[ps] = 1;
        dist[ps] = 0;
    }
    for (int i = 1;i<=n - 1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto val:adj[u]){
            int v = val[0],index = val[1];
            if (!vis[v]){
                vis[v] = 1;
                colour[index] = IMPORTANT;
                q.push(v);
            }
        }
    }
    vi ans;
    for (int i = 1;i<=n - 1;i++)
        if (colour[i] == UNVISITED)ans.pb(i);
    cout<<ans.size()<<'\n';
    for (int edge:ans)cout<<edge<<" ";
    return 0;
} */

/* #include <bits/stdc++.h>
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
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}
#define pr(x) cout<<x<<endl;
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

queue <int> q;
vector<pair<int, int>> adj[300005];
int v[300005];
vi res(300005,0);
int32_t main(){
    int n, k, d;
    cin>>n>>k>>d;
    d=0; //immaterial
    f(i,0,k){
        int p;
        cin>>p;
        q.push(p);
        v[p]=1; // multi source BFS 
        
    }
    f(i,0,n-1){
        int u, v;
        cin>>u>>v;
        adj[u].push_back({v, i+1});
        adj[v].push_back({u, i+1});
    }

    while(!q.empty()) {

    int node = q.front();
    q.pop();

    for(auto i : adj[node]) {
        if(!v[i.first]) {
            debug(i.ff);
            debug(node);
            q.push({i.first});
            v[i.ff] = 1;
            res[i.second]=1;
        }  
      }
    
}

    cout<<k-1<<endl;
    //or !res.sz()

    f(i,1,n)
    if(!res[i]){
        cout<<i<<" ";
    }

}
 */