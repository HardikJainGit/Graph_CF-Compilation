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
#define all(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n = 1e5 + 5,k;//k is not used that much
vvi adj(n);
vi a(n);
vi subtreeXOR(n);
int x;//XOR SUM
bool isSubtree;//global variable
void dfs1(int u,int p)//computes subtree xors of all subtrees using Dynamic Programming
{
    subtreeXOR[u] = a[u];
    for (int v:adj[u]){
        if (v != p){
            dfs1(v,u);
            subtreeXOR[u] ^= subtreeXOR[v];
        }
    }
}

bool dfs2(int node,int p,bool isThereANC)
{
    if (isThereANC and subtreeXOR[node] == x)return true;//ancestor case

    if (subtreeXOR[node] == x and isSubtree)return true;
    //It checks in one subtree whether a node has val x and then in second cond it checks
    //whether the other subtree half of the root node has a val x so as to club them
    
    //disjoint subtree case
    if (subtreeXOR[node] == 0)isThereANC = 1;//update ONLY THE VARIABLE isAncestor
    for (int v:adj[node]){
        if (v != p){
            if (dfs2(v,node,isThereANC))
                return true;
        }
    }

    if (subtreeXOR[node] == x)
    isSubtree = 1;//update isSubtree ONLY over here 
    //(after calling dfs on all children)
    
    return false;
}

void solve()
{
    cin>>n>>k;
    for (int i = 1;i<=n;i++)adj[i].clear(),a[i] = 0,subtreeXOR[i] = 0;
    
    int xorSum = 0;
    isSubtree = 0;
 
    for (int i = 1;i<=n;i++){
        cin>>a[i];
        xorSum ^= a[i];
    }
 
    x = xorSum;
    
    for (int i = 1;i<=n - 1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }
 
    if (xorSum == 0){//if the XOR of all numbers is 0,
        //then we can just remove ANY 1 edge resulting in 2 components
        //with equal XOR
        cout<<"YES"<<'\n';
        return;
    }
 
    if (k == 2){//there is no way to remove only 1 edge 
        cout<<"NO"<<'\n';
        return;
    }
    
    //we need to find a way to remove 2 edges resulting in 3 components
    //each with the same XOR WHICH IS EQUAL TO xorSum
    //removing an edge (u,parent[u]) means creating 2 components: 
    //a component with subtree rooted at u,
    //and a 2nd component consisting of root's subtree excluding u's subtree
    //now to check whether there is a subtree in this new tree
    //with a XOR == xorSum, 
    //THEREFORE THERE ARE 2 WAYS THIS CAN HAPPEN:
 
    //Way 1: There is some ancestor of u with a subtree XOR == 0
    //Way 2: There is some other DISJOINT subtree with XOR == x
 
    dfs1(1,1);
    if (dfs2(1,1,0))cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}
int32_t main()
{
   // setIO();
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}