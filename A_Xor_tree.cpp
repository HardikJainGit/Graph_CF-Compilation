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
    __print(p.sscond);
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
    reverss(debugVector.begin(), debugVector.end());
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

#define py cout << "YES\n";
#define pn cout << "NO\n";
#define int long long
#define vi vector <int>
#define vvi vector<vector<int>>
#define pb push_back
#define ff first
#define ss second
#define rev(v) reverss(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define maxv(v) *max_element(v.begin(), v.end())
#define aint(v) v.begin(),v.end()
#define in(x) int x; cin>>x;
#define f(i,a,b) for(int i=a;i<b;i++)
#define inp(a,n) int a[n]; f(i,0,n) cin>>a[i];
#define inpv(a,n) vector <int> a; f(i,0,n) {int x; cin>>x; a.pb(x);}
#define pr(x) cout<<x<<endl;
#define sz(x) ((int)(x).size())
#define yoyo ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 1e5+10;

vi g[N];
bool vis[N];
vector<pair<int,int>> v;
vi ans;

/* void dfs2(int Node,int z,int odd,int even){

    //Top Down

    vis[Node] = true;
    z++;

    if(z%2==1 && odd>0) //odd=0 implies even odds
    {
        v[Node].ff=1 - v[Node].ff;
    }

    else if(z%2==0 && even>0) 
    {
        v[Node].ff=1-v[Node].ff;
    }

    if(v[Node].ff!=v[Node].ss){ //perform operation
            ans.pb(Node);
            if(z%2==1) odd=1-odd;
            else even=1-even;
    }

    //run dfs from Node
    for(auto it : g[Node]){
        if(vis[it]) continue;
        dfs2(it,z,odd,even);
    }

    return;
} */

void dfs(int Node,int level,int odd,int even){

    //Top Down

    vis[Node] = true;
    level++;

    if(level%2==1) 
    {
        v[Node].ff=(v[Node].ff+odd)%2;
    }

    else if(level%2==0) 
    {
        v[Node].ff=(v[Node].ff+even)%2;
    }

    if(v[Node].ff!=v[Node].ss){ //perform operation
            ans.pb(Node);
            if(level%2==1) odd++;
            else even++;
    }

    //run dfs from Node
    for(auto it : g[Node]){
        if(vis[it]) 
        continue;
        dfs(it,level,odd,even);
    }

    return;
}
 
int32_t main() {
    yoyo

    in(n);

    f(i,0,n-1){
        in(x);in(y);
        g[x].pb(y);
        g[y].pb(x);
    }

    v.pb({-1,-1});

    f(i,0,n){
        int x;
        cin>>x;
        v.pb({x,0});
    }

    f(i,1,n+1){
        int x;
        cin>>x;
        v[i].ss=x;
    }

    dfs(1,0,0,0);

    pr(ans.size());

    for(auto it:ans)
    pr(it);

    }
