/* #include<bits/stdc++.h>
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
#define sz(x) ((int)(x).size())
#define vvvi vector<vvi>
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n = 3e5 + 5;
vector<vvi> adj(n);//we need to store the edge weights
int ans = 0;

void dfs(int node,int p,vector<int> &d) {
    debug(node);
    debug(d);
    
    for(auto i : adj[node]) {
        if(i[0]!=p) {
            debug(i[1]);
            debug(d[node]);
            d[i[0]]=d[node]+i[1];
            dfs(i[0],node,d);  

           // d[i[0]]=d[p]+i[1];
        } 
    }

}

int32_t main()
{
    cin>>n;
    int one_to_one=0;
    
    f(i,1,n){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        one_to_one+=2*w;
    }
    debug(one_to_one);

    vi d(n+1,0);
    d[1]=0;

    dfs(1,-1,d);
    debug(d);

    pr(one_to_one-maxv(d));




}
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n = 1e5 + 5;
vvvl adj(n);//3D - when storing weights of edges in a graph
vvl dp(n,vl(2));//dp[u][0] and dp[u][1]

bool is_leaf(int u)
{
    if (u != 1 && adj[u].size() == 1)return true;
    return false;
}

void dfs(int u,int p)
{
    if (is_leaf(u)){
        dp[u][0] = dp[u][1] = 0;
        return;
    }
    for (auto val:adj[u]){
        int v = val[0],w = val[1];
        if (v == p)continue;
        dfs(v,u);
    }
    for (auto val:adj[u]){
        int v = val[0],w = val[1];
        if (v == p)continue;
        dp[u][0] += dp[v][0] + 2 * w;
    }
    
    ll SUM = dp[u][0]; //ending at u starting at u (revpatrol)
    dp[u][1] = INT_MAX; //or sum as it is always bigger

    for (auto val:adj[u]){
        int v = val[0],w = val[1];
        if (v == p)continue;
        dp[u][1] = min(dp[u][1],SUM + dp[v][1] - dp[v][0] - w);
    }
}

int main()
{
    fast
    cin>>n;
    for (int i = 0;i<n - 1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w}),adj[v].pb({u,w});
    }
    dfs(1,-1);

    cout<<min(dp[1][0],dp[1][1]);//prove that the value of dp[1][1] < dp[1][0]
    return 0;
}