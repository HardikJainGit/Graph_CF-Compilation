#include<bits/stdc++.h>
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
vvi dp(n,vi(2));//dp[u][0] and dp[u][1]
vi w(n);
int ans = 0;

bool isLeaf(int u)
{
    if (u != 1 && adj[u].size() == 1)return true;
    return false;
}

void dfs(int u,int p)
{
    vi all;

    if (isLeaf(u)){//base cases
        dp[u][0] = w[u];
        dp[u][1]=0;
        ans = max(ans,max(dp[u][0],dp[u][1]));
        return;
    }

    for (auto val:adj[u]){
        int v = val[0];
        int wt = val[1];
        
        if (v == p)continue;

        dfs(v,u);

        all.pb(dp[v][0] - wt);//dp[v][0] - wt
    }
    
    sort(all.rbegin(),all.rend());//decreasing order

    int numChild = (int)all.size();

    if (numChild == 1)
        dp[u][0] = max(w[u],w[u] + all[0]);//dp[u][1] does not make sense
    //because we need at least 2 children for dp[u][1]
    
    else{
        dp[u][0] = max(w[u],w[u] + all[0]); //w[u] for standing at node itself

        dp[u][1] = (w[u] + all[0] + all[1]);
    }

    ans = max(ans,max(dp[u][0],dp[u][1]));
}
int32_t main()
{
    cin>>n;
    f(i,1,n+1)cin>>w[i];

    if (n == 1){cout<<w[1];return 0;}
    
    f(i,1,n){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    dfs(1,-1);

    cout<<ans;
    return 0;
}